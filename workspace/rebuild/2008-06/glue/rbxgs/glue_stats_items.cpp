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
		Item::Item()
			: val(0)
		{
		}

		Item::Item(const char* name)
			: val(0)
		{
			setName(name);
		}

		bool Item::askAddChild(const Instance* instance) const
		{
			return dynamic_cast<const Item*>(instance) != NULL;
		}

		void Item::formatMem(size_t bytes)
		{
			char text[64];
			if (bytes < 1000)
				_snprintf(text, sizeof(text), "%u B", (unsigned)bytes);
			else if (bytes < 1000000)
				_snprintf(text, sizeof(text), "%u KB", (unsigned)(bytes / 1000));
			else if (bytes < 1000000000)
				_snprintf(text, sizeof(text), "%u MB", (unsigned)(bytes / 1000000));
			else
				_snprintf(text, sizeof(text), "%u GB", (unsigned)(bytes / 1000000000));
			setValue((double)bytes, text);
		}

		void Item::formatValue(double value, const char* format, ...)
		{
			char text[256];
			va_list args;
			va_start(args, format);
			_vsnprintf(text, sizeof(text), format, args);
			va_end(args);
			text[sizeof(text) - 1] = 0;
			setValue(value, text);
		}

		Item* Item::createChildItem(const char* name)
		{
			Item* item = Creatable<Instance>::create<Item>(name).get();
			item->setParent(this);
			return item;
		}

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

		Item* Item::createBoundChildItem(const Profiling::Profiler& profiler)
		{
			Item* item = Creatable<Instance>::create<ProfilerItem>(boost::cref(profiler)).get();
			item->setParent(this);
			return item;
		}
	}
}
