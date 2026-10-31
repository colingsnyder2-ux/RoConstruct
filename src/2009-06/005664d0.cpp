// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-render roc_espclaude_8285e36ddceb8b09.cpp

// Candidate translation unit (score above; library headers required).
#include "RenderLib/EffectSettings.h"
#include "RenderLib/TextureProxy.h"
#include <G3D/Array.h>

namespace RBX
{
	namespace Render
	{
		class Material : public G3D::ReferenceCountedObject
		{
		public:
			class Level
			{
				friend class Material;
			public:
				bool emptyLevel;
				Level();
				virtual ~Level();
				virtual void exeV1();
				virtual void exeV2();
				virtual void exeV3();
				virtual void exeV4();
				virtual G3D::ReferenceCountedPointer<G3D::Texture> matte(G3D::RenderDevice* rd) const;
				virtual void exeV6();
				virtual const G3D::Color3& color() const;
				virtual float transparent() const;
				virtual float reflect() const;
				virtual void configureRenderDevice(G3D::RenderDevice* renderDevice) const;
			};

		private:
			G3D::Array<Level> levels;
		public:
			//Material(const Material&);
			Material();
			const Level& appendEmptyLevel();
			const Level& appendLevel(G3D::Color3, float, float, float, float);
			const Level& appendLevel(G3D::ReferenceCountedPointer<TextureProxy> baseTexture, G3D::Color3 color, float specular, float shiny, float reflect, float transparent);

			virtual ~Material();
			size_t levelCount() const;

			Level& getLevel(int);

			const Level* detailLevel(float lvl) const
			{
				if (levels.size() == 0)
				{
					return NULL;
				}
				else
				{
					int sizeMinusOne = levels.size() - 1;
					int level = lvl * levels.size();

					if (level <= 0)
						level = 0;
					else if (level >= sizeMinusOne)
						level = sizeMinusOne;

					return !levels[level].emptyLevel ? levels.begin() + level : NULL;
				}
			}

			bool veryTransparent() const;
			//Material& operator=(const Material&);
		};
	}
}

#define Material Material_unused_
#include "RenderLib/Material.h"
#undef Material
#include "RenderLib/RenderSurface.h"
#include "RenderLib/Chunk.h"
#include <GLG3D/Sky.h>
#include <G3D/GCamera.h>

namespace RBX
{
	namespace Render
	{
		class RenderScene
		{
			friend class SceneManager;

		private:
			char exePad[0x28];
			G3D::Array<RenderSurface> proxyArray;
			G3D::Array<RenderSurface*> diffuseProxyArray;
			G3D::Array<RenderSurface*> reflectProxyArray;
			G3D::Array<RenderSurface*> transparentProxyArray;
			G3D::Array<RenderSurface> shadowProxyArray;
			G3D::Array<G3D::ReferenceCountedPointer<Chunk>> shadowCachingChunkArray;
			G3D::VAR shadowVAR;
			G3D::ReferenceCountedPointer<G3D::VARArea> shadowVARArea;
			EffectSettings effectSettings;
			G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;
			G3D::ReferenceCountedPointer<G3D::Lighting> lighting;

			float shadingQuality;
			float meshDetail;
			bool shadows;
			float cameraDistance;
			G3D::Array<G3D::ReferenceCountedPointer<Chunk>> chunkArray;
			G3D::Array<unsigned> shadowIndexArray;
		public:
			RenderStats renderStats;
			bool debugShadowVolumes;
			G3D::ReferenceCountedPointer<G3D::Sky> sky;
			G3D::Color4 colorClearValue;
			G3D::LightingParameters desiredSkyParameters;
			G3D::LightingParameters skyParameters;

