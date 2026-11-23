// =============================================================================
// aggregatingscenemanager.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/aggregatingscenemanager.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "RenderLib/SceneManager2008.h"
#include "RenderLib/Material2008.h"
#include <G3D/System.h>
namespace RBX { namespace RenderBase {
unsigned int AggregatingSceneManager::aggregationSize = 40;
void AggregatingSceneManager::prerender(double optimizationTime)
{
	const double timeUp = G3D::System::getTick() + 1000.0 * optimizationTime;

	{
		std::set<G3D::WeakReferenceCountedPointer<Chunk> >::iterator iter = invalidSleepingModels.begin();
		std::set<G3D::WeakReferenceCountedPointer<Chunk> >::iterator end = invalidSleepingModels.end();
		while (iter != end) {
			G3D::ReferenceCountedPointer<Chunk> chunk = iter->createStrongPtr();
			if (chunk.notNull()) {
				chunk->getMesh();
				chunk->getMaterial();

				G3D::ReferenceCountedPointer<AggregateChunk> aggr = chunk->aggregate.createStrongPtr();
				if (aggr.notNull()) {
					deconstructAggregate(aggr);
				}
				else {
					dequeueSleepingChunk(chunk);
					queueSleepingChunk(chunk);
				}
			}
			++iter;
		}

		invalidSleepingModels.clear();
		invalidMovingModels.clear();

		if (aggregationSize > 1) {
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator iter = buckets.begin();
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> >::iterator end = buckets.end();
			while (timeUp > G3D::System::getTick() && iter != end) {
				iter->second->optimize(*this, optimizationTime);
				++iter;
			}
		}
	}
}

} }
