// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Flag (inactive): the clone/timer/stand half of the original Flag unit (00618380..00619a60).
// Flag.cpp (read-only, another contributor) holds the descriptor, constructor, destructor and accessors; this unit
// adds doUglyPeriodicCloneHack 00618f70, onServiceProvider 006194a0 and onChildAdded 00619970. Shapes follow the
// donor Flag.cpp; every call target below is read from the 2008-06 bodies (identity registry names in comments).
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/TimerService.h"
#include "util/RunStateOwner.h"
#include <boost/bind.hpp>

namespace RBX
{
	// 00618f70: evilClone = clone() (Instance::clone 00559350, shared_count::operator= 004025b0); re-arms the
	// timer (TimerService::delay 005d6e10, 2.0 at 00826fd0) only while the flag has no children (+0x108 children).
	void Flag::doUglyPeriodicCloneHack()
	{
		evilClone = clone();

		if (timer && numChildren() == 0)
		{
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
		}
	}

	// 006194a0: create<TimerService> 00492020, delay 005d6e10, connection::disconnect 00595230,
	// create<RunService> 004530f0 (runState +0x1b4 == RS_RUNNING), create<FlagStandService>(this) 00619450,
	// FindStandWithFlag 0062bfc0, FindClosestEmptyStandForFlag 0062c2e0, FlagStand::AffixFlag 0062bdc0.
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

	// 00619970: dynamic_cast<PartInstance*>, Tool::getHandle 005fd760, event_Touched (00976164)
	// TSignalDesc::connect 004a3340 with priority 10, scoped_connection::operator= 00595540.
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
