// =============================================================================
// Profiling.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/Profiling.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "util/Profiling.h"

void nativeProfilerEnable(bool enabled)
{
	if (enabled)
		RBX::Profiling::Mark::markTlsIndex = TlsAlloc();
}

#include "ProfiledRakPeer.h"

bool ProfiledRakPeer::RunUpdateCycle()
{
	RBX::Profiling::Mark mark(*profiler, false);
	return RakPeer::RunUpdateCycle();
}

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
