// =============================================================================
// TimerService.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/TimerService.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::TimerService::Item> >;
template class std::allocator<RBX::TimerService::Item>;
template class std::allocator<std::_List_nod<RBX::TimerService::Item,std::allocator<RBX::TimerService::Item> >::_Node *>;

template void RBX::Name::callDoDeclare<RBX::sTimerService>();
