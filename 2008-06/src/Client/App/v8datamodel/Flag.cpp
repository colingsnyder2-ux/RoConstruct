#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/TimerService.h"
#include "humanoid/Humanoid.h"
#include "Network/Player.h"

namespace RBX
{
	static Reflection::PropDescriptor<Flag, BrickColor> prop_Color("TeamColor", "Data", &Flag::getTeamColor, &Flag::setTeamColor, Reflection::PropertyDescriptor::STANDARD);

	Flag::Flag()
		: timer(NULL)
	{
		setName("Flag");
	}

	Flag::~Flag() {}

	BrickColor Flag::getTeamColor() const
	{
		return teamColor;
	}

	void Flag::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(prop_Color);
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

	bool Flag::canBePickedUpByPlayer(Network::Player* p)
	{
		if (p->getNeutral())
			return false;

		BrickColor current = teamColor;
		if (p->getTeamColor() != current)
			return true;
		else
			return false;
	}

	void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			timer = ServiceProvider::create<TimerService>(newProvider);
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0f);
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

	void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
	{
		Instance* parent = other->getParent();

		if (!Humanoid::modelIsCharacter(parent))
			return;

		Network::Player* player = Network::Players::getPlayerFromCharacter(parent);
		if (!player)
			return;

		if (player->getNeutral())
			return;

		BrickColor current = teamColor;
		if (player->getTeamColor() != current)
			return;

		FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
		if (!flagStandService->FindStandWithFlag(this))
		{
			if (FlagStand* flagStand = flagStandService->FindClosestEmptyStandForFlag(this))
			{
				flagStand->AffixFlag(this);
			}
		}
	}

	void Flag::doUglyPeriodicCloneHack()
	{
		evilClone = clone();

		if (timer && numChildren() == 0)
		{
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0f);
		}
	}
}
