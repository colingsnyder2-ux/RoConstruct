// 2008-06 native RBX::ScoreHud unit (inactive): 00650f80..00656488.
// Layout and addresses in native-headers/gui/ScoreHud.h; verified by tests/record_native_hud.py.
#include "gui/ScoreHud.h"
#include "v8tree/Service.h"
#include "v8tree/InstanceEvents.h"
#include "Network/Players.h"
#include "Network/Player.h"

namespace RBX
{
	ScoreHud::~ScoreHud()
	{
	}

#ifdef NATIVE_SCOREHUD_PENDING
	void ScoreHud::onEvent(const Instance*, ChildRemoved)
	{
	}
#endif

	void ScoreHud::onEvent(const Instance*, ChildAdded)
	{
	}

	ScoreHud::ScoreHud(const ServiceProvider* serviceProvider)
		: runService(NULL),
		  players(NULL)
	{
		runService = ServiceProvider::find<RunService>(serviceProvider);
		players = ServiceProvider::find<Network::Players>(serviceProvider);
	}

	void ScoreHud::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		runService = ServiceProvider::find<RunService>(newProvider);
		players = ServiceProvider::find<Network::Players>(newProvider);
	}

	ScoreHud::BoardType ScoreHud::DetermineBoardType()
	{
		BoardType type = PLAYER_LIST;
		bool hasStats = false;
		bool hasTeams = false;
		if (players)
		{
			{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = players->getPlayers();
			for (size_t i = 0; i < list->size(); ++i)
			{
				Network::Player* player = static_cast<Network::Player*>(list->at(i).get());
				if (player->findFirstChildByName("leaderstats"))
					hasStats = true;
				if (!player->getNeutral())
					hasTeams = true;
			}
			}
			if (hasStats)
				type = FFA;
			if (hasTeams)
				type = TEAM_LIST;
			if (hasStats && hasTeams)
				type = TEAM_DEATHMATCH;
		}
		return type;
	}

	void ScoreHud::render2d(Adorn* adorn)
	{
		switch (DetermineBoardType())
		{
		case PLAYER_LIST:
			renderFFALeaderboard(adorn);
			break;
		case TEAM_DEATHMATCH:
			renderTeamDeathmatchLeaderboard(adorn, TEAM_DEATHMATCH);
			break;
		case TEAM_LIST:
			renderTeamDeathmatchLeaderboard(adorn, TEAM_LIST);
			break;
		case FFA:
			renderFFALeaderboard(adorn);
			break;
		}
	}
}
