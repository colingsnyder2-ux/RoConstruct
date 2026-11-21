#pragma once
#include "gui/Gui.h"
#include <map>
#include <algorithm>

struct NativeHudLayout;
struct NativeScoreHudLeaderboardLayout;

namespace RBX
{
	class RunService;

	namespace Network
	{
		class Players;
	}

	unsigned int stringHash(const std::string&);

	class BoardData
	{
	public:
		std::vector<std::vector<std::string> > data;                 // +0x00 (00654080)
		std::vector<std::string> fields;                             // +0x18 (00654080)

	public:
		BoardData()                                                  // 00654080
		{
		}
		void SetSize(int dataSize, int fieldSize)                    // 00654630
		{
			data.resize(dataSize);
			for (int i = 0; i < dataSize; ++i)
				data[i].resize(fieldSize);
			fields.resize(fieldSize);
		}
		void AddField(std::string fieldName, int position)           // 00650ef0
		{
			fields[position] = fieldName;
		}
	};

	class Team;

	class LeaderboardData
	{
	public:
		std::vector<std::string> statNamesList;                      // +0x00
		std::map<Team*, std::vector<std::string> > playersByTeamList; // +0x18 (00654b8f)
		std::map<std::string, std::map<std::string, int> > statMap; // +0x38 (00654bc5)
		std::map<Team*, std::map<std::string, int> > teamTotals;     // +0x58 (00654c08)
	private:
		Instance* context;                                           // +0x78 (0065487d)

	public:
		LeaderboardData(Instance* context)                           // 00655970
			: context(context)
		{
		}
		void CompileData();                                          // 00654860

	private:
		void AddTuple(std::string playerName, Team* team, std::string statName, int statValue);  // 006546d0
		friend struct ::NativeScoreHudLeaderboardLayout;
	};

	class ScoreHud : public GuiItem,
					 public Listener<Instance, ChildAdded>,
					 public Listener<Instance, ChildRemoved>
	{
	protected:
		enum BoardType
		{
			PLAYER_LIST,
			FFA,
			TEAM_DEATHMATCH,
			TEAM_LIST
		};

	protected:
		RunService* runService;                                      // +0x14c (00652617)
		Network::Players* players;                                   // +0x150 (00652629)

	protected:
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);  // slot 12, 00652600
		virtual void onEvent(const Instance*, ChildRemoved);         // 00651210 (pending)
		virtual void onEvent(const Instance*, ChildAdded);           // 00651210
		virtual void render2d(Adorn*);                               // slot 24, 00656430
		void renderTeamDeathmatchLeaderboard(Adorn*, BoardType);     // 00655a20
		void renderFFALeaderboard(Adorn*);                           // 006551e0
		void BuildBoardData(BoardData&);                             // 00654d20
		BoardType DetermineBoardType();                              // 006512e0
	public:
		ScoreHud(const ServiceProvider*);                            // 00652510
		virtual ~ScoreHud();                                         // 00650f80
		friend struct ::NativeHudLayout;
	};
}
