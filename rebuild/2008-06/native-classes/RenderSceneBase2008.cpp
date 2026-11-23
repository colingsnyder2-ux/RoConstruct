// 2008-06 native RBX::RenderBase::RenderSceneBase and RBX::Render::RenderScene (inactive). One optimized unit
// (document-swap flags, /O2, /fp:fast), as in the original: the RenderSceneBase ctor 00504fd0 sits between the
// Render::RenderScene bodies and is called out of line by both scene constructors; the base dtor is header-inline and
// its out-of-line copy 005039d0 is emitted for the constructors' EH unwind.
//   RenderSceneBase: ctor 00504fd0, dtor 005039d0, ??_G 00503a30, presetLighting default 005039e0.
//   Render::RenderScene: ctor 00505040, dtor 00503a60, ??_G 00503fc0, setThrottle 00502d30, setLighting 00502e70,
//   presetLighting 00503cc0, the RenderSurface sort procs 005051e0 / 00505220 / 00505240 and sortBy* 00505860 /
//   00505890 / 005058c0 with their std::sort helpers. render 00504bf0 / computeProxyArrays 00504b60: RenderSceneRecovery_00504b60.cpp.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "RenderLib/RenderSceneRender2008.h"
#include <exception>
#include <GLG3D/GLCaps.h>

namespace RBX
{
	namespace RenderBase
	{
		RenderSceneBase::RenderSceneBase()
			: colorClearValue(0.5f, 0.5f, 1.0f, 1.0f),
			  shadingQuality(-1.0f),
			  meshDetail(-1.0f)
		{
		}

		void RenderSceneBase::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                     G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			throw std::exception("shouldn't be here");
		}
	}

	namespace Render
	{
		bool materialDepthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->material < B->material || (A->material == B->material && A->z > B->z);
		}

		bool materialPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->material < B->material;
		}

		bool depthPtrSortProc(RenderSurface* const& A, RenderSurface* const& B)
		{
			return A->z < B->z;
		}

		void sortByMaterialAndDepth(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &materialDepthPtrSortProc);
		}

		void sortByMaterial(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &materialPtrSortProc);
		}

		void sortByDepth(G3D::Array<RenderSurface*>& array)
		{
			std::sort(array.begin(), array.end(), &depthPtrSortProc);
		}

		// 00502370 (thiscall, ret 4): Mesh::sendGeometry is the static 00548fe0; Level::configureRenderDevice is slot 11.
		void RenderScene::sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const
		{
			for (int i = diffuseProxyArray.size() - 1; i >= 0; i--)
			{
				RenderSurface* proxy = diffuseProxyArray[i];

				rd->setObjectToWorldMatrix(proxy->cframe);
				rd->setPolygonOffset(proxy->polygonOffset);
				proxy->material->configureRenderDevice(rd);
				RenderBase::Mesh::sendGeometry(proxy->mesh, rd);
			}
		}

		// 005023e0 (thiscall, ret 4): transparent() slot 10 is read before color() slot 6 (Color4 argument order).
		void RenderScene::transparentPass(G3D::RenderDevice* rd)
		{
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
			rd->setBlendFunc(G3D::RenderDevice::BLEND_SRC_ALPHA, G3D::RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
			rd->setDepthWrite(false);

			for (int p = 0; p < transparentProxyArray.size(); p++)
			{
				RenderSurface* proxy = transparentProxyArray[p];
				const RenderBase::MaterialBase::Level* material = proxy->material;

				rd->setObjectToWorldMatrix(proxy->cframe);
				rd->setPolygonOffset(proxy->polygonOffset);
				proxy->material->configureRenderDevice(rd);
				rd->setColor(G3D::Color4(material->color(), 1.0f - material->transparent()));
				RenderBase::Mesh::sendGeometry(proxy->mesh, rd);
			}
		}

		// 00502b90 (thiscall, ret 4): GLCaps cube-map flag 0096ee86, environmentMap at Lighting +0x30, dimension
		// (Texture +0x58) DIM_CUBE_MAP 5 / DIM_CUBE_MAP_NPOT 7.
		void RenderScene::reflectionPass(G3D::RenderDevice* rd)
		{
			if (G3D::GLCaps::supports_GL_EXT_texture_cube_map() && !lighting->environmentMap.isNull() &&
			    (lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP ||
			     lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP_NPOT))
			{
				rd->pushState();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
				rd->setPolygonOffset(-0.2);
				rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE);
				rd->disableLighting();
				rd->configureReflectionMap(1, lighting->environmentMap);
				rd->setDepthWrite(false);

				for (int p = 0; p < reflectProxyArray.size(); p++)
				{
					RenderSurface* proxy = reflectProxyArray[p];
					const RenderBase::MaterialBase::Level* material = proxy->material;

					rd->setPolygonOffset(proxy->polygonOffset);
					rd->setObjectToWorldMatrix(proxy->cframe);
					rd->setTexture(0, material->matte(rd));
					rd->setColor(G3D::Color3::white() * material->reflect());
					RenderBase::Mesh::sendGeometry(proxy->mesh, rd);
				}

				rd->popState();
			}
		}

		// 00503540 (thiscall): called by computeProxyArrays 00504b60.
		void RenderScene::classifyProxies()
		{
			for (int i = 0; i < proxyArray.size(); i++)
			{
				RenderSurface* ptr = &proxyArray[i];

				if (ptr->material != NULL)
				{
					if (ptr->material->transparent() > 0)
					{
						transparentProxyArray.append(ptr);
					}
					else
					{
						diffuseProxyArray.append(ptr);

						if (ptr->material->reflect() > 0)
						{
							reflectProxyArray.append(ptr);
						}
					}
				}
			}
		}

