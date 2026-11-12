// from server: 74% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/Clusterer.cpp

// Candidate translation unit (score above; library headers required).
#include "Clusterer.h"

#include <algorithm>
#include <cstdlib>
#include <functional>

namespace RBX {
namespace Render {

// FUNCTION: WEBSERVICE 0x101f9fa0
// FUNCTION: ROBLOX 0x00537270 FOLDED
Clusterer::Cluster* Clusterer::findClosestCluster(Sample* sample)
{
	Cluster* bestCluster = NULL;
	float bestDistance = G3D::inf();

	Clusters::iterator end = clusters.end();

	for (Clusters::iterator it = clusters.begin(); it != end; ++it) {
		float distance = it->getDistanceFromCentroid(sample);

		if (distance < bestDistance) {
			bestCluster = &(*it);
			bestDistance = distance;
		}
	}

	return bestCluster;
}

// FUNCTION: WEBSERVICE 0x101fa0c0
// FUNCTION: ROBLOX 0x004a2380 FOLDED
void Clusterer::Cluster::computeCentroid()
{
	G3D::Vector3 c(0, 0, 0);

	Samples::iterator it = samples.begin();
	Samples::iterator end = samples.end();

	for (; it != end; ++it) {
		c += (*it)->cframe().translation;
	}

	centroid = c / (float) samples.size();
}

// FUNCTION: WEBSERVICE 0x101fa2c0
// FUNCTION: ROBLOX 0x005374b0 FOLDED
unsigned int Clusterer::moveSample(Sample* sample, Cluster* cluster)
{
	while (true) {
		if (cluster->visitIndex == cluster->samples.size()) {
			cluster->samples.push_back(sample);
			cluster->visitIndex++;
			return 1;
		}

		Sample* visited = cluster->samples[cluster->visitIndex];
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

// FUNCTION: WEBSERVICE 0x101fa380
// FUNCTION: ROBLOX 0x004a2460 FOLDED
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

// FUNCTION: WEBSERVICE 0x101fa520
// FUNCTION: ROBLOX 0x00537570 FOLDED
Clusterer::Clusters* Clusterer::go(unsigned int maxSteps)
{
	if (clusterCount > 1) {
		Clusters::iterator it = clusters.begin();
		Clusters::iterator end = clusters.end();
		for (; it != end; ++it) {
			if (it->samples.size() != 0) {
				unsigned int index = rand() % it->samples.size();
				it->centroid = it->samples[index]->cframe().translation;
			}
		}

		const unsigned int threshold = std::max(1u, sampleSize / 20);

		for (unsigned int step = 1; moveSamples() > threshold; step++) {
			if (step == maxSteps) {
				break;
			}

			std::for_each(clusters.begin(), clusters.end(), std::mem_fun_ref(&Cluster::computeCentroid));
		}
	}

	return &clusters;
}

// FUNCTION: WEBSERVICE 0x101fa8a0
// FUNCTION: ROBLOX 0x005378f0 FOLDED
Clusterer::Clusterer(unsigned int clusterCount) : sampleSize(0), clusterCount(clusterCount), clusters(clusterCount)
{
}

} // namespace Render
} // namespace RBX
