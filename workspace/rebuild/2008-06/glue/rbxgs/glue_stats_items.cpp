// Rebuild glue: RBX::Stats::Item, which rbxgs declares (v8datamodel/Stats.h) but leaves unimplemented
// (rbxgs and OpenRBX v8datamodel/Stats.cpp are empty). Behavioural reconstruction, not byte-verified.
// Memory formatting follows the 2008 Log::formatMem at 0x5a6bc0 (exact): B / KB / MB / GB thresholds
// at 1e3, 1e6, 1e9.
#include "v8datamodel/Stats.h"
#include "util/Profiling.h"
#include <stdarg.h>
#include <stdio.h>

namespace RBX
{
	namespace Stats
	{



		namespace
		{
			// CPU share of one profiler over the last second
			class ProfilerItem : public Item
			{
				const Profiling::Profiler& profiler;

			public:
				ProfilerItem(const Profiling::Profiler& profiler)
					: Item(profiler.name.c_str()), profiler(profiler)
				{
				}

				virtual void update()
				{
					Profiling::Bucket b = profiler.getData(1.0);
					double busy = (double)(b.kernTimeSpan + b.userTimeSpan) / 1.0e7; // FILETIME is 100ns
					double share = b.sampleTimeSpan > 0 ? busy / b.sampleTimeSpan : 0;
					formatValue(share, "%.1f%%", share * 100.0);
				}
			};
		}

	}
}
