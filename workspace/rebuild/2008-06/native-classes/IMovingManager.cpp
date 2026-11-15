// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8world/IMoving.h"

namespace RBX
{
	// makeMoving and moved have no out-of-line copy in the image; inlined into notifyMoved / setMovingManager.
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
