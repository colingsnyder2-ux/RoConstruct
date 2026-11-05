// from server: 100% by EspClaude
// from server: 98% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_80e8df6c7fd397c0.cpp

// Candidate translation unit (score above; library headers required).
#include <queue>
#include "v8tree/Instance.h"
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"

static void cleanup(boost::weak_ptr<RBX::Instance> item)
{
	try
	{
		boost::shared_ptr<RBX::Instance> i = item.lock();
		if (i)
			i->setParent(NULL);
	}
	catch (std::exception& e)
	{
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, e);
	}
}

namespace RBX
{
	class DebrisService
	{
		char exePad2009[0x8c];
		std::queue<boost::weak_ptr<Instance>> queue;
		int maxItems;
		TimerService* timer;
	public:
		void addItem(boost::shared_ptr<Instance> item, double lifetime);
	private:
		void cleanup();
	};

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
}
