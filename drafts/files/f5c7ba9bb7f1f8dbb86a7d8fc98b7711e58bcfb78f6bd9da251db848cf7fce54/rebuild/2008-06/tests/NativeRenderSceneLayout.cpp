// Layout probes for the inactive native RBX::RenderBase::Chunk / AggregateChunk / SceneManager / SimpleSceneManager /
// RenderSceneBase and RBX::ViewBase / ViewNew::ViewRbxGfx (2008-06). Each probe compiles to `mov eax, imm32; ret`; tests/record_native_render_scene.py compares the
// immediates with the sizes and offsets read from the original (allocation sizes, constructor / destructor stores).
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/RenderScene2008.h"
#include "RenderLib/ViewNew2008.h"
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