#ifdef RENDERSCENE_HEADER_DECLARES_SHADOW_VOLUME
		// Guarded: RenderLib/RenderSceneRender2008.h does not yet declare the three private shadow helpers (header proposal).
		// Batch 47 scratch compile with those three declarations, shadowIndexArray as G3D::Array<int> (the index type of
		// Mesh::computeDirectionalShadowVolume 00549050 and AggregateChunk's sendIndices<int> 005029c0) and an inline
		// RenderSurface() : material(NULL), polygonOffset(0), mesh(NULL) {} ctor: renderShadowVolumeGeometry 00502b00,
		// updateShadowVAR 005033e0 and markStencilShadows 00503fe0 IDENTICAL (relocations masked); computeShadowVolumeGeometry
		// 306 B vs 308 B (x87 operand order of the first direction() x component).
		// Shapes from the openrbx 2007 analog RenderLib/RenderScene.cpp; 2008 call sites in markStencilShadows 00503fe0
		// (00504095 computeShadowVolumeGeometry, 005040a1 updateShadowVAR, 00504221 / 0050425a renderShadowVolumeGeometry).

		// 00502b00 (thiscall, ret 0x10): begin/setVertexArray/sendIndices/endIndexedPrimitives, then Chunk slot 2.
		void RenderScene::renderShadowVolumeGeometry(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps,
		                                             float shadowVertexDistance)
		{
			rd->beginIndexedPrimitives();
			rd->setVertexArray(shadowVAR);
			rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray);
			rd->endIndexedPrimitives();

			for (int i = 0; i < shadowCachingChunkArray.size(); i++)
			{
				shadowCachingChunkArray[i]->renderShadows(rd, light, caps, shadowVertexDistance);
			}
		}

		// 005032a0 (thiscall, ret 0x14): renderStats.cpuShadow (+0x190) tick/tock, Mesh::computeDirectionalShadowVolume 00549050.
		void RenderScene::computeShadowVolumeGeometry(G3D::Array<int>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex,
		                                              const G3D::GLight& light, bool generateLightCap,
		                                              float shadowVertexDistance) const
		{
			renderStats.cpuShadow.tick();

			shadowVertex.resize(0, false);
			indexArray.resize(0, false);

			shadowVertex.append(-light.position.xyz().direction() * shadowVertexDistance);

			G3D::Vector3 worldLight = light.position.xyz().direction();

			for (int i = 0; i < shadowProxyArray.size(); i++)
			{
				const RenderSurface& proxy = shadowProxyArray[i];
				proxy.fullMesh->computeDirectionalShadowVolume(proxy.cframe, worldLight, indexArray, shadowVertex,
				                                               generateLightCap);
			}

			renderStats.cpuShadow.tock();
		}

		// 005033e0 (thiscall, ret 4): VARArea::create 00475ec0 / reset, VAR(Array<Vector3>, area) 00502910.
		void RenderScene::updateShadowVAR(const G3D::Array<G3D::Vector3>& shadowVertex)
		{
			size_t size = shadowVertex.size() * sizeof(G3D::Vector3) + 16;

			if (shadowVARArea.isNull() || shadowVARArea->totalSize() < size)
			{
				shadowVARArea = G3D::VARArea::create(size);
			}
			else
			{
				shadowVARArea->reset();
			}

			shadowVAR = G3D::VAR(shadowVertex, shadowVARArea);
		}

		// 00503fe0 (thiscall, ret 0xc): function-local static shadowVertex (atexit 006a17af), two-sided stencil flag.
		void RenderScene::markStencilShadows(G3D::RenderDevice* rd, const G3D::GCamera& camera, const G3D::GLight& light)
		{
			static G3D::Array<G3D::Vector3> shadowVertex;

			float shadowVertexDistance = G3D::min(10000.0f, -camera.getFarPlaneZ() * 0.2f);

			shadowIndexArray.resize(0, false);
			computeShadowVolumeGeometry(shadowIndexArray, shadowVertex, light, true, shadowVertexDistance);
			updateShadowVAR(shadowVertex);

			rd->pushState();
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

			if (debugShadowVolumes)
			{
				rd->setColor(G3D::Color3::white() * 0.25f);
				rd->setCullFace(G3D::RenderDevice::CULL_NONE);
				rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE);
				rd->setDepthWrite(false);
			}
			else
			{
				rd->setDepthWrite(false);
				rd->setColorWrite(false);
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LESS);
				rd->setPolygonOffset(0.2);

				if (G3D::GLCaps::supports_two_sided_stencil())
				{
					rd->setCullFace(G3D::RenderDevice::CULL_NONE);
					rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP,
					                 G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_KEEP,
					                 G3D::RenderDevice::STENCIL_INCR_WRAP, G3D::RenderDevice::STENCIL_KEEP);
				}
				else
				{
					rd->setCullFace(G3D::RenderDevice::CULL_BACK);
					rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP,
					                 G3D::RenderDevice::STENCIL_KEEP);
				}

				rd->disableLighting();
			}

			rd->setShadeMode(G3D::RenderDevice::SHADE_FLAT);
			rd->setObjectToWorldMatrix(G3D::CoordinateFrame());
			renderShadowVolumeGeometry(rd, light, true, shadowVertexDistance);

			if (!G3D::GLCaps::supports_two_sided_stencil() && !debugShadowVolumes)
			{
				rd->setCullFace(G3D::RenderDevice::CULL_FRONT);
				rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_INCR_WRAP,
				                 G3D::RenderDevice::STENCIL_KEEP);
				renderShadowVolumeGeometry(rd, light, true, shadowVertexDistance);
				rd->setCullFace(G3D::RenderDevice::CULL_BACK);
				rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP,
				                 G3D::RenderDevice::STENCIL_KEEP);
			}

			rd->popState();
		}
