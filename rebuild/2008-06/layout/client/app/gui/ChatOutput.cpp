#include "gui/ChatOutput.h"
#include "v8datamodel/SafeChat.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>

namespace RBX
{
	void ChatOutput::render2d(Adorn* adorn)
	{
		Rect rect = getMyRect();
		G3D::Vector2 position = rect.low;
		position.y -= fifo.size() * 12;

		for (size_t i = 0; i < fifo.size(); ++i)
		{
			std::string user = fifo[i]->user + "; ";
			G3D::Vector2 userSize = adorn->get2DStringBounds(user, 12, Adorn::PROPORTIONAL_SPACING);
			G3D::Vector2 messageSize = adorn->get2DStringBounds(fifo[i]->message, 12, Adorn::PROPORTIONAL_SPACING);
			float width = std::max(userSize.x + 4.0f, 20.0f);

			G3D::Rect2D backdrop = G3D::Rect2D::xyxy(G3D::Vector2(position.x - 2.0f, position.y + 1.0f),
													  G3D::Vector2(width + messageSize.x + position.x + 2.0f, position.y + userSize.y - 1.0f));
			adorn->rect2d(backdrop, GuiItem::translucentBackdrop());

			G3D::Color3 messageColor = G3D::Color3::white();
			if (fifo[i]->profane)
				messageColor = G3D::Color3::red();

			adorn->drawFont2D(user, position, 12, G3D::Color4(fifo[i]->userColor, 1.0f), G3D::Color4::clear(),
							  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			adorn->drawFont2D(fifo[i]->message, G3D::Vector2(position.x + width, position.y), 12,
							  G3D::Color4(messageColor, 1.0f), G3D::Color4::clear(), Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP,
							  Adorn::PROPORTIONAL_SPACING);

			position.y += 14.0f;
		}
	}

	bool ChatOutput::ParseCommand(Network::ChatMessage chat)
	{
		std::vector<std::string> parts;
		boost::char_separator<char> separator(" -_/,");
		boost::tokenizer<boost::char_separator<char> > tokens(chat.message, separator);
		for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it)
			parts.push_back(*it);

		if (parts.size() == 0)
			return false;

		boost::algorithm::to_lower(parts[0]);
		if (parts[0] == "sc")
		{
			std::string message = SafeChat::singleton().getMessage(parts);
			ChatLine* line = new ChatLine(chat.source.get(), message, time + 60.0f);
			fifo.push_back(line);
			return true;
		}

		return false;
	}
}

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

namespace RBX {
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
}
