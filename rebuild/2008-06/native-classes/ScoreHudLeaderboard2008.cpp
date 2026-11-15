// 2008-06 native RBX::ScoreHud leaderboards (inactive): BoardData, BuildBoardData 00654d20, renderFFALeaderboard
// 006551e0. Layout and addresses in native-headers/gui/ScoreHud.h; verified by tests/record_native_scorehud_leaderboard.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "gui/ScoreHud.h"
#include "v8datamodel/Value.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Team.h"
#include "v8tree/Service.h"
#include "util/Color.h"
#include <boost/lexical_cast.hpp>

namespace RBX
{
	void ScoreHud::BuildBoardData(BoardData& board)
	{
		if (!players)
			return;
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = players->getPlayers();
		for (size_t i = 0; i < list->size(); ++i)
		{
			Instance* player = list->at(i).get();
			Instance* stats = player->findFirstChildByName("leaderstats");
			if (stats)
			{
				board.SetSize((int)list->size(), (int)stats->numChildren() + 1);
				board.AddField("Player", 0);
				for (size_t j = 0; j < stats->numChildren(); ++j)
					board.AddField(stats->getChild(j)->getName(), (int)j + 1);
				board.data[i][0] = player->getName();
				for (size_t j = 0; j < stats->numChildren(); ++j)
				{
					dynamic_cast<IntValue*>(stats->getChild(j));
					int value = IntValue::desc_Value.getValue(stats->getChild(j));
					board.data[i][j + 1] = boost::lexical_cast<std::string>(value);
				}
			}
			else
			{
				board.SetSize((int)list->size(), 1);
				board.AddField("Player List", 0);
				board.data[i][0] = player->getName();
			}
		}
		for (size_t i = 0; i < list->size(); ++i)
		{
			if (board.data[i][0].size() > 16)
				board.data[i][0].resize(16);
		}
	}

