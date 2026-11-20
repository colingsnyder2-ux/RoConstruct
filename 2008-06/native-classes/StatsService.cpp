// 2008-06 native Stats unit (inactive): RBX::Stats::Item methods, TypedMemItem, the global ProfilingItem and the
// Item / ProfilingItem function descriptors (original unit 005c8e50..005ca365, dynamic initializers
// 007f5c50 / 007f5c80 / 007f5cb0), plus RBX::Stats::StatsService (its constructor 00458520 and template
// instances sit in another unit in the original). Evidence in native-headers/stats/Stats.h.
// ProfilingItem (constructor 005c9f70, update 005c9fe0, getTimes 005c9440) and Item::createBoundChildItem 005ca240
// use the 2008 util/Profiling.h (Profiler name std::string +0xc020, getData 005c4120, Bucket helpers 005c3f40 /
// 005c3f60). getTimes is not byte-exact yet (see its comment).
// Verified by tests/record_native_stats_service.py.
#include "stats/Stats.h"
#include "util/Log.h"
#include "util/Profiling.h"
#include <G3D/format.h>
#include <stdarg.h>
#include <stdio.h>

extern const char sProfilingItem[];

// RTTI 00839f0c .?AVProfilingItem@@ (global namespace) -> DescribedNonCreatable<ProfilingItem, Stats::Item,
// sProfilingItem> (3QBDB: const char array in .rdata, 00839bc8). Constructor 005c9f70 stores the profiler
// reference at +0x158; Creatable<Instance>::create<ProfilingItem> 005ca1c0 allocates 0x160.
class ProfilingItem : public RBX::DescribedNonCreatable<ProfilingItem, RBX::Stats::Item, sProfilingItem>
{
	const RBX::Profiling::Profiler& profiler; // +0x158

public:
	ProfilingItem(const RBX::Profiling::Profiler& profiler) // 005c9f70
		: profiler(profiler)
	{
	}

	// 005c9440 (GetTimes; NOT EXACT, parked after three trials: 397 B against 405 B. The target copies the second
	// value (sampleTimeSpan) into a temporary (fld [bucket]; fstp [esp+0x3c]) before the any holder is allocated,
	// as it does for the getTotalTime() rvalue, so the original second operand was an rvalue too (an accessor the
	// util/Profiling.h Bucket does not declare). Rejected: Value::set for all three (set stays out of line, 214 B);
	// static_cast<double>(data.sampleTimeSpan) (optimised away, same 397 B). Tuple(3) also needs the core
	// reflection.h Tuple(size_t) to be inline (the target calls the vector<Value>(size_t) constructor 00589c40). RTTI .?AV?$BoundFuncDesc@VProfilingItem@@$$A6A?AUTuple@Reflection@RBX@@N@Z$00@...,
	// 00839c2c). Profiler::getData 005c4120 into a local Bucket, Tuple(3) through the vector<Value>(size_t)
	// constructor 00589c40, then values[0..2] through checked vector::operator[] (_invalid_parameter_noinfo) and
	// Value::set (Type::singleton<double> 0056cd10 / <int> 0056cbc0, boost::any holder<double> 0082e21c /
	// holder<int> 008106cc with the std::swap self check). The first value is the bucket's +8 double (wallTimeSpan,
	// Bucket::getTotalTime), the second +0 (sampleTimeSpan), the third +0x10 (frames).
	RBX::Reflection::Tuple getTimes(double window)
	{
		RBX::Profiling::Bucket data = profiler.getData(window);
		RBX::Reflection::Tuple result(3);
		result.values[0] = data.getTotalTime();
		result.values[1] = data.sampleTimeSpan;
		result.values[2] = data.frames;
		return result;
	}

protected:
	virtual void update(); // 005c9fe0
};

const char sProfilingItem[] = "ProfilingItem"; // 00839bc8 (doDeclare 005c9b20, classDescriptor 005c95e0)

namespace RBX
{
	namespace Stats
	{
		char sStatsItem[] = "StatsItem"; // 00950c6c (classDescriptor 0045dc70)
		char sStats[] = "Stats";         // 00950c64 (classDescriptor 00457af0)
	}

