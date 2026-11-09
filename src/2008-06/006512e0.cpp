// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_72a4aa186f2a5f36.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#undef _RELEASEASSERT
#include "gui/ScoreHud.h"
#include "Network/Players.h"

namespace RBX
{
	// 2008-06 layouts from the target: ScoreHud::players at +0x150, Player::neutral at +0x17c.
	struct ScoreHud2008View { char prefix[0x150]; Network::Players* players; };
	struct Player2008View { char prefix[0x17c]; bool neutral; };

	ScoreHud::BoardType ScoreHud::DetermineBoardType()
	{
		BoardType board = PLAYER_LIST;

		bool hasStats = false;
		bool hasTeams = false;

		Network::Players* players = ((ScoreHud2008View*)this)->players;
		if (players)
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> playerList = players->getPlayers();

			for (size_t i = 0; i < playerList->size(); ++i)
			{
				Network::Player* player = static_cast<Network::Player*>(playerList->at(i).get());

				if (player->findFirstChildByName("leaderstats"))
					hasStats = true;
				if (!((Player2008View*)player)->neutral)
					hasTeams = true;
			}
		}

		if (hasStats)
			board = FFA;
		if (hasTeams)
			board = TEAM_LIST;
		if (hasStats && hasTeams)
			board = TEAM_DEATHMATCH;

		return board;
	}
}
