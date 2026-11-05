// Layout probes for the inactive native RBX::RenderBase::Chunk / AggregateChunk / SceneManager / SimpleSceneManager /
// RenderSceneBase, Render::RenderScene / RenderSurface and RBX::ViewBase / ViewNew::ViewRbxGfx (2008-06). Each probe compiles to `mov eax, imm32; ret`; tests/record_native_render_scene.py compares the
// immediates with the sizes and offsets read from the original (allocation sizes, constructor / destructor stores).
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/RenderScene2008.h"
#include "RenderLib/ViewNew2008.h"
#include "RenderLib/RenderSceneRender2008.h"
#include "RenderLib/RenderSceneNew2008.h"
#include <stddef.h>

using namespace RBX::RenderBase;

struct NativeRenderSceneLayout
{
	static int chunkSize() { return sizeof(Chunk); }
	static int chunkEntity() { return offsetof(Chunk, entity); }
	static int chunkSubEntity() { return offsetof(Chunk, subEntity); }
	static int chunkSortValue() { return offsetof(Chunk, sortValue); }
	static int chunkPolygonOffset() { return offsetof(Chunk, polygonOffset); }
	static int chunkRadius() { return offsetof(Chunk, radius); }
	static int chunkAggregate() { return offsetof(Chunk, aggregate); }
	static int aggregateChunkSize() { return sizeof(AggregateChunk); }
	static int aggregateMaterial() { return offsetof(AggregateChunk, material); }
	static int aggregateMesh() { return offsetof(AggregateChunk, mesh); }
	static int aggregateCframe() { return offsetof(AggregateChunk, _cframe); }
	static int aggregateCastsShadows() { return offsetof(AggregateChunk, _castsShadows); }
	static int aggregateCullable() { return offsetof(AggregateChunk, _cullable); }
	static int aggregateShadowSource() { return offsetof(AggregateChunk, shadowSource); }
	static int aggregateShadowVAR() { return offsetof(AggregateChunk, shadowVAR); }
	static int aggregateShadowIndexArray() { return offsetof(AggregateChunk, shadowIndexArray); }
	static int aggregateShadowIndexArray16() { return offsetof(AggregateChunk, shadowIndexArray16); }
	static int aggregateComponents() { return offsetof(AggregateChunk, components); }
	static int sceneManagerSize() { return sizeof(SceneManager); }
	static int sceneManagerRenderScene() { return offsetof(SceneManager, renderScene); }
	static int simpleSceneManagerSize() { return sizeof(SimpleSceneManager); }
	static int bucketSize() { return sizeof(AggregatingSceneManager::Bucket); }
	static int bucketQueue() { return offsetof(AggregatingSceneManager::Bucket, queue); }
	static int bucketKeySize() { return sizeof(AggregatingSceneManager::BucketKey); }
	static int bucketKeyCullable() { return offsetof(AggregatingSceneManager::BucketKey, cullable); }
	static int bucketKeyPolygonOffset() { return offsetof(AggregatingSceneManager::BucketKey, polygonOffset); }
	static int bucketKeyMaterial() { return offsetof(AggregatingSceneManager::BucketKey, material); }
	static int aggregatingSize() { return sizeof(AggregatingSceneManager); }
	static int aggregatingBuckets() { return offsetof(AggregatingSceneManager, buckets); }
	static int aggregatingInvalidSleeping() { return offsetof(AggregatingSceneManager, invalidSleepingModels); }
	static int aggregatingInvalidMoving() { return offsetof(AggregatingSceneManager, invalidMovingModels); }
	static int sceneBaseSize() { return sizeof(RenderSceneBase); }
	static int sceneBaseChunkArray() { return offsetof(RenderSceneBase, chunkArray); }
	static int sceneBaseColorClearValue() { return offsetof(RenderSceneBase, colorClearValue); }
	static int sceneBaseShadingQuality() { return offsetof(RenderSceneBase, shadingQuality); }
	static int sceneBaseMeshDetail() { return offsetof(RenderSceneBase, meshDetail); }
	static int sceneBaseRenderStats() { return offsetof(RenderSceneBase, renderStats); }
	static int renderStatsSize() { return sizeof(RenderStats); }
	static int lightingParametersSize() { return sizeof(G3D::LightingParameters); }
	static int viewBaseSize() { return sizeof(RBX::ViewBase); }
	static int viewBaseSceneManager() { return offsetof(RBX::ViewBase, sceneManager); }
	static int viewBaseRenderLibScene() { return offsetof(RBX::ViewBase, renderLibScene); }
	static int viewBaseTextureManager() { return offsetof(RBX::ViewBase, textureManager); }
	static int viewBaseMaterialFactory() { return offsetof(RBX::ViewBase, materialFactory); }
	static int viewBaseDataModel() { return offsetof(RBX::ViewBase, dataModel); }
	static int viewBaseLightingChanged() { return offsetof(RBX::ViewBase, lightingChangedConnection); }
	static int viewBaseDescendentAdded() { return offsetof(RBX::ViewBase, workspaceDescendentAddedConnection); }
	static int viewBaseLightingValid() { return offsetof(RBX::ViewBase, lightingValid); }
	static int scopedConnectionSize() { return sizeof(boost::signals::scoped_connection); }
	static int textureManagerSize() { return sizeof(G3D::TextureManager); }
	static int viewRbxGfxSize() { return sizeof(RBX::ViewNew::ViewRbxGfx); }
	static int viewRbxGfxSkyValid() { return offsetof(RBX::ViewNew::ViewRbxGfx, skyValid); }
	typedef RBX::Render::RenderScene RS;
	typedef RBX::Render::RenderSurface RSF;
	static int renderSceneSize() { return sizeof(RS); }
	static int renderSceneProxyArray() { return offsetof(RS, proxyArray); }
	static int renderSceneDiffuseProxyArray() { return offsetof(RS, diffuseProxyArray); }
	static int renderSceneReflectProxyArray() { return offsetof(RS, reflectProxyArray); }
	static int renderSceneTransparentProxyArray() { return offsetof(RS, transparentProxyArray); }
	static int renderSceneShadowProxyArray() { return offsetof(RS, shadowProxyArray); }
	static int renderSceneShadowCachingChunkArray() { return offsetof(RS, shadowCachingChunkArray); }
	static int renderSceneShadowVAR() { return offsetof(RS, shadowVAR); }
	static int renderSceneShadowVARArea() { return offsetof(RS, shadowVARArea); }
	static int renderSceneEffectSettings() { return offsetof(RS, effectSettings); }
	static int renderSceneDesiredLighting() { return offsetof(RS, desiredLighting); }
	static int renderSceneLighting() { return offsetof(RS, lighting); }
	static int renderSceneShadows() { return offsetof(RS, shadows); }
	static int renderSceneCameraDistance() { return offsetof(RS, cameraDistance); }
	static int renderSceneShadowIndexArray() { return offsetof(RS, shadowIndexArray); }
	static int renderSceneDebugShadowVolumes() { return offsetof(RS, debugShadowVolumes); }
	static int renderSceneSky() { return offsetof(RS, sky); }
	static int renderSceneDesiredSkyParameters() { return offsetof(RS, desiredSkyParameters); }
	static int renderSceneSkyParameters() { return offsetof(RS, skyParameters); }
	static int effectSettingsSize() { return sizeof(RBX::Render::EffectSettings); }
	static int renderSurfaceSize() { return sizeof(RSF); }
	static int renderSurfaceZ() { return offsetof(RSF, z); }
	static int renderSurfaceMaterial() { return offsetof(RSF, material); }
	static int renderSurfacePolygonOffset() { return offsetof(RSF, polygonOffset); }
	static int renderSurfaceMesh() { return offsetof(RSF, mesh); }
	static int renderSurfaceFullMesh() { return offsetof(RSF, fullMesh); }
	static int lightingShadowedLightArray() { return offsetof(G3D::Lighting, shadowedLightArray); }
	static int lightingAmbientTop() { return offsetof(G3D::Lighting, ambientTop); }
	typedef RBX::RenderNew::RenderScene NS;
	static int renderNewSceneSize() { return sizeof(NS); }
	static int renderNewSceneRootNode() { return offsetof(NS, rootNode); }
	static int renderNewSceneEntity() { return offsetof(NS, entity); }
	static int renderNewSceneMaterial() { return offsetof(NS, material); }
	static int renderNewSceneMesh() { return offsetof(NS, mesh); }
	static int renderNewSceneProxyArray() { return offsetof(NS, proxyArray); }
	static int renderNewSceneShadowProxyArray() { return offsetof(NS, shadowProxyArray); }
	static int renderNewSceneShadowCachingChunkArray() { return offsetof(NS, shadowCachingChunkArray); }
	static int renderNewSceneShadowVAR() { return offsetof(NS, shadowVAR); }
	static int renderNewSceneShadowVARArea() { return offsetof(NS, shadowVARArea); }
	static int renderNewSceneEffectSettings() { return offsetof(NS, effectSettings); }
	static int renderNewSceneDesiredLighting() { return offsetof(NS, desiredLighting); }
	static int renderNewSceneLighting() { return offsetof(NS, lighting); }
	static int renderNewSceneShadows() { return offsetof(NS, shadows); }
	static int renderNewSceneCameraDistance() { return offsetof(NS, cameraDistance); }
	static int renderNewSceneShadowIndexArray() { return offsetof(NS, shadowIndexArray); }
	static int renderNewSceneDebugShadowVolumes() { return offsetof(NS, debugShadowVolumes); }
	static int renderNewSceneShadowColor() { return offsetof(NS, shadowColor); }
	static int renderNewSceneColorShiftTop() { return offsetof(NS, colorShiftTop); }
	static int renderNewSceneColorShiftBottom() { return offsetof(NS, colorShiftBottom); }
	static int renderNewSceneBrightness() { return offsetof(NS, brightness); }
	static int renderNewSceneAmbient() { return offsetof(NS, ambient); }
	static int renderNewSceneLightingTerm0() { return offsetof(NS, lightingTerm0); }
	static int renderNewSceneLightingTerm4() { return offsetof(NS, lightingTerm4); }
	static int renderNewSceneDesiredSkyParameters() { return offsetof(NS, desiredSkyParameters); }
	static int renderNewSceneSkyParameters() { return offsetof(NS, skyParameters); }
	static int renderNewSceneEffectSettingsSize() { return sizeof(RBX::RenderNew::EffectSettings); }
	static int renderNewSceneEffectSettingsFarCullZ() { return offsetof(RBX::RenderNew::EffectSettings, _farCullZ); }
	static int renderNewSceneEffectSettingsLODShift() { return offsetof(RBX::RenderNew::EffectSettings, _LODShift); }
};

