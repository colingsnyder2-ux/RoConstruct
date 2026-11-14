// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive native 2008-06 recovery: RBX::IMoving / RBX::IMovingManager of v8world/IMoving.cpp (unit 00614bd0..00614df1,
// between RevoluteLink and the SleepStage std::set instantiations): notifyMoved 00614be0, IMovingManager::remove
// 00614c20, onMovingHeartbeat 00614cc0 and setMovingManager 00614d50. Flags: native-classes/WorkspaceUpdate.cpp (no
// float code here).
// Layout is the donor v8world/IMoving.h, which the binary confirms: IMoving vtable +0 (slot 0 onCanAggregateChanged,
// called with 0 / 1), iMovingManager +4, stepsToSleep +8 (IMoving() 00614bd0 zeroes both); IMovingManager vtable +0,
// std::set<IMoving*> moving +4 (set constructor 0064b2a0), checked iterator current +0x24 / +0x28 (IMovingManager()
// 00614dc0 sets it to moving.end()).
// makeMoving and moved have no out-of-line copy in the image: defined here (non-inline, as the donor header declares
// them) and inlined into notifyMoved / setMovingManager (the reload and NULL test of iMovingManager after the slot-0
// call, then std::set::insert 005e8c40).
#include "v8world/IMoving.h"

namespace RBX
{
	void IMovingManager::moved(IMoving* iMoving)
	{
		moving.insert(iMoving);
	}

	void IMoving::makeMoving()
	{
		onCanAggregateChanged(false);
		if (iMovingManager)
			iMovingManager->moved(this);
	}

	// 00614be0
	void IMoving::notifyMoved()
	{
		if (stepsToSleep == 0)
		{
			stepsToSleep = 30;
			makeMoving();
		}
	}

	// 00614c20
	void IMovingManager::remove(IMoving* iMoving)
	{
		if (current != moving.end() && *current == iMoving)
			current = moving.erase(current);
		else
			moving.erase(iMoving);
	}

	// 00614cc0
	void IMovingManager::onMovingHeartbeat()
	{
		current = moving.begin();
		while (current != moving.end())
		{
			IMoving* iMoving = *current;
			if (iMoving->stepsToSleep > 1)
			{
				iMoving->stepsToSleep--;
				++current;
			}
			else
			{
				iMoving->stepsToSleep = 0;
				iMoving->onCanAggregateChanged(true);
				remove(iMoving);
			}
		}
	}

	// 00614d50
	void IMoving::setMovingManager(IMovingManager* _iMovingManager)
	{
		if (iMovingManager)
			iMovingManager->remove(this);
		iMovingManager = _iMovingManager;
		if (iMovingManager && stepsToSleep > 0)
			makeMoving();
	}
}
