// 2008-06 native Stats unit (inactive): RBX::Stats::Item methods, TypedMemItem, the global ProfilingItem and the
// Item / ProfilingItem function descriptors (original unit 005c8e50..005ca365, dynamic initializers
// 007f5c50 / 007f5c80 / 007f5cb0), plus RBX::Stats::StatsService (its constructor 00458520 and template
// instances sit in another unit in the original). Evidence in native-headers/stats/Stats.h.
// Not recovered here (they need a native 2008 util/Profiling.h: Profiler with bucketTimeSpan +0x08, currentBucket
// +0x10, 2048 0x18-byte {double, double, int} buckets from +0x18, name std::string +0xc020, getData 005c4120 and
// the bucket helpers 005c3f40 / 005c3f60): ProfilingItem::getTimes 005c9440, ProfilingItem::update 005c9fe0 and
// Item::createBoundChildItem 005ca240 (with the ProfilingItem constructor, create and shared_ptr instances it
// pulls in: 005c9ac0, 005c9ed0, 005c9f70, 005ca1c0, 005c91b0, 005c92e0).
// Verified by tests/record_native_stats_service.py.
// >>> native-status (generated) -- do not edit >>>
// StatsService | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src a27e7f99 | roc native-status --write
#include "stats/Stats.h"
#include "util/Log.h"
#include <G3D/format.h>
#include <stdarg.h>

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

#ifdef NATIVE_STATS_PENDING
	// Returns RBX::Reflection::Tuple (RTTI .?AV?$BoundFuncDesc@VProfilingItem@@$$A6A?AUTuple@Reflection@RBX@@N@Z$00@...,
	// 00839c2c), which no shared header declares yet; see the proposal in tests/record_native_stats_service.py.
	RBX::Reflection::Tuple getTimes(double window); // 005c9440 (GetTimes; body not recovered)
#endif

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
#ifdef NATIVE_STATS_PENDING
		static Reflection::BoundFuncDesc<ProfilingItem, Reflection::Tuple(double), 1> func_GetTimes(&ProfilingItem::getTimes, "GetTimes", "window", 0.0, Reflection::FunctionDescriptor::AnyCaller);
#endif

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
