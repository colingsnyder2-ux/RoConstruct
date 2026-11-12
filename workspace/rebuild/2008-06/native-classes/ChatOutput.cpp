// 2008-06 native RBX::ChatOutput unit (inactive): 0064fb60..00651000.
// Layout and addresses in native-headers/gui/ChatOutput.h; verified by tests/record_native_hud.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ChatOutput | 2008-06 | 5 byte-exact, inactive (not link-selected)
// 5/6 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (+3) (mixed 4)
// <<< native-status | src a96ac092 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::ChatLine *> >;
template class std::_Deque_const_iterator<RBX::ChatLine *,std::allocator<RBX::ChatLine *>,1>;
template class std::_Deque_iterator<RBX::ChatLine *,std::allocator<RBX::ChatLine *>,1>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *,std::allocator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *,std::allocator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *> >;
template class std::deque<RBX::ChatLine *,std::allocator<RBX::ChatLine *> >;
template class std::vector<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *,std::allocator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *> >;

#include "v8datamodel/GameSettings.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Team.h"
#include "util/Color.h"
namespace RBX {
unsigned int stringHash(const std::string&);
}
namespace RBX {
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
}
