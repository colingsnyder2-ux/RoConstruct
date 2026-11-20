#include "stats/Stats.h"
#include "util/Log.h"
#include "util/Profiling.h"
#include <G3D/format.h>
#include <stdarg.h>
#include <stdio.h>

extern const char sProfilingItem[];

class ProfilingItem : public RBX::DescribedNonCreatable<ProfilingItem, RBX::Stats::Item, sProfilingItem>
{
	const RBX::Profiling::Profiler& profiler; // +0x158

public:
	ProfilingItem(const RBX::Profiling::Profiler& profiler) // 005c9f70
		: profiler(profiler)
	{
	}

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
	extern double profilerWindow;
}

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

template class boost::_bi::list1<boost::_bi::value<unsigned int const *> >;
template class boost::_bi::value<unsigned int const *>;
template class boost::shared_ptr<RBX::Stats::TypedMemItem>;

template void RBX::Name::callDoDeclare<RBX::Stats::sStats>();
