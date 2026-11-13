#include "gui/ScoreHud.h"

#include "network/Player.h"
#include "network/Players.h"
#include "rbxgraphics/Adorn.h"
#include "util/Color.h"
#include "util/Hash.h"
#include "util/Rect.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Value.h"
#include "v8tree/Service.h"

#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <map>

namespace RBX {

// PORT: complete 2008 forward declaration with authentic donor BoardData declaration.
class BoardData
{
public:
	BoardData() {}

	void SetSize(int rows, int columns);
	void AddField(std::string field, int index);

	std::vector<std::vector<std::string> > data; // 0x00
	std::vector<std::string> fields;             // 0x10

	// SYNTHETIC: ROBLOX 0x0065cd90
	// RBX::BoardData::~BoardData
};

// SIZE 0x38
class LeaderboardData
{
public:
	LeaderboardData(Instance* context);

	void CompileData();

	std::vector<std::string> statNamesList;                       // 0x00
	std::map<Team*, std::vector<std::string> > playersByTeamList; // 0x10
	std::map<std::string, std::map<std::string, int> > statMap;   // 0x1c
	std::map<Team*, std::map<std::string, int> > teamTotals;      // 0x28

private:
	Instance* context; // 0x34

	void AddTuple(std::string playerName, Team* team, std::string statName, int value);
};

// PORT: omit donor-only size annotation.
// FUNCTION: ROBLOX 0x00659e80
void BoardData::AddField(std::string field, int index)
{
	fields[index] = field;
}

// FUNCTION: ROBLOX 0x00659f10
ScoreHud::~ScoreHud()
{
}

// FUNCTION: ROBLOX 0x0065a0e0 FOLDED
void ScoreHud::onEvent(const Instance* source, ChildRemoved event)
{
}

// FUNCTION: ROBLOX 0x0065a0e0 FOLDED
void ScoreHud::onEvent(const Instance* source, ChildAdded event)
{
}

// STUB: ROBLOX 0x0065a160
ScoreHud::BoardType ScoreHud::DetermineBoardType()
{
	BoardType boardType = PLAYER_LIST;
	bool hasStats = false;
	bool hasTeams = false;

	if (players != NULL) {
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = players->getPlayers();

			for (unsigned int i = 0; list->size() > i; ++i) {
				Network::Player* player = static_cast<Network::Player*>((list->begin() + i)->get());

				Instance* stats = player->findFirstChildByName("leaderstats");
				if (stats != NULL) {
					hasStats = true;
				}

				if (!player->getNeutral()) {
					hasTeams = true;
				}
			}
		}

		if (hasStats) {
			boardType = FFA;
		}

		if (hasTeams) {
			boardType = TEAM_LIST;
		}

		if (hasStats && hasTeams) {
			boardType = TEAM_DEATHMATCH;
		}
	}

	return boardType;
}

// FUNCTION: ROBLOX 0x0065b460
ScoreHud::ScoreHud(const ServiceProvider* serviceProvider) : runService(NULL), players(NULL)
{
	runService = serviceProvider ? serviceProvider->find<RunService>() : NULL;
	players = serviceProvider ? serviceProvider->find<Network::Players>() : NULL;
}

// FUNCTION: ROBLOX 0x0065b550
void ScoreHud::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	runService = newProvider ? newProvider->find<RunService>() : NULL;
	players = newProvider ? newProvider->find<Network::Players>() : NULL;
}

// FUNCTION: ROBLOX 0x0065d220
void BoardData::SetSize(int rows, int columns)
{
	data.resize(rows);

	for (int i = 0; i < rows; ++i) {
		data[i].resize(columns);
	}

	fields.resize(columns);
}

// FUNCTION: ROBLOX 0x0065d300
void LeaderboardData::AddTuple(std::string playerName, Team* team, std::string statName, int value)
{
	if (std::find(statNamesList.begin(), statNamesList.end(), statName) == statNamesList.end()) {
		statNamesList.push_back(statName);
	}

	if (std::find(playersByTeamList[team].begin(), playersByTeamList[team].end(), playerName) ==
		playersByTeamList[team].end()) {
		playersByTeamList[team].push_back(playerName);
	}

	statMap[playerName][statName] = value;
}

