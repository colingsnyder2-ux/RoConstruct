// from server: 100% by EspClaude
// from server: 51% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_3e35018f5802168d.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _MT
#define _MT
#endif
#ifndef _DLL
#define _DLL
#endif
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"

namespace RBX
{
	TimerService::TimerService() {}

	void TimerService::delay(boost::function0<void> func, double seconds)
	{
		Item item;
		item.time = G3D::System::getLocalTime() + seconds;
		item.func = func;

		std::list<Item>::iterator pos = items.end();

		std::list<Item>::reverse_iterator iter = items.rbegin();
		std::list<Item>::reverse_iterator end = items.rend();

		for (; iter != end; iter++)
		{
			if (iter->time > item.time)
				pos = iter.base();
			else
				break;
		}

		items.insert(pos, item);
	}

	void TimerService::onEvent(const RunService* source, Heartbeat event)
	{
		G3D::RealTime time = G3D::System::getLocalTime();

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

		Instance::onServiceProvider(oldProvider, newProvider);
		runService = shared_from(ServiceProvider::create<RunService>(newProvider));

		Notifier<RunService,Heartbeat>::connect(runService, this);
	}
}

#include <map>
#include <string>
#include <utility>
#include <boost/shared_ptr.hpp>

namespace RBX
{
	// key layout read off the pair copy at 0x545cc0: std::string at +0, 4-byte field at +0x1c;
	// operator[] compares only the string (single MSVCP80 operator< call)
	struct MapKey0548310 : public std::string
	{
		int n;
	};
	// mapped type: 16 bytes, zeroed, two shared_ptrs released at +0xc then +4 (0x52ce80)
	typedef std::pair<boost::shared_ptr<int>, boost::shared_ptr<int> > MapVal0548310;
}
template class std::map<RBX::MapKey0548310, RBX::MapVal0548310>;
