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

// PORT: selective unit; remaining functions use the 2008 object.

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

} // namespace RBX
