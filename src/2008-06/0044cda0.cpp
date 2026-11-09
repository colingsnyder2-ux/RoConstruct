// from server: 71% by colin
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

static PropDescriptor<Team, int> prop_Score("Score", "Data", &RBX::Team::getScore, &RBX::Team::setScore);

static PropDescriptor<Team, BrickColor> prop_Color(
	"TeamColor",
	"Data",
	&RBX::Team::getTeamColor,
	&RBX::Team::setTeamColor
);

static PropDescriptor<Team, bool> prop_AutoAssignable(
	"AutoAssignable",
	"Data",
	&RBX::Team::getAutoAssignable,
	&RBX::Team::setAutoAssignable
);

// FUNCTION: WEBSERVICE 0x100be710
void Team::setScore(int score)
{
	this->score = score;
	raisePropertyChanged(prop_Score);
}

// FUNCTION: WEBSERVICE 0x100be730
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
