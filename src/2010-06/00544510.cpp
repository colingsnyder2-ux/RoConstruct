// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/RenderScene.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/RenderScene.h"

namespace RBX {
namespace Render {

// FUNCTION: WEBSERVICE 0x101ef3f0
static float detailLevel(float x, float lo, float hi)
{
	return G3D::clamp(1.0f - (x - lo) / (hi - lo), 0.0f, 1.0f);
}

// FUNCTION: WEBSERVICE 0x101ef6c0
void RenderScene::turnOnLights(G3D::RenderDevice* rd, bool allLights) const
{
	rd->enableLighting();

	for (int i = 0; i < lighting->lightArray.size(); i++) {
		rd->setLight(i, lighting->lightArray[i]);
	}

	if (allLights) {
		for (int i = 0; i < lighting->shadowedLightArray.size(); i++) {
			rd->setLight(lighting->lightArray.size() + i, lighting->shadowedLightArray[i]);
		}
	}

	G3D::Color3 average = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
	rd->setAmbientLightColor(average);

	int i = lighting->shadowedLightArray.size() * 2;
	G3D::Vector3 direction(-0.4f, -1.0f, 0.1f);

	if (lighting->shadowedLightArray.size() > 0) {
		direction = -lighting->shadowedLightArray[0].position.xyz();
	}

	if (effectSettings.hemisphereLighting()) {
		if (lighting->ambientBottom != average) {
			rd->setLight(i, G3D::GLight::directional(direction, lighting->ambientBottom - average, false));
			i++;
		}

		if (lighting->ambientTop != average) {
			rd->setLight(i + 1, G3D::GLight::directional(G3D::Vector3::unitY(), lighting->ambientTop - average, false));
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ef990
void RenderScene::sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const
{
	for (int i = diffuseProxyArray.size() - 1; i >= 0; i--) {
		RenderSurface* proxy = diffuseProxyArray[i];

		rd->setObjectToWorldMatrix(proxy->cframe);
		rd->setPolygonOffset(proxy->polygonOffset);
		proxy->material->configureRenderDevice(rd);
		Mesh::sendGeometry(proxy->mesh, rd);
	}
}

// FUNCTION: WEBSERVICE 0x101efa00
void RenderScene::transparentPass(G3D::RenderDevice* rd)
{
	rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
	rd->setBlendFunc(G3D::RenderDevice::BLEND_SRC_ALPHA, G3D::RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
	rd->setDepthWrite(false);

	for (int i = 0; i < transparentProxyArray.size(); i++) {
		RenderSurface* p = transparentProxyArray[i];
		const Material::Level* material = p->material;

		rd->setObjectToWorldMatrix(p->cframe);
		rd->setPolygonOffset(p->polygonOffset);
		p->material->configureRenderDevice(rd);
		rd->setColor(G3D::Color4(material->color(), 1.0f - material->transparent()));
		Mesh::sendGeometry(p->mesh, rd);
	}
}

// FUNCTION: WEBSERVICE 0x101eff30
void RenderScene::renderShadowVolumeGeometry(
	G3D::RenderDevice* rd,
	const G3D::GLight& light,
	bool caps,
	float shadowVertexDistance
)
{
	rd->beginIndexedPrimitives();
	rd->setVertexArray(shadowVAR);
	rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray);
	rd->endIndexedPrimitives();

	for (int i = 0; i < shadowCachingChunkArray.size(); i++) {
		shadowCachingChunkArray[i]->renderShadows(rd, light, caps, shadowVertexDistance);
	}
}

// FUNCTION: WEBSERVICE 0x101effc0
void RenderScene::reflectionPass(G3D::RenderDevice* rd)
{
	if (G3D::GLCaps::supports_GL_EXT_texture_cube_map() && !lighting->environmentMap.isNull() &&
		(lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP ||
		 lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP_NPOT)) {
		rd->pushState();
		rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
		rd->setPolygonOffset(-0.2);
		rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE);
		rd->disableLighting();
		rd->configureReflectionMap(1, lighting->environmentMap);
		rd->setDepthWrite(false);

		for (int i = 0; i < reflectProxyArray.size(); i++) {
			RenderSurface* p = reflectProxyArray[i];
			const Material::Level* material = p->material;

			rd->setPolygonOffset(p->polygonOffset);
			rd->setObjectToWorldMatrix(p->cframe);
			rd->setTexture(0, material->matte(rd));
			rd->setColor(material->reflect() * G3D::Color3::white());
			Mesh::sendGeometry(p->mesh, rd);
		}

		rd->popState();
	}
}

// FUNCTION: WEBSERVICE 0x101f01b0
void RenderScene::setThrottle(float t, float m, bool s, float c)
{
	t = G3D::clamp(t, 0.0f, 100.0f);

	if (t != shadingQuality || m != meshDetail || s != shadows || c != cameraDistance) {
		shadingQuality = t;
		meshDetail = m;
		cameraDistance = c;
		shadows = s;

		lighting = effectSettings.update(
			shadingQuality,
			meshDetail,
			shadows,
			cameraDistance,
			desiredLighting,
			desiredSkyParameters,
			skyParameters
		);
	}
}

// FUNCTION: WEBSERVICE 0x101f0320
void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
{
	desiredLighting = L;
	lighting = effectSettings.update(
		shadingQuality,
		meshDetail,
		shadows,
		cameraDistance,
		desiredLighting,
		desiredSkyParameters,
		skyParameters
	);
}

// FUNCTION: WEBSERVICE 0x101f06a0
void RenderScene::computeShadowVolumeGeometry(
	G3D::Array<unsigned int>& indexArray,
	G3D::Array<G3D::Vector3>& shadowVertex,
	const G3D::GLight& light,
	bool generateLightCap,
	float shadowVertexDistance
) const
{
	renderStats.cpuShadow.tick();

	shadowVertex.resize(0, false);
	indexArray.resize(0, false);

	shadowVertex.append(-light.position.xyz().direction() * shadowVertexDistance);

	G3D::Vector3 worldLight = light.position.xyz().direction();

	for (int i = 0; i < shadowProxyArray.size(); i++) {
		const RenderSurface& proxy = shadowProxyArray[i];

		proxy.fullMesh
			->computeDirectionalShadowVolume(proxy.cframe, worldLight, indexArray, shadowVertex, generateLightCap);
	}

	renderStats.cpuShadow.tock();
}

// FUNCTION: WEBSERVICE 0x101f07a0
void RenderScene::updateShadowVAR(const G3D::Array<G3D::Vector3>& shadowVertex)
{
	size_t size = shadowVertex.size() * sizeof(G3D::Vector3) + 16;

	if (shadowVARArea.isNull() || shadowVARArea->totalSize() < size) {
		shadowVARArea = G3D::VARArea::create(size);
	}
	else {
		shadowVARArea->reset();
	}

	shadowVAR = G3D::VAR(shadowVertex, shadowVARArea);
}

// FUNCTION: WEBSERVICE 0x101f0900
void RenderScene::classifyProxies()
{
	for (int i = 0; i < proxyArray.size(); i++) {
		RenderSurface* ptr = &proxyArray[i];

		if (ptr->material != NULL) {
			if (ptr->material->transparent() > 0) {
				transparentProxyArray.append(ptr);
			}
			else {
				diffuseProxyArray.append(ptr);

				if (ptr->material->reflect() > 0) {
					reflectProxyArray.append(ptr);
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x101f0ff0
RenderScene::~RenderScene()
{
}

// FUNCTION: WEBSERVICE 0x101f1200
void RenderScene::presetLighting(
	G3D::ReferenceCountedPointer<G3D::Sky> sky,
	G3D::LightingParameters skyParameters,
	G3D::Color3 ambientTop,
	G3D::Color3 ambientBottom
)
{
	this->sky = sky;
	desiredSkyParameters = skyParameters;

	G3D::LightingRef lighting = G3D::Lighting::create();
	lighting->ambientTop = ambientTop;
	lighting->ambientBottom = ambientBottom;

	G3D::GLight light = G3D::GLight::directional(skyParameters.lightDirection, skyParameters.lightColor * 0.9);
	lighting->shadowedLightArray.append(light);

	if (!sky.isNull()) {
		lighting->environmentMap = sky->getEnvironmentMap();
	}

	setLighting(lighting);
}

// FUNCTION: WEBSERVICE 0x101f1680
void RenderScene::markStencilShadows(G3D::RenderDevice* rd, const G3D::GCamera& camera, const G3D::GLight& light)
{
	static G3D::Array<G3D::Vector3> shadowVertex;

	float shadowVertexDistance = G3D::min(10000.0f, -camera.getFarPlaneZ() * 0.2f);

	shadowIndexArray.resize(0, false);
	computeShadowVolumeGeometry(shadowIndexArray, shadowVertex, light, true, shadowVertexDistance);
	updateShadowVAR(shadowVertex);

	rd->pushState();
	rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

	if (debugShadowVolumes) {
		rd->setColor(G3D::Color3::white() * 0.25f);
		rd->setCullFace(G3D::RenderDevice::CULL_NONE);
		rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE);
		rd->setDepthWrite(false);
	}
	else {

		rd->setDepthWrite(false);
		rd->setColorWrite(false);
		rd->setDepthTest(G3D::RenderDevice::DEPTH_LESS);
		rd->setPolygonOffset(0.2);

		if (G3D::GLCaps::supports_two_sided_stencil()) {
			rd->setCullFace(G3D::RenderDevice::CULL_NONE);
			rd->setStencilOp(
				G3D::RenderDevice::STENCIL_KEEP,
				G3D::RenderDevice::STENCIL_DECR_WRAP,
				G3D::RenderDevice::STENCIL_KEEP,
				G3D::RenderDevice::STENCIL_KEEP,
				G3D::RenderDevice::STENCIL_INCR_WRAP,
				G3D::RenderDevice::STENCIL_KEEP
			);
		}
		else {
			rd->setCullFace(G3D::RenderDevice::CULL_BACK);
			rd->setStencilOp(
				G3D::RenderDevice::STENCIL_KEEP,
				G3D::RenderDevice::STENCIL_DECR_WRAP,
				G3D::RenderDevice::STENCIL_KEEP
			);
		}

		rd->disableLighting();
	}

	rd->setShadeMode(G3D::RenderDevice::SHADE_FLAT);
	rd->setObjectToWorldMatrix(G3D::CoordinateFrame());
	renderShadowVolumeGeometry(rd, light, true, shadowVertexDistance);

	if (!G3D::GLCaps::supports_two_sided_stencil() && !debugShadowVolumes) {
		rd->setCullFace(G3D::RenderDevice::CULL_FRONT);
		rd->setStencilOp(
			G3D::RenderDevice::STENCIL_KEEP,
			G3D::RenderDevice::STENCIL_INCR_WRAP,
			G3D::RenderDevice::STENCIL_KEEP
		);
		renderShadowVolumeGeometry(rd, light, true, shadowVertexDistance);
		rd->setCullFace(G3D::RenderDevice::CULL_BACK);
		rd->setStencilOp(
			G3D::RenderDevice::STENCIL_KEEP,
			G3D::RenderDevice::STENCIL_DECR_WRAP,
			G3D::RenderDevice::STENCIL_KEEP
		);
	}

	rd->popState();
}

// STUB: WEBSERVICE 0x101f1960
void RenderScene::allocateProxies(G3D::RenderDevice* rd, const G3D::GCamera& camera)
{
	G3D::CoordinateFrame cameraCFrame;
	camera.getCoordinateFrame(cameraCFrame);

	float farZ = G3D::max(effectSettings.farCullZ(), camera.getFarPlaneZ());
	float nearZ = camera.getNearPlaneZ();
	for (int p = 0; p < chunkArray.size(); p++) {
		Chunk* chunk = chunkArray[p].getPointer();

		if (chunk == NULL) {
			continue;
		}

		bool hasMesh = chunk->getMesh().notNull();
		bool hasMaterial = chunk->getMaterial().notNull();

		if (!hasMesh || !hasMaterial) {
			continue;
		}

		const G3D::CoordinateFrame& cframe = chunk->cframe();
		G3D::Vector3 cspace = cameraCFrame.pointToObjectSpace(cframe.translation);

		bool farCulled = cspace.z + chunk->radius < farZ && chunk->cullable();
		bool nearCulled = cspace.z - chunk->radius > nearZ;
		bool shadowFarCulled = cspace.z + chunk->radius < farZ * 1.2f && chunk->cullable();

		if (chunk->castsShadows() && !shadowFarCulled && !chunk->getMaterial()->veryTransparent()) {
			if (chunk->cachesShadows()) {
				shadowCachingChunkArray.append(chunkArray[p]);
			}
			else {
				shadowProxyArray.resize(shadowProxyArray.size() + 1, false);

				RenderSurface& shadowProxy = shadowProxyArray.last();
				shadowProxy.material = NULL;
				shadowProxy.cframe = cframe;
				shadowProxy.mesh = chunk->getMesh()->dropShadowMesh().getPointer();
				shadowProxy.fullMesh = chunk->getMesh();
			}
		}

		if (!farCulled && !nearCulled) {
			RenderSurface proxy;
			proxy.cframe = cframe;
			proxy.polygonOffset = chunk->polygonOffset;
			proxy.z = cspace.z - chunk->polygonOffset;
			proxy.fullMesh = chunk->getMesh();

			float rawLvl = detailLevel(fabs(proxy.z), -nearZ, -farZ) + effectSettings.LODShift();
			float lvl = G3D::clamp(rawLvl, 0.0f, 1.0f);

			proxy.material = chunk->getMaterial()->detailLevel(rawLvl);

			if (proxy.material != NULL) {
				proxy.material->baseTexture(rd);
				proxy.mesh = chunk->getMesh()->detailLevel(lvl).getPointer();
				proxyArray.append(proxy);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x101f1fd0
void RenderScene::computeProxyArrays(G3D::RenderDevice* rd, const G3D::GCamera& camera)
{
	renderStats.computeProxyArrays.tick();

	clearProxyArrays();
	allocateProxies(rd, camera);
	classifyProxies();
	sortProxies();

	renderStats.computeProxyArrays.tock();

	renderStats.diffuseProxyCount = diffuseProxyArray.size();
}

// FUNCTION: WEBSERVICE 0x101f2450
RenderScene::RenderScene()
	: shadingQuality(-1.0f), meshDetail(-1.0f), shadows(false), cameraDistance((float) G3D::inf()),
	  debugShadowVolumes(false), colorClearValue(0.5f, 0.5f, 1.0f, 1.0f)
{
	desiredLighting = lighting = G3D::Lighting::create();
}

} // namespace Render
} // namespace RBX
