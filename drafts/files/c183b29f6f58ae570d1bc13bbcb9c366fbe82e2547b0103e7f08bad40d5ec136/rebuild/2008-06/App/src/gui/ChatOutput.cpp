// 2008-06 native RBX::ChatOutput unit (inactive): 0064fb60..00651000.
// Layout and addresses in native-headers/gui/ChatOutput.h; verified by tests/record_native_hud.py.
#include "gui/ChatOutput.h"
#include "Network/Player.h"
#include "v8datamodel/GameSettings.h"

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

namespace RBX {
void ChatOutput::onEvent(const Network::Players*, Network::ChatMessage message)
{
    unsigned int current = fifo.size();
    while (current > static_cast<unsigned int>(GameSettings::singleton().chatScrollLength)) {
        removeOldest();
        current = fifo.size();
    }
    if (message.message.size() > 0) {
        const char* text = message.message.c_str();
        if (text[0] == '/') {
            if (ParseCommand(message) == true) return;
        }
    }
    Network::Player* player = players->getLocalPlayer();
    if (!player || !player->getSuperSafeChat()) {
        bool profane = filter.ContainsProfanity(message.message);
        if (!player || message.source.get() == player || !profane) {
            // INFERRED: original 00650db6 adds the float at 0083792c.
            ChatLine* line = new ChatLine(message.source.get(), message.message, time + 20.0f);
            line->profane = false;
            fifo.push_back(line);
        }
    }
}
}
