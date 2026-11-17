// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /GS-
// 2008-06 native RBX::Flag (inactive): part of the original Flag unit (00618380..00619a60, initializer 007f7cc0,
// atexit 00800310). Evidence in native-headers/v8datamodel/Flag.h.
// Built against the native v8datamodel/Tool.h and Hopper.h (Tool / BackpackItem with the 2008 const-char-array
// DescribedCreatable); tests/record_native_flag_family.py verifies every row and the Flag vtables.
#include "v8datamodel/Flag.h"
#include "Network/Player.h"

#include "../native-headers/v8datamodel/PartInstance.h"

#include "../native-headers/v8datamodel/TimerService.h"
#include "../native-headers/v8datamodel/FlagStandService.h"
#include "../native-headers/v8datamodel/FlagStand.h"

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

	// Dynamic initializer 007f7cc0.
	static Reflection::PropDescriptor<Flag, BrickColor> prop_Color("TeamColor", "Data", &Flag::getTeamColor, &Flag::setTeamColor, Reflection::PropertyDescriptor::STANDARD);

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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sFlag>();

namespace RBX {
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

namespace RBX {
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
				PartInstance* handle = flag->getHandle();

				FlagStandService* fss = ServiceProvider::create<FlagStandService>(this);
				if (!fss->FindStandWithFlag(flag))
				{
					if (FlagStand* fs = fss->FindClosestEmptyStandForFlag(flag))
					{
						fs->AffixFlag(flag);
					}
				}
			}
		}
	}
}
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sFlag>();