#define PROBE(name) int native##name() { return NativeRenderSceneLayout::name(); }
PROBE(chunkSize) PROBE(chunkEntity) PROBE(chunkSubEntity) PROBE(chunkSortValue) PROBE(chunkPolygonOffset)
PROBE(chunkRadius) PROBE(chunkAggregate) PROBE(aggregateChunkSize) PROBE(aggregateMaterial) PROBE(aggregateMesh)
PROBE(aggregateCframe) PROBE(aggregateCastsShadows) PROBE(aggregateCullable) PROBE(aggregateShadowSource)
PROBE(aggregateShadowVAR) PROBE(aggregateShadowIndexArray) PROBE(aggregateShadowIndexArray16)
PROBE(aggregateComponents) PROBE(sceneManagerSize) PROBE(sceneManagerRenderScene) PROBE(simpleSceneManagerSize)
PROBE(bucketSize) PROBE(bucketQueue) PROBE(bucketKeySize) PROBE(bucketKeyCullable) PROBE(bucketKeyPolygonOffset)
PROBE(bucketKeyMaterial) PROBE(aggregatingSize) PROBE(aggregatingBuckets) PROBE(aggregatingInvalidSleeping)
PROBE(aggregatingInvalidMoving)
PROBE(sceneBaseSize) PROBE(sceneBaseChunkArray) PROBE(sceneBaseColorClearValue) PROBE(sceneBaseShadingQuality)
PROBE(sceneBaseMeshDetail) PROBE(sceneBaseRenderStats) PROBE(renderStatsSize) PROBE(lightingParametersSize)
PROBE(viewBaseSize) PROBE(viewBaseSceneManager) PROBE(viewBaseRenderLibScene) PROBE(viewBaseTextureManager)
PROBE(viewBaseMaterialFactory) PROBE(viewBaseDataModel) PROBE(viewBaseLightingChanged) PROBE(viewBaseDescendentAdded)
PROBE(viewBaseLightingValid) PROBE(scopedConnectionSize) PROBE(textureManagerSize) PROBE(viewRbxGfxSize)
PROBE(viewRbxGfxSkyValid)
PROBE(renderSceneSize) PROBE(renderSceneProxyArray) PROBE(renderSceneDiffuseProxyArray) PROBE(renderSceneReflectProxyArray)
PROBE(renderSceneTransparentProxyArray) PROBE(renderSceneShadowProxyArray) PROBE(renderSceneShadowCachingChunkArray)
PROBE(renderSceneShadowVAR) PROBE(renderSceneShadowVARArea) PROBE(renderSceneEffectSettings)
PROBE(renderSceneDesiredLighting) PROBE(renderSceneLighting) PROBE(renderSceneShadows) PROBE(renderSceneCameraDistance)
PROBE(renderSceneShadowIndexArray) PROBE(renderSceneDebugShadowVolumes) PROBE(renderSceneSky)
PROBE(renderSceneDesiredSkyParameters) PROBE(renderSceneSkyParameters) PROBE(effectSettingsSize) PROBE(renderSurfaceSize)
PROBE(renderSurfaceZ) PROBE(renderSurfaceMaterial) PROBE(renderSurfacePolygonOffset) PROBE(renderSurfaceMesh)
PROBE(renderSurfaceFullMesh) PROBE(lightingShadowedLightArray) PROBE(lightingAmbientTop)
PROBE(renderNewSceneSize) PROBE(renderNewSceneRootNode) PROBE(renderNewSceneEntity) PROBE(renderNewSceneMaterial) PROBE(renderNewSceneMesh) PROBE(renderNewSceneProxyArray) PROBE(renderNewSceneShadowProxyArray) PROBE(renderNewSceneShadowCachingChunkArray) PROBE(renderNewSceneShadowVAR) PROBE(renderNewSceneShadowVARArea) PROBE(renderNewSceneEffectSettings) PROBE(renderNewSceneDesiredLighting) PROBE(renderNewSceneLighting) PROBE(renderNewSceneShadows) PROBE(renderNewSceneCameraDistance) PROBE(renderNewSceneShadowIndexArray) PROBE(renderNewSceneDebugShadowVolumes) PROBE(renderNewSceneShadowColor) PROBE(renderNewSceneColorShiftTop) PROBE(renderNewSceneColorShiftBottom) PROBE(renderNewSceneBrightness) PROBE(renderNewSceneAmbient) PROBE(renderNewSceneLightingTerm0) PROBE(renderNewSceneLightingTerm4) PROBE(renderNewSceneDesiredSkyParameters) PROBE(renderNewSceneSkyParameters) PROBE(renderNewSceneEffectSettingsSize) PROBE(renderNewSceneEffectSettingsFarCullZ) PROBE(renderNewSceneEffectSettingsLODShift)