// STUB: ROBLOX 0x0065d480
void LeaderboardData::CompileData()
{
	Network::Players* players = ServiceProvider::find<Network::Players>(context);
	Teams* teams = ServiceProvider::create<Teams>(context);
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > teamList = teams->getTeams();
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > playerList = players->getPlayers();

	for (unsigned int i = 0; playerList->size() > i; ++i) {
		Network::Player* player = static_cast<Network::Player*>((playerList->begin() + i)->get());
		Team* team = teams->getTeamFromPlayer(player);
		playersByTeamList[team].push_back(player->getName());

		Instance* leaderstats = player->findFirstChildByName("leaderstats");
		if (leaderstats != NULL) {
			for (unsigned int j = 0; j < leaderstats->numChildren(); ++j) {
				Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */* stat = dynamic_cast<Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */*>(leaderstats->getChild(j));
				if (stat != NULL) {
					AddTuple(
						player->getName(),
						teams->getTeamFromPlayer(player),
						stat->getName(),
						Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value.getValue(stat)
					);
				}
			}
		}
	}

	if (teams != NULL) {
		for (unsigned int i = 0; i < teams->numChildren(); ++i) {
			Team* team = dynamic_cast<Team*>(teams->getChild(i));

			for (unsigned int j = 0; j < statNamesList.size(); ++j) {
				teamTotals[team][statNamesList[j]] = 0;

				for (unsigned int k = 0; k < playersByTeamList[team].size(); ++k) {
					int value = statMap[playersByTeamList[team][k]][statNamesList[j]];
					teamTotals[team][statNamesList[j]] += value;
				}
			}
		}
	}
}

// STUB: ROBLOX 0x0065d920
void ScoreHud::BuildBoardData(BoardData& boardData)
{
	if (players == NULL) {
		return;
	}

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = players->getPlayers();

	for (unsigned int i = 0; i < list->size(); ++i) {
		Network::Player* player = static_cast<Network::Player*>((list->begin() + i)->get());

		Instance* leaderstats = player->findFirstChildByName("leaderstats");
		if (leaderstats != NULL) {
			boardData.SetSize(list->size(), leaderstats->numChildren() + 1);
			boardData.AddField("Player", 0);

			for (unsigned int j = 0; j < leaderstats->numChildren(); ++j) {
				boardData.AddField(leaderstats->getChild(j)->getName(), j + 1);
			}

			boardData.data[i][0] = player->getName();

			for (unsigned int j = 0; j < leaderstats->numChildren(); ++j) {
				Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */* stat = dynamic_cast<Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */*>(leaderstats->getChild(j));
				boardData.data[i][j + 1] =
					boost::lexical_cast<std::string>(Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value.getValue(stat));
			}
		}
		else {
			boardData.SetSize(list->size(), 1);
			boardData.AddField("Player List", 0);
			boardData.data[i][0] = player->getName();
		}
	}

	for (unsigned int i = 0; i < list->size(); ++i) {
		if (boardData.data[i][0].size() > 16) {
			boardData.data[i][0].resize(16);
		}
	}
}

// STUB: ROBLOX 0x0065de40
void ScoreHud::renderFFALeaderboard(Adorn* adorn)
{
	bool showStats = true;
	BoardData boardData;
	BuildBoardData(boardData);

	if (boardData.fields.size() != 0) {
		if (boardData.fields.size() == 1) {
			showStats = false;
		}

		G3D::Rect2D viewport = adorn->getViewport();
		float width = viewport.width();
		float fontSize = 0.0009765625f * width * 14.0f;
		float boardWidth = width * 0.33f;
		if (!showStats) {
			boardWidth *= 0.5f;
		}

		setGuiSize(G3D::Vector2(boardWidth, ((float) boardData.data.size() + 2.5f) * fontSize));

		Rect rect = getMyRect();
		G3D::Rect2D rect2D = rect.toRect2D();
		adorn->rect2d(rect2D, GuiItem::translucentBackdrop());

		for (unsigned int i = 0; i < boardData.fields.size(); ++i) {
			G3D::Vector2 position(rect.low.x, rect.low.y);
			if (i != 0) {
				float half = (rect.high.x - rect.low.x) * 0.5f;
				position.x = (float) (i - 1) * (half / (float) boardData.fields.size()) + half + rect.low.x;
			}

			G3D::Color4 color(G3D::Color3::white(), 1.0f);
			adorn->drawFont2D(
				boardData.fields[i],
				position,
				fontSize,
				color,
				G3D::Color4::clear(),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_TOP,
				Adorn::PROPORTIONAL_SPACING
			);
		}

		rect.low.y += fontSize + fontSize;

		for (unsigned int i = 0; i < boardData.fields.size(); ++i) {
			for (unsigned int j = 0; j < boardData.data.size(); ++j) {
				G3D::Color3 color = G3D::Color3::white();
				if (i == 0) {
					color = Color::colorFromIndex8(Hash::hash(boardData.data[j][0]) & 7);
				}

				G3D::Vector2 position(rect.low.x, (float) j * fontSize + rect.low.y);
				if (i != 0) {
					float half = (rect.high.x - rect.low.x) * 0.5f;
					position.x = (float) (i - 1) * (half / (float) boardData.fields.size()) + half + rect.low.x;
				}

				adorn->drawFont2D(
					boardData.data[j][i],
					position,
					fontSize,
					G3D::Color4(color, 1.0f),
					G3D::Color4::clear(),
					Adorn::XALIGN_LEFT,
					Adorn::YALIGN_TOP,
					Adorn::PROPORTIONAL_SPACING
				);
			}
		}
	}
}

// FUNCTION: ROBLOX 0x0065e4c0
LeaderboardData::LeaderboardData(Instance* context) : context(context)
{
}

