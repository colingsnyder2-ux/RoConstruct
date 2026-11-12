#include "gui/ChatOutput.h"

// PORT: 2008 MSVC build uses original API; no modern-compiler compatibility prelude.
#include "network/Player.h"
#include "network/Players.h"
#include "util/Color.h"
#include "util/Hash.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/SafeChat.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Teams.h"
#include "v8tree/Service.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <vector>

namespace RBX {

// FUNCTION: ROBLOX 0x00658530
ChatLine::~ChatLine()
{
}

// FUNCTION: ROBLOX 0x006587e0
ChatOutput::ChatOutput() : runService(NULL), players(NULL), time(0)
{
}

// FUNCTION: ROBLOX 0x00658960
void ChatOutput::removeOldest()
{
	ChatLine* line = fifo.front();
	fifo.pop_front();
	delete line;
}

bool ChatOutput::frontIsOld()
{
	return !fifo.empty() && fifo.front()->dieTime < time;
}

// FUNCTION: ROBLOX 0x00658a10
void ChatOutput::onEvent(const RunService* source, Heartbeat event)
{
	time += event.step;

	while (frontIsOld()) {
		removeOldest();
	}
}

// FUNCTION: ROBLOX 0x00658b10
ChatOutput::~ChatOutput()
{
	while (!fifo.empty()) {
		removeOldest();
	}
}

// STUB: ROBLOX 0x00658c00
void ChatOutput::render2d(Adorn* adorn)
{
	Rect rect = getMyRect();
	G3D::Vector2 pos(rect.low.x, rect.low.y - fifo.size() * 12);

	for (size_t i = 0; i < fifo.size(); i++) {
		std::string user = fifo[i]->user + "; ";
		G3D::Vector2 userSize = adorn->get2DStringBounds(user, 12, Adorn::PROPORTIONAL_SPACING);
		G3D::Vector2 messageSize = adorn->get2DStringBounds(fifo[i]->message, 12, Adorn::PROPORTIONAL_SPACING);
		float userWidth = std::max(userSize.x + 4, 20.0f);

		adorn->rect2d(
			G3D::Rect2D::xyxy(
				G3D::Vector2(pos.x - 2, pos.y + 1),
				G3D::Vector2(pos.x + userWidth + messageSize.x + 2, pos.y + userSize.y - 1)
			),
			translucentBackdrop()
		);

		G3D::Color3 messageColor = G3D::Color3::white();
		if (fifo[i]->profane) {
			messageColor = G3D::Color3::red();
		}

		adorn->drawFont2D(
			user,
			pos,
			12,
			G3D::Color4(fifo[i]->userColor),
			G3D::Color4::clear(),
			Adorn::XALIGN_LEFT,
			Adorn::YALIGN_TOP,
			Adorn::PROPORTIONAL_SPACING
		);
		adorn->drawFont2D(
			fifo[i]->message,
			G3D::Vector2(pos.x + userWidth, pos.y),
			12,
			G3D::Color4(messageColor),
			G3D::Color4::clear(),
			Adorn::XALIGN_LEFT,
			Adorn::YALIGN_TOP,
			Adorn::PROPORTIONAL_SPACING
		);

		pos.y += 14;
	}
}

// FUNCTION: ROBLOX 0x00659440
ChatLine::ChatLine(Network::Player* p_unk0x04, const std::string& p_unk0x08, float p_unk0x0c)
	: message(p_unk0x08), dieTime(p_unk0x0c), profane(false)
{
	user = p_unk0x04->getName();

	Teams* teams = ServiceProvider::find<Teams>(p_unk0x04);

	if (teams && teams->isTeamGame()) {
		if (!p_unk0x04->getNeutral()) {
			Team* team = teams->getTeamFromPlayer(p_unk0x04);

			if (team) {
				userColor = team->getTeamColor().color3();
			}
			else {
				userColor = G3D::Color3::black();
			}
		}
		else {
			userColor = G3D::Color3::white();
		}
	}
	else {
		userColor = Color::colorFromIndex8(Hash::hash(user) & 7);
	}
}

// FUNCTION: ROBLOX 0x00659540
bool ChatOutput::ParseCommand(Network::ChatMessage p_unk0x04)
{
	std::vector<std::string> tokens;
	boost::char_separator<char> sep(" -_/,");
	boost::tokenizer<boost::char_separator<char> > tok(p_unk0x04.message, sep);

	for (boost::tokenizer<boost::char_separator<char> >::iterator it = tok.begin(); it != tok.end(); ++it) {
		tokens.push_back(*it);
	}

	if (tokens.size() == 0) {
		return false;
	}

	boost::to_lower(tokens[0]);

	if (tokens[0] == "sc") {
		std::string message = SafeChat::singleton().getMessage(tokens);
		fifo.push_back(new ChatLine(p_unk0x04.source.get(), message, time + 60));
		return true;
	}

	return false;
}

// FUNCTION: ROBLOX 0x00659ac0
void ChatOutput::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	stopListening<RunService, Heartbeat>(runService, this);
	stopListening<Network::Players, Network::ChatMessage>(players, this);

	GuiItem::onServiceProvider(oldProvider, newProvider);

	runService = newProvider ? newProvider->create<RunService>() : NULL;
	players = newProvider ? newProvider->create<Network::Players>() : NULL;

	startListening<RunService, Heartbeat>(runService, this);
	startListening<Network::Players, Network::ChatMessage>(players, this);
}

// FUNCTION: ROBLOX 0x00659b90
void ChatOutput::onEvent(const Network::Players* source, Network::ChatMessage event)
{
	while (fifo.size() > GameSettings::singleton().chatScrollLength) {
		removeOldest();
	}

	if (event.message.size() > 0 && event.message[0] == '/') {
		if (ParseCommand(event) == true) {
			return;
		}
	}

	Network::Player* localPlayer = players->getLocalPlayer();

	if (localPlayer && localPlayer->getSuperSafeChat()) {
		return;
	}

	bool profane = filter.ContainsProfanity(event.message);

	if (localPlayer && event.source.get() != localPlayer && profane) {
		return;
	}

	ChatLine* line = new ChatLine(event.source.get(), event.message, time + 60);
	line->profane = false;
	fifo.push_back(line);
}

} // namespace RBX