	// Template members the shared headers only declare (same definitions as Feature.cpp).
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	template<class C, class F>
	Reflection::BoundFuncDesc<C, F, 1>::BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name,
		Arg1 default1, Security security)
		: FuncDesc<C>(name, security),
		  function(function),
		  default1(default1)
	{
		declareSignature(arg1Name);
	}

	namespace Stats
	{
		// Dynamic initializers 007f5c50 (0x9797e0), 007f5c80 (0x979820), 007f5cb0 (0x979860); security 1 = AnyCaller.
		static Reflection::BoundFuncDesc<Item, std::string(), 0> func_GetValueString(&Item::getStringValue2, "GetValueString", Reflection::FunctionDescriptor::AnyCaller);
		static Reflection::BoundFuncDesc<Item, double(), 0> func_GetValue(&Item::getValue, "GetValue", Reflection::FunctionDescriptor::AnyCaller);
		static Reflection::BoundFuncDesc<ProfilingItem, Reflection::Tuple(double), 1> func_GetTimes(&ProfilingItem::getTimes, "GetTimes", "window", 0.0, Reflection::FunctionDescriptor::AnyCaller);

		double Item::getValue()
		{
			update();
			return val;
		}

		std::string Item::getStringValue2()
		{
			update();
			return sValue;
		}

		void Item::formatMem(size_t bytes)
		{
			setValue(bytes, Log::formatMem(bytes));
		}

		void __cdecl Item::formatValue(double value, const char* format, ...)
		{
			va_list args;
			va_start(args, format);
			setValue(value, G3D::vformat(format, args));
			va_end(args);
		}

		template<>
		void Item::formatValue<double>(const double& value)
		{
			formatValue(value, "%.3g", value);
		}

		template<>
		void Item::formatValue<float>(const float& value)
		{
			formatValue(value, "%.3g", value);
		}

		template<>
		void Item::formatValue<int>(const int& value)
		{
			formatValue(value, "%d", value);
		}

		template<>
		void Item::formatValue<unsigned int>(const unsigned int& value)
		{
			formatValue(value, "%d", value);
		}

		template<>
		void Item::formatValue<bool>(const bool& value)
		{
			sValue = value ? "true" : "false";
			val = value ? 1 : 0; // 005c9170 reloads the bool and uses setne, not movzx
		}

		bool Item::askAddChild(const Instance* instance) const
		{
			return dynamic_cast<const Item*>(instance) != NULL;
		}

		Item* Item::createChildItem(const char* name)
		{
			boost::shared_ptr<Item> item = Creatable<Instance>::create<Item>();
			item->setName(name);
			item->setParent(this);
			return item.get();
		}

		Item* Item::createBoundMemChildItem(const char* name, const size_t& value)
		{
			boost::shared_ptr<Item> item = Creatable<Instance>::create<TypedMemItem>(&value);
			item->setName(name);
			item->setParent(this);
			return item.get();
		}

		// 005ca240: Creatable<Instance>::create<ProfilingItem> 005ca1c0 (malloc 0x160, constructor 005c9f70), named after
		// the profiler (std::string +0xc020 of the 2008 Profiler, util/Profiling.h) through a temporary std::string(const char*).
		Item* Item::createBoundChildItem(const Profiling::Profiler& profiler)
		{
			boost::shared_ptr<Item> item = Creatable<Instance>::create<ProfilingItem, const Profiling::Profiler&>(profiler);
			item->setName(profiler.name.c_str());
			item->setParent(this);
			return item.get();
		}

		TypedMemItem::TypedMemItem(const size_t* value)
			: TypedStatsItem<size_t>(value)
		{
		}

		void TypedMemItem::update()
		{
			formatMem(func());
		}

		StatsService::StatsService()
			: DescribedNonCreatable<StatsService, Instance, sStats>("Stats")
		{
		}

		bool StatsService::askAddChild(const Instance* instance) const
		{
			return dynamic_cast<const Item*>(instance) != NULL;
		}

		XmlElement* StatsService::write()
		{
			return NULL;
		}
	}
}

namespace RBX
{
	// INFERRED: process-wide profiling window, double at 0094f640 (.data, initial 3.0); no header declares it (the same
	// extern is in native-classes/DebugSettingsProfiler.cpp, whose getter 00563170 / setter 005639f0 use it).
	extern double profilerWindow;
}

// 005c9fe0: Profiler::getData(profilerWindow); with a positive sample time span val = wallTimeSpan / sampleTimeSpan and
// sValue is sprintf'd into a 64-byte aligned stack buffer (and esp, 0xffffffc0): "%.3g/s" (00839f68) of val for a
// CountProfiler (dynamic_cast 0094f648 -> 0094f69c), else with frames "%s, %.3gfps (%.3g%%)" (00839f50) of
// Log::formatTime(getFrameTime()) 005a6c60 / 005c3f60, getNominalFPS 005c3f40 and val * 100 (00817a88), else
// "%.3g%%" (00817a7c) of val * 100. Without samples val = 0 and sValue = "?" (00819e10).
void ProfilingItem::update()
{
	RBX::Profiling::Bucket data = profiler.getData(RBX::profilerWindow);
	if (data.sampleTimeSpan > 0)
	{
		val = data.wallTimeSpan / data.sampleTimeSpan;
		__declspec(align(64)) char buffer[256]; // INFERRED: size; the frame keeps it 64-byte aligned
		if (dynamic_cast<const RBX::Profiling::CountProfiler*>(&profiler))
			sprintf(buffer, "%.3g/s", val);
		else if (data.frames > 0)
		{
			std::string frameTime = RBX::Log::formatTime(data.getFrameTime());
			sprintf(buffer, "%s, %.3gfps (%.3g%%)", frameTime.c_str(), data.getNominalFPS(), 100 * val);
		}
		else
			sprintf(buffer, "%.3g%%", 100 * val);
		sValue = buffer;
	}
	else
	{
		val = 0;
		sValue = "?";
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::list1<boost::_bi::value<unsigned int const *> >;
template class boost::_bi::value<unsigned int const *>;
template class boost::shared_ptr<RBX::Stats::TypedMemItem>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::Stats::sStats>();