		private:
			void updateShadowVAR(const G3D::Array<G3D::Vector3>& shadowVertex);
			void computeShadowVolumeGeometry(G3D::Array<unsigned>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex, const G3D::GLight& light, bool generateLightCap, float shadowVertexDistance) const;
			void clearProxyArrays();
			void allocateProxies(G3D::RenderDevice*, const G3D::GCamera&);
			void classifyProxies();
			void sortProxies();
			void computeProxyArrays(G3D::RenderDevice* rd, const G3D::GCamera& camera);
			void sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const;
			void markStencilShadows(G3D::RenderDevice* rd, const G3D::GCamera& camera, const G3D::GLight& light);
			void sendShadowProxyMeshGeometry(G3D::RenderDevice*, const G3D::GLight&) const;
			void turnOnLights(G3D::RenderDevice* rd, bool allLights) const;
			void diffusePass(G3D::RenderDevice*);
			void reflectionPass(G3D::RenderDevice* rd);
			void transparentPass(G3D::RenderDevice* rd);
			void debugShowTextures(G3D::RenderDevice*, const G3D::GCamera&);
			void renderShadowVolumeGeometry(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance);
		public:
			RenderScene();
			~RenderScene();

			void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters, G3D::Color3 ambientTop, G3D::Color3 ambientBottom);
			void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L);
			void setThrottle(float t, float m, bool s, float c);
			float getShadingQuality() const
			{
				return shadingQuality;
			}
			float getMeshDetail() const
			{
				return meshDetail;
			}
			void render(G3D::RenderDevice* rd, const G3D::GCamera& camera);
		};

		class SceneManager
		{
		public:
			RenderScene* renderScene;
		public:
			virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>&, bool) = 0;
			virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>&) = 0;
			virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>&) = 0;
			virtual void clear() = 0;
			virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>&, bool) = 0;
			virtual void prerender(double) = 0;
			virtual ~SceneManager() {}
		protected:
			SceneManager(RenderScene* renderScene)
				: renderScene(renderScene)
			{
			}
			void clearScene()
			{
				renderScene->chunkArray.clear();
			}
			void addToScene(const G3D::ReferenceCountedPointer<Chunk>& chunk)
			{
				renderScene->chunkArray.push_back(chunk);
			}
			void removeFromScene(const G3D::ReferenceCountedPointer<Chunk>& chunk)
			{
				renderScene->chunkArray.fastRemove(renderScene->chunkArray.findIndex(chunk));
			}
		};
	}
}


namespace RBX
{
	namespace Render
	{
		RenderScene::RenderScene()
			: shadingQuality(-1.0f),
			  shadows(false),
			  debugShadowVolumes(false),
			  meshDetail(-1.0f),
			  cameraDistance(G3D::inf()),
			  colorClearValue(G3D::Color3(0.5f, 0.5f, 1.0f))
		{
			desiredLighting = lighting = G3D::Lighting::create();
		}

		RenderScene::~RenderScene() {}

		void RenderScene::turnOnLights(G3D::RenderDevice* rd, bool allLights) const
		{
			rd->enableLighting();

			for (int i = 0; i < lighting->lightArray.size(); i++)
			{
				rd->setLight(i, lighting->lightArray[i]);
			}

			if (allLights)
			{
				for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
				{
					rd->setLight(lighting->lightArray.size() + i, lighting->shadowedLightArray[i]);
				}
			}

			G3D::Color3 average = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
			rd->setAmbientLightColor(average);

			int runningTotal = lighting->shadowedLightArray.size() * 2;

			G3D::Vector3 direction = G3D::Vector3(-0.4f, -1.0f, 0.1f);
			if (lighting->shadowedLightArray.size() > 0)
			{
				direction = -lighting->shadowedLightArray.front().position.xyz();
			}

			if (effectSettings.hemisphereLighting())
			{
				if (lighting->ambientBottom != average)
				{
					rd->setLight(runningTotal, G3D::GLight::directional(direction, lighting->ambientBottom - average, false, true));
					runningTotal++;
				}

				if (lighting->ambientTop != average)
				{
					rd->setLight(runningTotal + 1, G3D::GLight::directional(G3D::Vector3::unitY(), lighting->ambientTop - average, false, true));
				}
			}
		}

