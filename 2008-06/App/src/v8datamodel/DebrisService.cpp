// 2008-06 native RBX::DebrisService (inactive); evidence in native-headers/v8datamodel/DebrisService.h.
// Verified by tests/record_native_debris_forcefield.py. Unit 0063b330..0063c3a0 plus the descriptor initializers
// 007f8b60 / 007f8ba0 (atexit 00801060 / 00801080), doDeclare 005bfe20 and classDescriptor 005c06a0.
// >>> native-status (generated) -- do not edit >>>
// DebrisService | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src a7f2b116 | roc native-status --write
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"
#include <boost/bind.hpp>

namespace RBX
{
	char sDebrisService[] = "Debris"; // 009611f0 (.data; doDeclare 005bfe20, classDescriptor 005c06a0)

	// Template members the shared headers only declare (same definitions as TimerService.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)   // 0063bdb0
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}
}

using namespace RBX;

// Dynamic initializers 007f8b60 (prop_MaxItems 0097d4fc) and 007f8ba0 (func_AddItem 0097d518, default lifetime 10.0
// from 008190b8). The 2008 AddItem pushes security 0.
static Reflection::PropDescriptor<DebrisService, int> prop_MaxItems("MaxItems", "Data", &DebrisService::getMaxItems, &DebrisService::setMaxItems, Reflection::PropertyDescriptor::STANDARD);
static Reflection::BoundFuncDesc<DebrisService, void(boost::shared_ptr<Instance>, double), 2> func_AddItem(&DebrisService::addItem, "AddItem", "item", "lifetime", 10.0, Reflection::FunctionDescriptor::NeedTrustedCaller);

// 0063b5c0 (catch funclet rows 0063b63f / 0063b673)
static void cleanup(boost::weak_ptr<Instance> item)
{
	try
	{
		boost::shared_ptr<Instance> i = item.lock();
		if (i)
			i->setParent(NULL);
	}
	catch (std::exception& e)
	{
		StandardOut::singleton()->print(MESSAGE_WARNING, e);
	}
}

namespace RBX
{
	// 0063be90: the class-name array itself is the Instance name (push 009611f0), passed as const char*
	// (DescribedCreatable<..>::DescribedCreatable<const char*> 0063bdb0).
	DebrisService::DebrisService()
		: Base(static_cast<const char*>(sDebrisService)),
		  maxItems(300),
		  timer(NULL)
	{
	}

	void DebrisService::setMaxItems(int value)
	{
		if (value != maxItems)
		{
			if (value < 0)
				throw std::runtime_error("DebrisService MaxItems must be greater than 0");

			maxItems = value;
			raisePropertyChanged(prop_MaxItems);
			DebrisService::cleanup();
		}
	}

	void DebrisService::addItem(boost::shared_ptr<Instance> item, double lifetime)
	{
		if (timer)
			timer->delay(boost::bind(&::cleanup, item), lifetime);

		queue.push(item);
		DebrisService::cleanup();
	}

	void DebrisService::cleanup()
	{
		while ((int)queue.size() > maxItems)
		{
			::cleanup(queue.front());
			queue.pop();
		}
	}

	// 0063c280: no Instance::onServiceProvider call in 2008.
	void DebrisService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		while ((int)queue.size() > 0)
		{
			::cleanup(queue.front());
			queue.pop();
		}

		timer = ServiceProvider::create<TimerService>(newProvider);
	}
}
