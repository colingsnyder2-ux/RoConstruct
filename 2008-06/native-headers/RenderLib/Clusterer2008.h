// Authentic RenderLib donor declarations; native 2008 ownership from optimize at 0053fe10.
#ifndef RENDERLIB_CLUSTERER2008_H
#define RENDERLIB_CLUSTERER2008_H

#include "RenderLib/AggregateChunk2008.h"

#include <G3D/Vector3.h>
#include <vector>

namespace RBX {
namespace RenderBase {

class Clusterer
{
public:
	typedef Chunk Sample;
	typedef std::vector<Sample*> Samples;

	class Cluster
	{
	public:
		G3D::Vector3 centroid;   
		Samples samples;         
		unsigned int visitIndex; 


		void computeCentroid();

		float getDistanceFromCentroid(Sample* sample)
		{
			G3D::Vector3 distance = sample->cframe().translation - centroid;
			return distance.length();
		}
	};

	typedef std::vector<Cluster> Clusters;

private:
	unsigned int sampleSize;         
	const unsigned int clusterCount; 
	Clusters clusters;               

	unsigned int moveSamples();
	unsigned int moveSample(Sample* sample, Cluster* cluster);
	Cluster* findClosestCluster(Sample* sample);

public:
	Clusterer(unsigned int clusterCount);

	template <class Iterator>
	void addSamples(Iterator _Iter, Iterator _End)
	{
		unsigned int i = 0;
		for (; _Iter != _End; ++_Iter) {
			clusters[i].samples.push_back(&**_Iter);
			++i;
			i %= clusterCount;
			sampleSize++;
		}
	}


	Clusters* go(unsigned int maxSteps);
};


} // namespace RenderBase
} // namespace RBX

#endif // RENDERLIB_CLUSTERER2008_H