#endif

		RenderScene::RenderScene()
			: shadows(false),
			  cameraDistance(G3D::inf()),
			  debugShadowVolumes(false)
		{
			desiredLighting = lighting = G3D::Lighting::create();
		}

		RenderScene::~RenderScene()
		{
		}

		void RenderScene::setThrottle(float t, float m, bool s, float c)
		{
			t = G3D::clamp(t, 0.0f, 100.0f);
			if (t != shadingQuality || m != meshDetail || s != shadows || c != cameraDistance)
			{
				shadingQuality = t;
				meshDetail = m;
				cameraDistance = c;
				shadows = s;

				lighting = effectSettings.update(t, m, s, c, desiredLighting, desiredSkyParameters, skyParameters);
			}
		}

		void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
		{
			desiredLighting = L;
			lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance, desiredLighting,
			                                 desiredSkyParameters, skyParameters);
		}

		void RenderScene::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                 G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			this->sky = sky;
			desiredSkyParameters = skyParameters;

			G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
			lighting->ambientTop = ambientTop;
			lighting->ambientBottom = ambientBottom;

			G3D::GLight sun = G3D::GLight::directional(skyParameters.lightDirection, skyParameters.lightColor * 0.9f);
			lighting->shadowedLightArray.append(sun);

			if (sky.notNull())
			{
				lighting->environmentMap = sky->getEnvironmentMap();
			}

			setLighting(lighting);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::Lighting>;
template class std::pair<RBX::Render::RenderSurface * *,RBX::Render::RenderSurface * *>;
// 005035e0: G3D::Array<RenderSurface>::resize(int, bool) (ret 8, 0x44-byte element dtor loop, realloc 00503110); used by
// the proxy arrays (allocateProxies 00504290 / clearProxyArrays 00504b00).
// Near miss (563 B) until RenderSurface gets its inline default ctor (header proposal): the target value-initialises
// material +0x34 / polygonOffset +0x38 / mesh +0x3c (not z +0x30); with that ctor the body is IDENTICAL (scratch compile).
template void G3D::Array<RBX::Render::RenderSurface>::resize(int, bool);
