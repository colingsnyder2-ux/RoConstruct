// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 006195b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "humanoid/Humanoid.h"
#include "Network/Player.h"
#include "Network/Players.h"
#include "util/Name.h"

namespace RBX
{
	void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
	{
		Instance* parent = other->getParent();

		Humanoid* humanoid = Humanoid::modelIsCharacter(parent);
		if (!humanoid)
			return;

		Network::Player* player = Network::Players::getPlayerFromCharacter(parent);
		if (!player)
			return;

		if (player->getNeutral() != false)
			return;

		BrickColor current = teamColor;
		if (player->getTeamColor() != current)
			return;

		FlagStandService* fss = ServiceProvider::create<FlagStandService>(this);
		if (!fss->FindStandWithFlag(this))
		{
			if (FlagStand* fs = fss->FindClosestEmptyStandForFlag(this))
			{
				fs->AffixFlag(this);
			}
		}
	}
}
