// 2008-06 native RBX::ChatOutput unit (inactive): 0064fb60..00651000.
// Layout and addresses in native-headers/gui/ChatOutput.h; verified by tests/record_native_hud.py.
#include "gui/ChatOutput.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Team.h"
#include "util/Color.h"

namespace RBX
{
	// Original 00669f60, decorated identity in the registry.
	unsigned int stringHash(const std::string&);

	// 00650560: retain the sender's name, team color (or deterministic name color), and expiry.
	ChatLine::ChatLine(Network::Player* player, const std::string& text, float expiry)
		: message(text), dieTime(expiry), profane(false)
	{
		user = player->getName();
		Teams* teams = ServiceProvider::find<Teams>(player);
		if (teams && teams->isTeamGame()) {
			if (!player->getNeutral()) {
				Team* team = teams->getTeamFromPlayer(player);
				userColor = team ? team->getTeamColor().color3() : G3D::Color3::black();
			} else
				userColor = G3D::Color3::white();
		} else
			userColor = Color::colorFromIndex8(stringHash(user) % 8);
	}

	// 00650cc0: original Listener<Players, ChatMessage> receiver, message filtering and queue insertion.
	void ChatOutput::onEvent(const Network::Players*, Network::ChatMessage event)
	{
		while (fifo.size() > GameSettings::singleton().chatScrollLength)
			removeOldest();
		if (event.message.size() > 0 && event.message[0] == '/' && ParseCommand(event) == true)
			return;
		Network::Player* localPlayer = players->getLocalPlayer();
		if (localPlayer && localPlayer->getSuperSafeChat())
			return;
		bool profane = filter.ContainsProfanity(event.message);
		if (localPlayer && event.source.get() != localPlayer && profane)
			return;
		ChatLine* line = new ChatLine(event.source.get(), event.message, time + 60.0f);
		line->profane = false;
		fifo.push_back(line);
	}

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
