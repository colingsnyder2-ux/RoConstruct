// =============================================================================
// Team.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Team.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Team.h"
#include "v8datamodel/Teams.h"

namespace RBX
{
	const char sTeam[] = "Team"; // 0082e8e8 (pushed by doDeclare<sTeam> 004067e0 and classDescriptor 005661b0)

	// Template members the shared headers only declare (same definitions as DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	static Reflection::PropDescriptor<Team, int> prop_Score(
		"Score",
		"Data",
		&Team::getScore,
		&Team::setScore,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Team, BrickColor> prop_Color(
		"TeamColor",
		"Data",
		&Team::getTeamColor,
		&Team::setTeamColor,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Team, bool> prop_AutoAssignable(
		"AutoAssignable",
		"Data",
		&Team::getAutoAssignable,
		&Team::setAutoAssignable,
		Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<bool, 1> Team::prop_AutoColorCharacters(
		"AutoColorCharacters",
		"Data",
		&Team::autoColorCharacters,
		Reflection::PropertyDescriptor::STANDARD);

	Team::Team()
		: score(0),
		  autoAssignable(true),
		  autoColorCharacters(true)
	{
		setName(sTeam);
		color = BrickColor::lego_1;
	}

	bool Team::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const Teams*>(instance) != 0;
	}

	int Team::getScore() const
	{
		return score;
	}

	void Team::setScore(int newScore)
	{
		if (score != newScore)
		{
			score = newScore;
			raisePropertyChanged(prop_Score);
		}
	}

	BrickColor Team::getTeamColor() const
	{
		return color;
	}

	void Team::setTeamColor(BrickColor newColor)
	{
		if (color != newColor)
		{
			color = newColor;
			raisePropertyChanged(prop_Color);
		}
	}

	bool Team::getAutoAssignable() const
	{
		return autoAssignable;
	}

	void Team::setAutoAssignable(bool value)
	{
		if (autoAssignable != value)
		{
			autoAssignable = value;
			raisePropertyChanged(prop_AutoAssignable);
		}
	}
}

template void RBX::Name::callDoDeclare<RBX::sTeam>();
