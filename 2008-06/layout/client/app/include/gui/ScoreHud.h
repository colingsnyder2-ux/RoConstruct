#pragma once
// 2008-06 native RBX::ScoreHud (inactive). Shape after the donor tools/rbxgs gui/ScoreHud.h. Read from the binary
// (tests/record_native_hud.py checks it):
//   ScoreHud  vtable 0084bcb4 .?AVScoreHud@RBX@@ -> GuiItem -> Instance (+ GuiTarget +0x130), Listener<Instance,
//             ChildAdded> +0x144 (vtable 0084bc20), Listener<Instance, ChildRemoved> +0x148 (vtable 0084bc14).
//             Constructor 00652510 (const ServiceProvider*; ret 4): GuiItem() 005739d0, the 13 vtables, runService
//             (+0x14c) and players (+0x150) = 0, then ServiceProvider::find<RunService>() 00452c80 and
//             find<Players>() 004125d0 of the argument. Size 0x154 (00602350 allocates 0x154).
//             Destructor 00650f80 (vtables, then ~GuiItem 00411540), deleting destructor 006511f0.
//             onServiceProvider 00652600 (slot 12; the same two finds, no Instance::onServiceProvider call).
//             Both listener onEvent slots hold 00651210 (empty bodies: only the by-value event's shared_ptr is
//             released). ChildAdded comes from native v8tree/InstanceEvents.h; ChildRemoved is only declared in native
//             v8tree/Instance.h, so its body is NATIVE_SCOREHUD_PENDING and its slot binds to 00651210 by address.
//             render2d 00656430 (slot 24) dispatches on DetermineBoardType 006512e0 (Players::getPlayers 004974c0,
//             findFirstChildByName("leaderstats") 00557950, Player::neutral +0x17c) to renderFFALeaderboard 006551e0
//             and renderTeamDeathmatchLeaderboard 00655a20 (native-classes/ScoreHudLeaderboard2008.cpp, verified by
//             tests/record_native_scorehud_leaderboard.py with BoardData / LeaderboardData below).
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

	// The player-name hash renderFFALeaderboard 0065556e and the ChatLine constructor 0065061e pass to
	// Color::colorFromIndex8 (low three bits): 00669f60, cdecl, one const std::string&, returns the 31-bit hash of the
	// characters (00669f10, seed 0xf8c9, multiplier 0x5c6b7). No evidence name; this name is a codegen analog.
	unsigned int stringHash(const std::string&);

	// BoardData: the FFA / player-list table built by ScoreHud::BuildBoardData 00654d20. Not polymorphic; 0x30 bytes
	// (00654080 constructs data at +0x00 and fields at +0x18, the two 0x18-byte std::vectors of this STL build;
	// SetSize 00654630 resizes data (00654170), each row (vector<string>::resize 00446190) and fields).
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

	// LeaderboardData: the team table renderTeamDeathmatchLeaderboard 00655a20 builds on its stack. Not polymorphic;
	// constructor 00655970, destructor 006558f0. CompileData 00654860 reads context [this + 0x78] and the members at
	// +0x00 (statNamesList), +0x18 / +0x38 / +0x58 (the three 0x20-byte maps of this STL build); 0x7c bytes.
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