		void RenderScene::sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const
		{
			for (int i = diffuseProxyArray.size() - 1; i >= 0; i--)
			{
				RenderSurface* current = diffuseProxyArray[i];
				rd->setObjectToWorldMatrix(current->cframe);
				rd->setPolygonOffset(current->polygonOffset);
				current->material->configureRenderDevice(rd);
				Mesh::sendGeometry(current->mesh, rd);
			}
		}

		void RenderScene::transparentPass(G3D::RenderDevice* rd)
		{
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
			rd->setBlendFunc(G3D::RenderDevice::BLEND_SRC_ALPHA, G3D::RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA, G3D::RenderDevice::BLENDEQ_ADD);
			rd->disableDepthWrite();

			for (int i = 0; i < transparentProxyArray.size(); i++)
			{
				RenderSurface* current = transparentProxyArray[i];
				const Material::Level* level = current->material;

				rd->setObjectToWorldMatrix(current->cframe);
				rd->setPolygonOffset(current->polygonOffset);
				current->material->configureRenderDevice(rd);
				rd->setColor(G3D::Color4(level->color(), 1.0f - level->transparent()));
				Mesh::sendGeometry(current->mesh, rd);
			}
		}

		void RenderScene::renderShadowVolumeGeometry(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance)
		{
			rd->beginIndexedPrimitives();
			rd->setVertexArray(shadowVAR);
			rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray.size(), shadowIndexArray.begin());
			rd->endIndexedPrimitives();

			for (int i = 0; i < shadowCachingChunkArray.size(); i++)
			{
				shadowCachingChunkArray[i]->renderShadows(rd, light, caps, shadowVertexDistance);
			}
		}

