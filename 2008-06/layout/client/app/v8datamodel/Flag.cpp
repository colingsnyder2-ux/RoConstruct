// =============================================================================
// Flag.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Flag.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/TimerService.h"
#include "util/RunStateOwner.h"
#include <boost/bind.hpp>

namespace RBX
{
	void Flag::doUglyPeriodicCloneHack()
	{
		evilClone = clone();

		if (timer && numChildren() == 0)
		{
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
		}
	}

	void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			timer = ServiceProvider::create<TimerService>(newProvider);
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
		}

		if (!newProvider)
		{
			flagTouched.disconnect();
			RunService* runService = ServiceProvider::create<RunService>(oldProvider);

			if (runService->getRunState() == RS_RUNNING)
			{
				if (Instance* evilC = evilClone.get())
				{
					Flag* flag = dynamic_cast<Flag*>(evilC);
					flag->getHandle();

					FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
					if (!flagStandService->FindStandWithFlag(flag))
					{
						if (FlagStand* flagStand = flagStandService->FindClosestEmptyStandForFlag(flag))
						{
							flagStand->AffixFlag(flag);
						}
					}
				}
			}
		}
	}

	void Flag::onChildAdded(Instance* instance)
	{
		if (dynamic_cast<PartInstance*>(instance))
		{
			if (PartInstance* handle = getHandle())
			{
				flagTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Flag::onEvent_flagTouched, this, _1), 10);
			}
		}
	}
}

#include "Network/Player.h"

namespace RBX
{
	const char sFlag[] = "Flag"; // 00843c90 (doDeclare 005a0320, classDescriptor 005c3880, constructor setName)

	// Template members the shared headers only declare (same definitions as Team.cpp / SpawnLocation.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	static Reflection::PropDescriptor<Flag, BrickColor> prop_Color(
		"TeamColor",
		"Data",
		&Flag::getTeamColor,
		&Flag::setTeamColor,
		Reflection::PropertyDescriptor::STANDARD);

	BrickColor Flag::getTeamColor() const
	{
		return teamColor;
	}

	bool Flag::canBePickedUpByPlayer(Network::Player* p)
	{
		return p->getNeutral() ? false : (p->getTeamColor() != getTeamColor());
	}

	Flag::~Flag()
	{
	}

	Flag::Flag()
		: timer(NULL)
	{
		setName(sFlag);
	}

	void Flag::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(prop_Color);
	}
}

template void RBX::Name::callDoDeclare<RBX::sFlag>();

namespace RBX
{
}

#include "humanoid/Humanoid.h"
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
