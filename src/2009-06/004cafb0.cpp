// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_903afbda57333c47.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("Network/Player.h","roc_unit_1cb1f788b2f04b82.cpp")
#pragma include_alias("util/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#include "Network/Players.h"
#include "Network/Player.h"
namespace RBX { namespace Network {
Player* Players::getPlayerFromCharacter(Instance* character)
		{
			Players* players = ServiceProvider::find<Players>(character);
			if (players)
			{
				const boost::shared_ptr<Instance> found = players->playerFromCharacter(shared_from(character));
				return static_cast<Player*>(found.get());
			}
			else
			{
				return NULL;
			}
		}
}}
