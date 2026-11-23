// =============================================================================
// Profiling.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Profiling.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
