#pragma once
// >>> native-status (generated) -- do not edit >>>
// ScoreHud | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 324bff76 | roc native-status --write
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
//             released; ChildAdded / ChildRemoved are only declared in native v8tree/Instance.h: NATIVE_SCOREHUD_PENDING).
//             render2d 00656430 (slot 24) dispatches on DetermineBoardType 006512e0 (Players::getPlayers 004974c0,
//             findFirstChildByName("leaderstats") 00557950, Player::neutral +0x17c) to renderFFALeaderboard 006551e0
//             and renderTeamDeathmatchLeaderboard 00655a20 (not attempted).
//             The donor's BoardData / LeaderboardData helpers have no layout evidence here and are left out.
#include "gui/Gui.h"

struct NativeHudLayout;

namespace RBX
{
	class RunService;

	namespace Network
	{
		class Players;
	}

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
		virtual void onEvent(const Instance*, ChildAdded);           // 00651210 (pending)
		virtual void render2d(Adorn*);                               // slot 24, 00656430
		void renderTeamDeathmatchLeaderboard(Adorn*, BoardType);     // 00655a20 (not attempted)
		void renderFFALeaderboard(Adorn*);                           // 006551e0 (not attempted)
		BoardType DetermineBoardType();                              // 006512e0
	public:
		ScoreHud(const ServiceProvider*);                            // 00652510
		virtual ~ScoreHud();                                         // 00650f80
		friend struct ::NativeHudLayout;
	};
}
