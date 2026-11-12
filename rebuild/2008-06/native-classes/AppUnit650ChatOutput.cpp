// 2008-06 native RBX::ChatLine constructor and ChatOutput::onEvent(ChatMessage), the ChatOutput half of the HUD unit in
// the application range 00650000..00654000 (inactive). Verified by tests/record_native_app_unit650.py (receipt
// app-unit650-working.json); needs /fp:fast like the owner's native-classes/ChatOutput.cpp.
//
// The classes are declared in the read-only native gui/ChatOutput.h (owner: ScoreHud / ChatOutput); the player-name
// hash stringHash 00669f60 is declared in the read-only native gui/ScoreHud.h.
//   ChatLine(Player*, const std::string&, float) 00650560: user (+0x0c) is default-constructed (std::string() import),
//     message (+0x28) copied, dieTime (+0x44), profane (+0x48) = false, then user = player->getName() (assign import
//     on Player +0x110); the colour comes from ServiceProvider::find<Teams> 0049ab50, Teams::isTeamGame 005d6070,
//     Player::neutral (+0x17c, read inline), Teams::getTeamFromPlayer 005d5ea0, Team::getTeamColor 00565e40 /
//     BrickColor::color3 005b6270, Color3::black 005149f0 / white 00514a60, or Color::colorFromIndex8 0064f830 of
//     stringHash(user) & 7.
//   ChatOutput::onEvent(const Players*, ChatMessage) 00650cc0 (NATIVE_APPUNIT650_PENDING) (Listener<Players, ChatMessage> slot 0, this = +0x144):
//     removeOldest 0064fd70 while fifo.size() (+0x190) > GameSettings::singleton() 0044bee0 chatScrollLength (+0x134);
//     a message starting with '/' goes to ParseCommand 00650660 first; then players (+0x150) localPlayer (+0x1a0)
//     superSafeChat (+0x1b1), ProfanityFilter::ContainsProfanity 0066a350 on filter (+0x154), new ChatLine (0x4c) with
//     dieTime = time (+0x194) + 60.0f (0083792c), profane = false, fifo.push_back.
#include "gui/ChatOutput.h"
#include "gui/ScoreHud.h"
#include "Network/Player.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/GameSettings.h"
#include "v8tree/Service.h"
#include "util/Color.h"

namespace RBX
{
	ChatLine::ChatLine(Network::Player* player, const std::string& text, float expiry)
		: message(text),
		  dieTime(expiry),
		  profane(false)
	{
		user = player->getName();
		Teams* teams = ServiceProvider::find<Teams>(player);
		if (teams && teams->isTeamGame())
		{
			if (!player->getNeutral())
			{
				if (Team* team = teams->getTeamFromPlayer(player))
					userColor = team->getTeamColor().color3();
				else
					userColor = G3D::Color3::black();
			}
			else
				userColor = G3D::Color3::white();
		}
		else
			userColor = Color::colorFromIndex8(stringHash(user) % 8);
	}

#ifdef NATIVE_APPUNIT650_PENDING
	// Needs Player::getSuperSafeChat() const { return superSafeChat; } inline in native Network/Player.h (proposal:
	// the original reads Player +0x1b1 directly at 00650d65; no out-of-line getter exists).
	void ChatOutput::onEvent(const Network::Players*, Network::ChatMessage event)
	{
		while (fifo.size() > (size_t)GameSettings::singleton().chatScrollLength)
			removeOldest();

		if (event.message.size() > 0 && event.message[0] == '/')
		{
			if (ParseCommand(event) == true)   // cmp al, 1 at 00650d50 (not test al, al)
				return;
		}

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
#endif
}
