#pragma once
#include <G3D/Vector3.h>
#include <G3D/System.h>
#include <boost/noncopyable.hpp>
#include <string>

namespace RBX
{
	namespace Profiling
	{
		void init(bool enabled);

		struct Bucket
		{
		public:
			double sampleTimeSpan;
			double wallTimeSpan;
			int frames;

		public:
			double getActualFPS() const;
			double getNominalFPS() const;
			double getFrameTime() const;
			double getTotalTime() const { return wallTimeSpan; }
		public:
			Bucket();
		public:
			Bucket& operator+=(const Bucket& other);
		};

		class Profiler : public boost::noncopyable
		{
		protected:
			const double bucketTimeSpan;
			int currentBucket;
			Bucket buckets[2048];
			G3D::RealTime lastSampleTime;
		public:
			const std::string name;

		public:
			Profiler(const char* name);
			virtual ~Profiler() {}
		public:
			Bucket getData(double window) const;
		};

		class CountProfiler : public Profiler
		{
		private:
			unsigned int lastCount;
		public:
			CountProfiler(const char* name);
			void sample(unsigned int count);
		};

		class CodeProfiler : public Profiler
		{
			friend class Mark;

		public:
			CodeProfiler *parent;

		public:
			CodeProfiler(const char* name);
		private:
			void log(bool frameTick, double wallTimeElapsed);
		};

		class Mark
		{
		private:
			CodeProfiler& section;
			Mark* enclosingMark;
			bool frameTick;
			double startTime;
		public:
			static DWORD markTlsIndex;

			Mark(CodeProfiler& sectionSet, bool frameTickSet)
				: section(sectionSet), frameTick(frameTickSet)
			{
				if (markTlsIndex)
				{
					startTime = G3D::System::getLocalTime();
					enclosingMark = (Mark*)TlsGetValue(markTlsIndex);
					TlsSetValue(markTlsIndex, this);
				}
			}

			~Mark()
			{
				if (markTlsIndex)
				{
					TlsSetValue(markTlsIndex, enclosingMark);
					double wallTimeElapsed = G3D::System::getLocalTime() - startTime;
					section.log(frameTick, wallTimeElapsed);
					if (enclosingMark && &enclosingMark->section != &section && &enclosingMark->section != section.parent)
						enclosingMark->startTime += wallTimeElapsed;
				}
			}
		};
	}
}