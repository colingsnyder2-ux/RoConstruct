// from server: 49% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Network/Player.cpp

// Candidate translation unit (score above; library headers required).
#include "network/Player.h"

#include "reflection/property.h"

namespace RBX {
namespace Network {

char sPlayer[] = "Player";

static Reflection::PropDescriptor<Player, BrickColor> prop_teamColor(
	"TeamColor",
	"Team",
	&RBX::Network::Player::getTeamColor,
	&RBX::Network::Player::setTeamColor
);

static Reflection::PropDescriptor<Player, bool> prop_neutral(
	"Neutral",
	"Team",
	&RBX::Network::Player::getNeutral,
	&RBX::Network::Player::setNeutral
);

// FUNCTION: WEBSERVICE 0x1018f9c0
void Player::setTeamColor(BrickColor value)
{
	if (value.number != teamColor.number) {
		teamColor = value;
		raisePropertyChanged(prop_teamColor);
	}
}

// FUNCTION: WEBSERVICE 0x1018f9f0
void Player::setNeutral(bool value)
{
	if (value != neutral) {
		neutral = value;
		raisePropertyChanged(prop_neutral);
	}
}

} // namespace Network
} // namespace RBX