// STUB: ROBLOX 0x0065e590
void ScoreHud::renderTeamDeathmatchLeaderboard(Adorn* adorn, BoardType boardType)
{
	LeaderboardData leaderboardData(this);
	leaderboardData.CompileData();

	Teams* teams = ServiceProvider::find<Teams>(this);
	if (teams == NULL) {
		return;
	}

	G3D::Rect2D viewport = adorn->getViewport();
	float scale = viewport.width() * 0.0009765625f;
	float fontSize = 14.0f * scale;

	unsigned int rows;
	float width;
	if (boardType == TEAM_DEATHMATCH) {
		rows = players->numPlayers() + (teams->numChildren() + 1) * 3;
		width = 320.0f;
	}
	else {
		rows = teams->numChildren() * 3 + 2 + players->numPlayers();
		width = 240.0f;
	}

	setGuiSize(G3D::Vector2(scale * width, (float) rows * fontSize));

	Rect rect = getMyRect();
	G3D::Rect2D rect2D = rect.toRect2D();
	adorn->rect2d(rect2D, GuiItem::translucentBackdrop());

	if (boardType == TEAM_DEATHMATCH) {
		for (unsigned int i = 0; i < leaderboardData.statNamesList.size() + 1; ++i) {
			float rowWidth = rect.high.x - rect.low.x;
			G3D::Vector2 position(rect.low.x, rect.low.y);
			std::string label = "Team";

			if (i != 0) {
				float half = rowWidth * 0.5f;
				position.x =
					(float) (i - 1) * (half / (float) leaderboardData.statNamesList.size()) + half + position.x;
				label = leaderboardData.statNamesList[i - 1];
			}

			adorn->drawFont2D(
				label,
				position,
				fontSize,
				G3D::Color4(G3D::Color3::white(), 1.0f),
				G3D::Color4::clear(),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_TOP,
				Adorn::PROPORTIONAL_SPACING
			);
		}

		rect.low.y += fontSize;
	}

	for (unsigned int t = 0; t < teams->numChildren(); ++t) {
		Team* team = dynamic_cast<Team*>(teams->getChild(t));

		for (unsigned int i = 0; i < leaderboardData.statNamesList.size() + 1; ++i) {
			float rowWidth = rect.high.x - rect.low.x;
			G3D::Vector2 position(rect.low.x, rect.low.y);
			std::string label = team->getName();

			if (i != 0) {
				float half = rowWidth * 0.5f;
				position.x =
					(float) (i - 1) * (half / (float) leaderboardData.statNamesList.size()) + half + position.x;
				label = boost::lexical_cast<std::string>(
					leaderboardData.teamTotals[team][leaderboardData.statNamesList[i - 1]]
				);
			}

			adorn->drawFont2D(
				label,
				position,
				fontSize,
				G3D::Color4(team->getTeamColor().color3(), 1.0f),
				G3D::Color4(0.0f, 0.0f, 0.0f, 1.0f),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_TOP,
				Adorn::PROPORTIONAL_SPACING
			);
		}

		rect.low.y += fontSize;
		adorn->line2d(
			G3D::Vector2(rect.low.x + 2.0f, rect.low.y + 7.0f),
			G3D::Vector2(rect.high.x - 2.0f, rect.low.y + 7.0f),
			G3D::Color4(team->getTeamColor().color3(), 1.0f)
		);

		rect.low.y += fontSize;
		for (unsigned int p = 0; p < leaderboardData.playersByTeamList[team].size(); ++p) {
			for (unsigned int i = 0; i < leaderboardData.statNamesList.size() + 1; ++i) {
				float rowWidth = rect.high.x - rect.low.x;
				G3D::Vector2 position(rect.low.x, rect.low.y);
				std::string label = leaderboardData.playersByTeamList[team][p];

				if (i == 0) {
					position.x += 5.0f;
				}
				else {
					float half = rowWidth * 0.5f;
					position.x =
						(float) (i - 1) * (half / (float) leaderboardData.statNamesList.size()) + half + position.x;
					label = boost::lexical_cast<std::string>(
						leaderboardData
							.statMap[leaderboardData.playersByTeamList[team][p]][leaderboardData.statNamesList[i - 1]]
					);
				}

				adorn->drawFont2D(
					label,
					position,
					fontSize,
					G3D::Color4(team->getTeamColor().color3(), 1.0f),
					G3D::Color4::clear(),
					Adorn::XALIGN_LEFT,
					Adorn::YALIGN_TOP,
					Adorn::PROPORTIONAL_SPACING
				);

				if (i == 0) {
					position.x -= 5.0f;
				}
			}

			rect.low.y += fontSize;
		}

		rect.low.y += fontSize;
	}
}

// FUNCTION: ROBLOX 0x0065efe0
void ScoreHud::render2d(Adorn* adorn)
{
	switch (DetermineBoardType()) {
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

} // namespace RBX
