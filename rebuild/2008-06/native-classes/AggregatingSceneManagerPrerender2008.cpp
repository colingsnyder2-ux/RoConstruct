// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 0053fc00: authentic donor method, checked against original virtual/call/global accesses.
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
