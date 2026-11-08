#pragma once
// >>> native-status (generated) -- do not edit >>>
// WorkspaceStatsItem | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src ff7a6fa9 | roc native-status --write
// 2008-06 native RBX::WorkspaceStatsItem (inactive, declaration only).
//   RTTI       vtable 008340ac .?AVWorkspaceStatsItem@RBX@@ -> Stats::Item (22 bases, no Service/IRenderable).
//   size       0x158 = sizeof(Stats::Item): Creatable<Instance>::create<WorkspaceStatsItem> 005a6620 allocates
//              0x158; the deleting destructor thunk 005a6610 jumps to Item's 005ca1a0 (no own members).
//   vtable     no override: slot 16 update stays the empty 0047d410.
//   ctor       005a5c90 (2431 bytes, Workspace unit): Item(), setName("Workspace"), then child items "FPS",
//              "Environment Speed %", "Physics CPU %", "Render CPU %", ... bound to Workspace/World/RunService
//              getters. Workspace::onServiceProvider 005a66b0 passes (this, world +0x2e4, the RunService from
//              ServiceProvider::create<RunService> 00452c80) and parents the item to create<StatsService> 00458610.
//              Not recovered: it needs native Workspace/World/RunService headers and the createChildItem<T>
//              function0 templates 005a52c0 / 005a5430 / 005a55a0.
#include "stats/Stats.h"

namespace RBX
{
	class Workspace;
	class World;
	class RunService;

	class WorkspaceStatsItem : public Stats::Item
	{
	public:
		WorkspaceStatsItem(const Workspace* workspace, const World* world, const RunService* runService); // 005a5c90
	};
}
