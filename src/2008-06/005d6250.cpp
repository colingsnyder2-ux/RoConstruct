// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_51324fc73e5a38ba.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_a8aed7660be8b02c.cpp")
#include "v8datamodel/Teams.h"
namespace RBX { namespace Network {
// Opaque receiver view; method declarations copied from native Network/Player.h.
class Player { public: void setTeamColor(BrickColor value); void setNeutral(bool value); };
}
void Teams::assignNewPlayerToTeam(Network::Player* player)
	{
		BrickColor best = BrickColor::lego_28;
		int best_count = 10000;
		bool found = false;

		for (size_t i = 0; i < numChildren(); i++)
		{
			Team* team = dynamic_cast<Team*>(getChild(i));
			if (team && team->getAutoAssignable() == true)
			{
				int count = getNumPlayersInTeam(team->getTeamColor());

				if (count < best_count)
				{
					best = team->getTeamColor();
					best_count = count;
					found = true;
				}
			}
		}
		
		if (found)
		{
			player->setTeamColor(best);
			player->setNeutral(false);
		}
	}

	
}
