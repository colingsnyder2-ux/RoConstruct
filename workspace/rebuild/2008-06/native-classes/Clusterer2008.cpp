// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Authentic donor implementations; original constructor 005528a0, go 00552bb0.
#include "RenderLib/Clusterer2008.h"

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <boost/bind.hpp>

namespace RBX {
namespace RenderBase {

Clusterer::Cluster* Clusterer::findClosestCluster(Sample* sample)
{
	Cluster* bestCluster = NULL;
	float bestDistance = G3D::inf();

	Clusters::const_iterator end = clusters.end();

	for (Clusters::iterator it = clusters.begin(); it != end; ++it) {
		float distance = (*it).getDistanceFromCentroid(sample);

		if (distance < bestDistance) {
			bestCluster = &(*it);
			bestDistance = distance;
		}
	}

	return bestCluster;
}

void Clusterer::Cluster::computeCentroid()
{
	G3D::Vector3 c;

	Samples::iterator it = samples.begin();
	Samples::iterator end = samples.end();

	for (; it != end; ++it) {
		c += (*it)->cframe().translation;
	}

	centroid = c / (float) samples.size();
}

unsigned int Clusterer::moveSample(Sample* sample, Cluster* cluster)
{
	while (true) {
		if (cluster->visitIndex == cluster->samples.size()) {
			cluster->samples.push_back(sample);
			cluster->visitIndex++;
			return 1;
		}
		else {
			Sample* visited = cluster->samples[cluster->visitIndex];
			{
				Cluster* bestCluster = findClosestCluster(visited);
				if (bestCluster == cluster) {
					cluster->visitIndex++;
				}
				else {
					cluster->samples[cluster->visitIndex] = sample;
					return moveSample(visited, bestCluster) + 1;
				}
			}
		}
	}
}

unsigned int Clusterer::moveSamples()
{
	unsigned int moveCount = 0;

	for (Clusters::iterator it = clusters.begin(); it != clusters.end(); ++it) {
		it->visitIndex = 0;
	}

	for (Clusters::iterator it = clusters.begin(); it != clusters.end(); ++it) {
		Cluster& cluster = *it;

		while (cluster.visitIndex < cluster.samples.size()) {
			Sample* sample = cluster.samples[cluster.visitIndex];
			Cluster* bestCluster = findClosestCluster(sample);

			if (bestCluster != &cluster) {
				cluster.samples[cluster.visitIndex] = cluster.samples.back();
				cluster.samples.pop_back();
				moveCount += moveSample(sample, bestCluster);
			}
			else {
				cluster.visitIndex++;
			}
		}
	}

	return moveCount;
}

Clusterer::Clusters* Clusterer::go(unsigned int maxSteps)
{
	if (clusterCount > 1) {
		Clusters::iterator it = clusters.begin();
		Clusters::iterator end = clusters.end();
		for (; it != end; ++it) {
			if (it->samples.size() > 0) {
				unsigned int index = rand() % it->samples.size();
				it->centroid = it->samples[index]->cframe().translation;
			}
		}

		const unsigned int threshold = std::max(1u, sampleSize / 20);

		unsigned int step = 0;
		while (true) {
			step++;
			if (moveSamples() <= threshold) {
				break;
			}
			if (step == maxSteps) {
				break;
			}

			std::for_each(clusters.begin(), clusters.end(), boost::bind(&Cluster::computeCentroid, _1));
		}
	}

	return &clusters;
}

Clusterer::Clusterer(unsigned int clusterCount) : sampleSize(0), clusterCount(clusterCount), clusters(clusterCount)
{
}

} // namespace Render
} // namespace RBX
