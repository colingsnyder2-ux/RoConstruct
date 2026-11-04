#pragma once
// Declaration-only overlay (copied as out/native-team-pending/humanoid/Humanoid.h by
// tests/record_native_team.py): Teams::getTeamColorForHumanoid only needs Humanoid as a
// polymorphic Instance for dynamic_cast (type descriptor 009534e0, vtable 0083d47c).
#include "v8tree/Instance.h"

namespace RBX
{
	extern char sHumanoid[];
	class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid>
	{
	};
}
