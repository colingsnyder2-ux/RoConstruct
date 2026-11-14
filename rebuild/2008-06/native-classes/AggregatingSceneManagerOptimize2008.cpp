// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Authentic donor body; original prerender calls 0053fe10.
#include "RenderLib/SceneManager2008.h"
#include "RenderLib/Clusterer2008.h"
#include <algorithm>
namespace RBX { namespace RenderBase {
void AggregatingSceneManager::Bucket::optimize(AggregatingSceneManager& sceneManager, double maxTime)
{
	if (queue.size() * 4 < aggregationSize) {
		return;
	}

	unsigned int clusterCount = std::max(1U, queue.size() / aggregationSize);
	Clusterer clusterer(clusterCount);

	clusterer.addSamples(queue.begin(), queue.end());
	queue.clear();

	Clusterer::Clusters* clusters = clusterer.go(5);

	Clusterer::Clusters::iterator iter = clusters->begin();
	Clusterer::Clusters::iterator end = clusters->end();
	for (; iter != end; ++iter) {
		Clusterer::Samples::iterator iter2 = iter->samples.begin();
		Clusterer::Samples::iterator end2 = iter->samples.end();

		if (end2 - iter2 >= 4) {
			G3D::ReferenceCountedPointer<AggregateChunk> aggregateChunk;

			for (; iter2 != end2; ++iter2) {
				G3D::ReferenceCountedPointer<Chunk> chunkToAggregate = *iter2;
				if (aggregateChunk.isNull()) {
					aggregateChunk = new AggregateChunk(chunkToAggregate);
				}

				aggregateChunk->components.push_back(chunkToAggregate);
				chunkToAggregate->aggregate = aggregateChunk;
				RenderStats::aggregatedChunkCount++;
				sceneManager.removeFromScene(chunkToAggregate);
			}

			if (aggregateChunk.notNull()) {
				aggregateChunk->makeMesh();
				sceneManager.addToScene(aggregateChunk);
			}
		}
	}
}

} }