		void RenderScene::reflectionPass(G3D::RenderDevice* rd)
		{
			if (G3D::GLCaps::supports_GL_EXT_texture_cube_map() && lighting->environmentMap.notNull() && 
				(lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP || 
				lighting->environmentMap->getDimension() == G3D::Texture::DIM_CUBE_MAP_NPOT))
			{
				rd->pushState();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
				rd->setPolygonOffset(-0.2);
				rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLENDEQ_ADD);
				rd->disableLighting();
				rd->configureReflectionMap(1, lighting->environmentMap);
				rd->disableDepthWrite();

				for (int i = 0; i < reflectProxyArray.size(); i++)
				{
					RenderSurface* current = reflectProxyArray[i];
					const Material::Level* level = current->material;

					rd->setPolygonOffset(current->polygonOffset);
					rd->setObjectToWorldMatrix(current->cframe);
					rd->setTexture(0, level->matte(rd));
					rd->setColor(G3D::Color3::white() * level->reflect());
					Mesh::sendGeometry(current->mesh, rd);
				}

				rd->popState();
			}
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
			lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance, desiredLighting, desiredSkyParameters, skyParameters);
		}

		void RenderScene::computeShadowVolumeGeometry(G3D::Array<unsigned>& indexArray, G3D::Array<G3D::Vector3>& shadowVertex, const G3D::GLight& light, bool generateLightCap, float shadowVertexDistance) const
		{
			renderStats.cpuShadow.tick();
			shadowVertex.fastClear();
			indexArray.fastClear();

			shadowVertex.append(-light.position.xyz().direction() * shadowVertexDistance);

			G3D::Vector3 worldLight = light.position.xyz().direction();

			for (int i = 0; i < shadowProxyArray.size(); i++)
			{
				const RenderSurface& current = shadowProxyArray[i];
				current.fullMesh->computeDirectionalShadowVolume(current.cframe, worldLight, indexArray, shadowVertex, generateLightCap);
			}

			renderStats.cpuShadow.tock();
		}

		void RenderScene::updateShadowVAR(const G3D::Array<G3D::Vector3>& shadowVertex)
		{
			size_t size = shadowVertex.size() * 12 + 16;
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

		void RenderScene::computeProxyArrays(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			renderStats.computeProxyArrays.tick();

			diffuseProxyArray.fastClear();
			shadowProxyArray.fastClear();
			reflectProxyArray.fastClear();
			transparentProxyArray.fastClear();
			proxyArray.fastClear();
			shadowCachingChunkArray.fastClear();

			allocateProxies(rd, camera);
			classifyProxies();

			renderStats.sort.tick();

			sortByMaterialAndDepth(diffuseProxyArray);
			sortByMaterial(reflectProxyArray);
			sortByDepth(transparentProxyArray);

			renderStats.sort.tock();
			renderStats.computeProxyArrays.tock();

			renderStats.diffuseProxyCount = diffuseProxyArray.size();
		}

		void RenderScene::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters, G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
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

		void RenderScene::classifyProxies()
		{
			for (int i = 0; i < proxyArray.size(); i++)
			{
				RenderSurface* ptr = &proxyArray[i];
				if (ptr->material)
				{
					if (ptr->material->transparent() > 0.0f)
					{
						transparentProxyArray.push_back(ptr);
					}
					else
					{
						diffuseProxyArray.push_back(ptr);

						if (ptr->material->reflect() > 0.0f)
							reflectProxyArray.push_back(ptr);
					}
				}
			}
		}

		void RenderScene::render(G3D::RenderDevice* rd, const G3D::GCamera& camera)
		{
			int startTriangleCount = rd->getTriangleCount();
			int markShadowsTriCount = 0;
			int unshadowedTriCount = 0;
			int shadowedTriCount = 0;

			renderStats.cpuRenderTotal.tick();

			rd->setStencilConstant(0);
			rd->setStencilClearValue(0);
			rd->setProjectionAndCameraMatrix(camera);

			if (effectSettings.applyToneMap())
			{
				effectSettings.getToneMap()->beginFrame(rd);
			}

			rd->setColorClearValue(colorClearValue);
			rd->clear(sky.isNull() || !effectSettings.skyBox(), true, true);

			if (sky.notNull() && effectSettings.skyBox())
			{
				sky->render(rd, skyParameters);
			}

			computeProxyArrays(rd, camera);

			rd->setShadeMode(G3D::RenderDevice::SHADE_SMOOTH);
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);
			rd->setAlphaTest(G3D::RenderDevice::ALPHA_GREATER, 0.1);
			rd->pushState();

			turnOnLights(rd, effectSettings.useAllLightsInUnshadowedPass());

			Mesh::beginRender(rd, true, false);

			if (!debugShadowVolumes)
			{
				int prevTriangleCount = rd->getTriangleCount();
				sendDiffuseProxyMeshGeometry(rd);
				unshadowedTriCount = rd->getTriangleCount() - prevTriangleCount;
			}

			Mesh::endRender(rd);

			rd->popState();

			if (effectSettings.stencilShadows())
			{
				rd->pushState();
				rd->disableDepthWrite();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

				for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
				{
					if (i > 0)
					{
						rd->clear(false, false, true);
					}

					const G3D::GLight& current = lighting->shadowedLightArray[i];

					if (effectSettings.alphaBlendShadowLights())
					{
						rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLENDEQ_ADD);
						rd->enableLighting();
						rd->setLight(0, current); 
					}
					else
					{
						turnOnLights(rd, true);
					}

					int prevTriangleCount = rd->getTriangleCount();
					markStencilShadows(rd, camera, current);
					markShadowsTriCount += rd->getTriangleCount() - prevTriangleCount;

					if (!debugShadowVolumes)
					{
						rd->setStencilConstant(0);
						rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

						int prevTriCount = rd->getTriangleCount();

						rd->setPolygonOffset(0.0);
						rd->setStencilTest(G3D::RenderDevice::STENCIL_EQUAL);
						
						Mesh::beginRender(rd, true, false);
						sendDiffuseProxyMeshGeometry(rd);
						Mesh::endRender(rd);

						shadowedTriCount += rd->getTriangleCount() - prevTriCount;
					}
				}
				
				rd->popState();
			}
			else
			{
				renderStats.cpuShadow.tick();
				renderStats.cpuShadow.tock();
			}

			rd->pushState();

			Mesh::beginRender(rd, true, false);
			reflectionPass(rd);
			Mesh::endRender(rd);

			rd->popState();

			rd->pushState();

			turnOnLights(rd, true);
			Mesh::beginRender(rd, true, false);
			transparentPass(rd);
			Mesh::endRender(rd);

			rd->popState();

			if (sky.notNull() && effectSettings.skyBox())
			{
				sky->renderLensFlare(rd, skyParameters);
			}

			if (effectSettings.applyDepthBlur())
			{
				effectSettings.getDepthBlur()->apply(rd);
			}

			if (effectSettings.applyToneMap())
			{
				effectSettings.getToneMap()->endFrame(rd);
			}

			renderStats.cpuRenderTotal.tock();
			renderStats.pushPopCount = rd->debugNumPushStateCalls();

			int endTriangleCount = rd->getTriangleCount();

			renderStats.markShadowsTriangles = markShadowsTriCount;
			renderStats.totalTriangles = endTriangleCount - startTriangleCount;
			renderStats.shadowedLightTriangles = shadowedTriCount;
			renderStats.unshadowedTriangles = unshadowedTriCount;
			renderStats.majorGLStateChanges = rd->debugNumMajorOpenGLStateChanges();
			renderStats.minorGLStateChanges = rd->debugNumMinorOpenGLStateChanges();
			renderStats.majorStateChanges = rd->debugNumMajorStateChanges();
			renderStats.minorStateChanges = rd->debugNumMinorStateChanges();
		}

		void RenderScene::markStencilShadows(G3D::RenderDevice* rd, const G3D::GCamera& camera, const G3D::GLight& light)
		{
			static G3D::Array<G3D::Vector3> shadowVertex;

			float farPlane = G3D::min(10000.0f, -camera.getFarPlaneZ() * 0.2f);

			shadowIndexArray.fastClear();
			computeShadowVolumeGeometry(shadowIndexArray, shadowVertex, light, true, farPlane);

			updateShadowVAR(shadowVertex);

			rd->pushState();
			rd->setDepthTest(G3D::RenderDevice::DEPTH_LEQUAL);

			if (debugShadowVolumes)
			{
				rd->setColor(G3D::Color3::white() * 0.25);
				rd->setCullFace(G3D::RenderDevice::CULL_NONE);
				rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLENDEQ_ADD);
				rd->disableDepthWrite();
			}
			else
			{
				rd->disableDepthWrite();
				rd->disableColorWrite();
				rd->setDepthTest(G3D::RenderDevice::DEPTH_LESS);
				rd->setPolygonOffset(0.2);

				if (G3D::GLCaps::supports_two_sided_stencil())
				{
					rd->setCullFace(G3D::RenderDevice::CULL_NONE);
					rd->setStencilOp(
						G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP, G3D::RenderDevice::STENCIL_KEEP,
						G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_INCR_WRAP, G3D::RenderDevice::STENCIL_KEEP
					);
				}
				else
				{
					rd->setCullFace(G3D::RenderDevice::CULL_BACK);
					rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP, G3D::RenderDevice::STENCIL_KEEP);
				}

				rd->disableLighting();
			}

			rd->setShadeMode(G3D::RenderDevice::SHADE_FLAT);
			rd->setObjectToWorldMatrix(G3D::CoordinateFrame());
			renderShadowVolumeGeometry(rd, light, true, farPlane);

			if (!G3D::GLCaps::supports_two_sided_stencil() && !debugShadowVolumes)
			{
				rd->setCullFace(G3D::RenderDevice::CULL_FRONT);
				rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_INCR_WRAP, G3D::RenderDevice::STENCIL_KEEP);

				renderShadowVolumeGeometry(rd, light, true, farPlane);

				rd->setCullFace(G3D::RenderDevice::CULL_BACK);
				rd->setStencilOp(G3D::RenderDevice::STENCIL_KEEP, G3D::RenderDevice::STENCIL_DECR_WRAP, G3D::RenderDevice::STENCIL_KEEP);
			}

			rd->popState();
		}
	}
}
