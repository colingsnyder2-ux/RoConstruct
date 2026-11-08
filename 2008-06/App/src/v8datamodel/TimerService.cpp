// 2008-06 native RBX::TimerService (inactive); evidence in native-headers/v8datamodel/TimerService.h.
// Verified by tests/record_native_spawn.py.
// >>> native-status (generated) -- do not edit >>>
// TimerService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 9b241fd0 | roc native-status --write
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"
#include <G3D/System.h>

namespace RBX
{
	char sTimerService[] = "Timer"; // 00953654: the 2008 class name is "Timer" (doDeclare 0048a250)

	// Template members the shared headers only declare (same definitions as DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	TimerService::TimerService()
	{
	}

	void TimerService::delay(boost::function0<void> func, double seconds)
	{
		Item item;
		item.time = G3D::System::getLocalTime() + seconds;
		item.func = func;

		// 005d6e10 walks forward and inserts before the first later item, else appends.
		for (std::list<Item>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			if (iter->time > item.time)
			{
				items.insert(iter, item);
				goto done; // one shared exit: a plain return duplicates the Item destructor
			}
		}

		items.push_back(item);
	done:
		;
	}

	void TimerService::onEvent(const RunService* source, Heartbeat event)
	{
		double time = G3D::System::getLocalTime();

		while (items.size() > 0)
		{
			Item& item = items.front();

			if (time >= item.time)
			{
				try
				{
					item.func();
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_WARNING, e);
				}

				items.pop_front();
			}
			else
			{
				break;
			}
		}
	}

	void TimerService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Heartbeat>::disconnect(runService, this);
		runService = shared_from(ServiceProvider::create<RunService>(newProvider));
		Notifier<RunService, Heartbeat>::connect(runService, this);
	}
}
