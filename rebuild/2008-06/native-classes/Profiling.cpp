// >>> native-status (generated) -- do not edit >>>
// Profiling | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 8f1c6f1c | roc native-status --write
#include "util/Profiling.h"

namespace RBX
{
	namespace Profiling
	{
		DWORD Mark::markTlsIndex = NULL;

		void init(bool enabled)
		{
			if (enabled)
				Mark::markTlsIndex = TlsAlloc();
		}

		Bucket::Bucket()
			: sampleTimeSpan(0),
			  wallTimeSpan(0),
			  frames(0)
		{
		}

		Bucket& Bucket::operator+=(const Bucket& other)
		{
			this->sampleTimeSpan += other.sampleTimeSpan;
			this->wallTimeSpan += other.wallTimeSpan;
			this->frames += other.frames;

			return *this;
		}

		Profiler::Profiler(const char* name)
			: bucketTimeSpan(0.01),
			  currentBucket(0),
			  lastSampleTime(G3D::System::getTick()),
			  name(name)
		{
		}

		CodeProfiler::CodeProfiler(const char* name)
			: Profiler(name),
			  parent(NULL)
		{
		}

		CountProfiler::CountProfiler(const char* name)
			: Profiler(name), lastCount(0)
		{
		}

		void CountProfiler::sample(unsigned int count)
		{
			double time = G3D::System::getTick();
			double elapsed = time - lastSampleTime;
			if (elapsed >= bucketTimeSpan)
			{
				currentBucket = (currentBucket + 1) & 2047;
				buckets[currentBucket].wallTimeSpan = count - lastCount;
				buckets[currentBucket].sampleTimeSpan = elapsed;
			}
			else
			{
				buckets[currentBucket].wallTimeSpan += count - lastCount;
				buckets[currentBucket].sampleTimeSpan += elapsed;
			}
			lastCount = count;
			lastSampleTime = time;
		}

		void CodeProfiler::log(bool frameTick, double wallTimeElapsed)
		{
			double time = G3D::System::getTick();
			double elapsed = time - lastSampleTime;
			if (elapsed >= bucketTimeSpan)
			{
				currentBucket = (currentBucket + 1) & 2047;
				buckets[currentBucket].frames = frameTick ? 1 : 0;
				buckets[currentBucket].sampleTimeSpan = elapsed;
				buckets[currentBucket].wallTimeSpan = wallTimeElapsed;
			}
			else
			{
				if (frameTick)
					++buckets[currentBucket].frames;
				buckets[currentBucket].sampleTimeSpan += elapsed;
				buckets[currentBucket].wallTimeSpan += wallTimeElapsed;
			}
			lastSampleTime = time;
		}

		Bucket Profiler::getData(double window) const
		{
			Bucket bucket;

			if (Mark::markTlsIndex != 0)
			{
				const int firstBucket = currentBucket + 2047;
				const size_t count = std::min((size_t)std::max((int)(window / bucketTimeSpan), 1), (size_t)2046);
				for (size_t i = 0; i < count; ++i)
				{
					bucket += buckets[(firstBucket - i) % 2048];
					if (bucket.sampleTimeSpan >= window)
						break;
				}
			}

			return bucket;
		}

		double Bucket::getActualFPS() const
		{
			return sampleTimeSpan > 0.0 ? frames / sampleTimeSpan : 0.0;
		}

		double Bucket::getNominalFPS() const
		{
			return wallTimeSpan > 0.0 ? frames / wallTimeSpan : 0.0;
		}

		double Bucket::getFrameTime() const
		{
			return frames > 0 ? wallTimeSpan / frames : 0.0;
		}

	}
}
