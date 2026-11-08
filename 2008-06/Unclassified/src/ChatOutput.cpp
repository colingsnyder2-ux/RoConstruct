// 2008-06 native RBX::ChatOutput unit (inactive): 0064fb60..00651000.
// Layout and addresses in native-headers/gui/ChatOutput.h; verified by tests/record_native_hud.py.
// >>> native-status (generated) -- do not edit >>>
// ChatOutput | 2008-06 | linked
// 5/5 exact by name (100%) | 5/5 exact bodies | no strings | verified 2026-11-07| by king_originala (+3) (mixed 4)
// <<< native-status | src ce3e090b | roc native-status --write
#include "gui/ChatOutput.h"

namespace RBX
{
	ChatOutput::ChatOutput()
		: runService(NULL),
		  players(NULL),
		  time(0.0f)
	{
	}

	void ChatOutput::removeOldest()
	{
		ChatLine* line = fifo.front();
		fifo.pop_front();
		delete line;
	}

	bool ChatOutput::frontIsOld()
	{
		if (fifo.empty())
			return false;
		ChatLine* line = fifo.front();
		return line->dieTime < time;
	}

	void ChatOutput::onEvent(const RunService*, Heartbeat event)
	{
		time += event.step;
		while (frontIsOld())
			removeOldest();
	}

	ChatOutput::~ChatOutput()
	{
		while (!fifo.empty())
			removeOldest();
	}

	void ChatOutput::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Heartbeat>::disconnect(runService, this);
		Notifier<Network::Players, Network::ChatMessage>::disconnect(players, this);

		runService = ServiceProvider::create<RunService>(newProvider);
		players = ServiceProvider::create<Network::Players>(newProvider);

		Notifier<RunService, Heartbeat>::connect(runService, this);
		Notifier<Network::Players, Network::ChatMessage>::connect(players, this);
	}
}
