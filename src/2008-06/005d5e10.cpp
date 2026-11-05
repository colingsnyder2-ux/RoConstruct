// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_1e49fe32c2e377dc.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/Teams.h"
namespace RBX {

	Teams::Teams()
		: teams(std::vector<boost::shared_ptr<Instance>>())
	{
		setName("Teams");
	}

	Teams::~Teams()
	{
	}
	
	bool Teams::teamExists(BrickColor brickColor)
	{
		return getTeamFromTeamColor(brickColor) != NULL;
	}

	Team* Teams::getTeamFromTeamColor(BrickColor brickColor)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			Team* team = dynamic_cast<Team*>(getChild(i));
			if (team && team->getTeamColor() == brickColor)
				return team;
		}
		
		return NULL;
	}

	void Teams::onChildAdded(Instance* child)
	{
		if (dynamic_cast<Team*>(child))
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>>& myTeams = teams.write();
			myTeams->push_back(shared_from(child));
		}
	}

	void Teams::onChildRemoving(Instance* child)
	{
		if (dynamic_cast<Team*>(child))
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>>& myTeams = teams.write();
			myTeams->erase(std::find(myTeams->begin(), myTeams->end(), shared_from(child)));
		}
	}

	void Teams::rebalanceTeams()
	{
		return;
	}
}