	void ScoreHud::renderFFALeaderboard(Adorn* adorn)
	{
		bool hasStats = true;
		BoardData data;
		BuildBoardData(data);
		if (data.fields.empty())
			return;
		if (data.fields.size() == 1)
			hasStats = false;

		G3D::Rect2D viewport = adorn->getViewport();
		float viewportWidth = viewport.width();
		float scale = viewportWidth * (1.0f / 1024.0f);
		float row = scale * 14.0f;
		float width = viewportWidth * 0.33f;
		if (!hasStats)
			width *= 0.5f;
		float height = (data.data.size() + 2.5f) * row;
		setGuiSize(G3D::Vector2(width, height));

		Rect rect = getMyRect();
		adorn->rect2d(rect.toRect2D(), GuiItem::translucentBackdrop());
		for (unsigned col = 0; col < data.fields.size(); ++col)
		{
			float extent = rect.high.x - rect.low.x;
			G3D::Vector2 position(rect.low.x, rect.low.y);
			if (col)
				position.x += extent * 0.5f + extent * 0.5f / data.fields.size() * (col - 1);
			adorn->drawFont2D(data.fields[col], position, row, G3D::Color4(G3D::Color3::white(), 1), G3D::Color4::zero(),
							  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
		}
		rect.low.y += row * 2;
		for (unsigned col = 0; col < data.fields.size(); ++col)
		{
			for (unsigned index = 0; index < data.data.size(); ++index)
			{
				G3D::Color3 color = G3D::Color3::white();
				if (!col)
					color = Color::colorFromIndex8(stringHash(data.data[index][0]) & 7);
				float extent = rect.high.x - rect.low.x;
				G3D::Vector2 position(rect.low.x, rect.low.y);
				if (col)
					position.x += extent * 0.5f + extent * 0.5f / data.fields.size() * (col - 1);
				position.y += index * row;
				adorn->drawFont2D(data.data[index][col], position, row, G3D::Color4(color, 1), G3D::Color4::zero(),
								  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			}
		}
	}

	void LeaderboardData::AddTuple(std::string playerName, Team* team, std::string statName, int statValue)
	{
		if (std::find(statNamesList.begin(), statNamesList.end(), statName) == statNamesList.end())
			statNamesList.push_back(statName);

		if (std::find(playersByTeamList[team].begin(), playersByTeamList[team].end(), playerName) == playersByTeamList[team].end())
			playersByTeamList[team].push_back(playerName);

		statMap[playerName][statName] = statValue;
	}

	void LeaderboardData::CompileData()
	{
		Network::Players* players = ServiceProvider::find<Network::Players>(context);
		Teams* teams = ServiceProvider::create<Teams>(context);
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > teamList = teams->getTeams();
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = players->getPlayers();
		for (size_t i = 0; i < list->size(); ++i)
		{
			Network::Player* player = static_cast<Network::Player*>(list->at(i).get());
			playersByTeamList[teams->getTeamFromPlayer(player)].push_back(player->getName());
			Instance* stats = player->findFirstChildByName("leaderstats");
			if (stats)
			{
				for (size_t j = 0; j < stats->numChildren(); ++j)
				{
					IntValue* value = dynamic_cast<IntValue*>(stats->getChild(j));
					if (value)
						AddTuple(player->getName(), teams->getTeamFromPlayer(player), value->getName(), IntValue::desc_Value.getValue(value));
				}
			}
		}
		if (!teams)
			return;
		for (size_t i = 0; i < teams->numChildren(); ++i)
		{
			Team* team = dynamic_cast<Team*>(teams->getChild(i));
			if (!team)
				continue;
			for (size_t j = 0; j < statNamesList.size(); ++j)
			{
				teamTotals[team][statNamesList[j]] = 0;
				for (size_t k = 0; k < playersByTeamList[team].size(); ++k)
				{
					int statValue = statMap[playersByTeamList[team][k]][statNamesList[j]];
					teamTotals[team][statNamesList[j]] += statValue;
				}
			}
		}
	}

	void ScoreHud::renderTeamDeathmatchLeaderboard(Adorn* adorn, BoardType mode)
	{
		LeaderboardData data(this);
		data.CompileData();
		Teams* teams = ServiceProvider::find<Teams>(this);
		if (!teams)
			return;
		G3D::Rect2D viewport = adorn->getViewport();
		float scale = viewport.width() / 1024.0f;
		float row = 14.0f * scale;
		if (mode == TEAM_DEATHMATCH)
		{
			size_t teamCount = teams->numChildren();
			int playerCount = players->numPlayers();
			float leaderboardSizeX = scale * 320.0f;
			float leaderboardSizeY = playerCount + (teamCount + 1) * 3;
			setGuiSize(G3D::Vector2(leaderboardSizeX, leaderboardSizeY * row));
		}
		else
		{
			size_t teamCount = teams->numChildren();
			int playerCount = players->numPlayers();
			float leaderboardSizeX = scale * 240.0f;
			float leaderboardSizeY = playerCount + teamCount * 3 + 2;
			setGuiSize(G3D::Vector2(leaderboardSizeX, leaderboardSizeY * row));
		}
		Rect rect = getMyRect();
		adorn->rect2d(rect.toRect2D(), GuiItem::translucentBackdrop());
		if (mode == TEAM_DEATHMATCH)
		{
			for (unsigned col = 0; col < data.statNamesList.size() + 1; ++col)
			{
				float width = rect.high.x - rect.low.x;
				G3D::Vector2 position = rect.low;
				std::string label("Team");
				if (col)
				{
					position.x += width * 0.5f + width * 0.5f / data.statNamesList.size() * (col - 1);
					label = data.statNamesList[col - 1];
				}
				adorn->drawFont2D(label, position, row, G3D::Color4(G3D::Color3::white(), 1), G3D::Color4::zero(),
								  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			}
			rect.low.y += row;
		}
		for (unsigned teamIndex = 0; teamIndex < teams->numChildren(); ++teamIndex)
		{
			Team* team = dynamic_cast<Team*>(teams->getChild(teamIndex));
			if (!team)
				continue;
			for (unsigned col = 0; col < data.statNamesList.size() + 1; ++col)
			{
				float width = rect.high.x - rect.low.x;
				G3D::Vector2 position = rect.low;
				std::string label = team->getName();
				if (col)
				{
					position.x += width * 0.5f + width * 0.5f / data.statNamesList.size() * (col - 1);
					label = boost::lexical_cast<std::string>(data.teamTotals[team][data.statNamesList[col - 1]]);
				}
				G3D::Color4 teamColor(team->getTeamColor().color3(), 1);
				adorn->drawFont2D(label, position, row, teamColor, G3D::Color4(0, 0, 0, 1),
								  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			}
			rect.low.y += row;
			adorn->line2d(G3D::Vector2(rect.low.x + 2, rect.low.y + 7), G3D::Vector2(rect.high.x - 2, rect.low.y + 7),
						  G3D::Color4(team->getTeamColor().color3(), 1));
			rect.low.y += row;
			for (unsigned player = 0; player < data.playersByTeamList[team].size(); ++player)
			{
				for (unsigned col = 0; col < data.statNamesList.size() + 1; ++col)
				{
					float width = rect.high.x - rect.low.x;
					G3D::Vector2 position = rect.low;
					std::string label = data.playersByTeamList[team][player];
					if (col)
					{
						position.x = position.x + (width * 0.5f + width * 0.5f / data.statNamesList.size() * (col - 1));
						int statValue = data.statMap[data.playersByTeamList[team][player]][data.statNamesList[col - 1]];
						label = boost::lexical_cast<std::string>(statValue);
					}
					else
					{
						position.x += 5.0f;
					}
					adorn->drawFont2D(label, position, row, G3D::Color4(team->getTeamColor().color3(), 1), G3D::Color4::zero(),
									  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
					if (!col)
						position.x -= 5.0f;
				}
				rect.low.y += row;
			}
			rect.low.y += row;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >;
template class std::_Tmap_traits<RBX::Team *,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0>;
template class std::_Tmap_traits<RBX::Team *,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Team *,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Team *,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0> >;
template class std::_Vector_const_iterator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::allocator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >;
template class std::_Vector_iterator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::allocator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Team *,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Team *,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >;
template class std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >;
template class std::vector<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::allocator<std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >;
