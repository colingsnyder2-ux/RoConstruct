// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_0eb7290d46cd81a9.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#include "v8datamodel/Team.h"

namespace RBX
{
	const char* sTeam = "Team";

	static Reflection::PropDescriptor<Team, int> prop_Score("Score", "Data", &Team::getScore, &Team::setScore, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Team, BrickColor> prop_Color("TeamColor", "Data", &Team::getTeamColor, &Team::setTeamColor, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Team, bool> prop_AutoAssignable("AutoAssignable", "Data", &Team::getAutoAssignable, &Team::setAutoAssignable, Reflection::PropertyDescriptor::STANDARD);

	Team::Team()
		: score(0),
		  autoAssignable(true),
		  autoColorCharacters(true)
	{
		setName("Team");
		color = BrickColor::lego_1;
	}

	int Team::getScore() const
	{
		return score;
	}

	void Team::setScore(int newScore)
	{
		score = newScore;
		raisePropertyChanged(prop_Score);
	}

	BrickColor Team::getTeamColor() const
	{
		return color;
	}

	void Team::setTeamColor(BrickColor newColor)
	{
		color = newColor;
		raisePropertyChanged(prop_Color);
	}

	bool Team::getAutoAssignable() const
	{
		return autoAssignable;
	}

	void Team::setAutoAssignable(bool value)
	{
		autoAssignable = value;
		raisePropertyChanged(prop_AutoAssignable);
	}
}
