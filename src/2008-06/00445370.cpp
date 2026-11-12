// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Team.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Team.h"

#include "reflection/property.h"

namespace RBX {

const char sTeam[] = "Team";

using namespace Reflection;

static PropDescriptor<Team, int> prop_Score("Score", "Data", &Team::getScore, &Team::setScore);

static PropDescriptor<Team, BrickColor> prop_Color("TeamColor", "Data", &Team::getTeamColor, &Team::setTeamColor);

static PropDescriptor<Team, bool> prop_AutoAssignable(
	"AutoAssignable", "Data", &Team::getAutoAssignable, &Team::setAutoAssignable
);

Reflection::BoundProp<bool, 1> Team::prop_AutoColorCharacters(
	"AutoColorCharacters", "Data", &Team::autoColorCharacters
);

// FUNCTION: WEBSERVICE 0x10068b70 FOLDED
int Team::getScore() const
{
	return score;
}

// FUNCTION: WEBSERVICE 0x100bded0
// FUNCTION: ROBLOX 0x0058b480
BrickColor Team::getTeamColor() const
{
	return color;
}

// FUNCTION: WEBSERVICE 0x100bdee0
// FUNCTION: ROBLOX 0x0058b490
bool Team::getAutoAssignable() const
{
	return autoAssignable;
}

// FUNCTION: WEBSERVICE 0x100be010
// FUNCTION: ROBLOX 0x0058b620
Team::~Team()
{
}

// FUNCTION: WEBSERVICE 0x100be630
// FUNCTION: ROBLOX 0x0058bc20
Team::Team() : score(0), autoAssignable(true), autoColorCharacters(true)
{
	setName(sTeam);
	color = BrickColor::legoWhite();
}

// FUNCTION: WEBSERVICE 0x100be710
void Team::setScore(int score)
{
	this->score = score;
	raisePropertyChanged(prop_Score);
}

// FUNCTION: WEBSERVICE 0x100be730
// FUNCTION: ROBLOX 0x0058bd20
void Team::setTeamColor(BrickColor color)
{
	this->color = color;
	raisePropertyChanged(prop_Color);
}

// FUNCTION: WEBSERVICE 0x100be750
void Team::setAutoAssignable(bool autoAssign)
{
	autoAssignable = autoAssign;
	raisePropertyChanged(prop_AutoAssignable);
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Team, RBX::Instance, RBX::sTeam>;
template class RBX::Reflection::
	Described<RBX::Team, RBX::sTeam, RBX::FactoryProduct<RBX::Team, RBX::Instance, RBX::sTeam> >;
template class RBX::DescribedCreatable<RBX::Team, RBX::Instance, RBX::sTeam>;
