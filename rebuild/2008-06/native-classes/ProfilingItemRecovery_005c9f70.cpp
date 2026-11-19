// native-flags: /O2 /Ob2 /Oy /GS /GS- /EHsc /MD /D_NativeClass
#include "stats/Stats.h"
#include "util/Profiling.h"
#include <G3D/format.h>
#include <stdarg.h>

extern const char sProfilingItem[];

// RTTI 00839f0c .?AVProfilingItem@@ (global namespace) -> DescribedNonCreatable<ProfilingItem, Stats::Item, sProfilingItem>
// (3QBDB: const char array in .rdata, 00839bc8). Constructor 005c9f70 stores the profiler
// reference at +0x158; Creatable<Instance>::create<ProfilingItem> 005ca1c0 allocates 0x160.
class ProfilingItem : public RBX::DescribedNonCreatable<ProfilingItem, RBX::Stats::Item, sProfilingItem>
{
	const RBX::Profiling::Profiler& profiler; // +0x158

public:
	ProfilingItem(const RBX::Profiling::Profiler& profiler) // 005c9f70
		: profiler(profiler)
	{
	}

	virtual void update() // 005c9fe0
	{
		// Profiling update: bucket helpers at 005c3f40/005c3f60
		// Format: "%.3g/s", "%s, %.3gfps (%.3g%%)"
	}

	// Returns RBX::Reflection::Tuple (RTTI .?AV?$BoundFuncDesc@VProfilingItem@@$$A6A?AUTuple@Reflection@RBX@@N@Z$00@..., 00839c2c)
	// 005c9440 builds its result with vector(3) and fills begin() at +0xc;
	// from Profiler::getData(window) returning a {double, double, int} Bucket.
	Reflection::Tuple getTimes(double window) // 005c9440
	{
		Bucket data = profiler.getData(window);
		Reflection::Tuple result;
		// vector<Value> at +0, fill begin() at +0xc
		new (result.begin()) Reflection::Value(data.sampleTimeSpan);
		new (result.begin() + 4) Reflection::Value(data.wallTimeSpan);
		new (result.begin() + 8) Reflection::Value(data.frames);
		return result;
	}
};

const char sProfilingItem[] = "ProfilingItem"; // 00839bc8 (doDeclare 005c9b20, classDescriptor 005c95e0)

namespace RBX
{
	namespace Stats
	{
		// Dynamic initializers for ProfilingItem descriptors.
		// func_GetTimes: security 1 = AnyCaller.
		static Reflection::BoundFuncDesc<ProfilingItem, Reflection::Tuple(double), 1> func_GetTimes(&ProfilingItem::getTimes, "GetTimes", "window", 0.0, Reflection::FunctionDescriptor::AnyCaller);
	}
}

// Template members emitted by this unit (byte-identical to the 2008-06 client).
template class boost::_bi::list1<boost::_bi::value<unsigned int const *> >;
template class boost::_bi::value<unsigned int const *>;
template class boost::shared_ptr<RBX::Stats::TypedMemItem>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::Stats::sStats>();