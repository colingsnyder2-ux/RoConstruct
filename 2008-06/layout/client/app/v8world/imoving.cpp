// =============================================================================
// imoving.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/imoving.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8world/IMoving.h"

namespace RBX
{
	IMovingManager::~IMovingManager()
	{
	}
}

namespace RBX
{
	IMoving::IMoving()
		: iMovingManager(NULL),
		  stepsToSleep(0)
	{
	}
}

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

void IMoving::notifyMoved(void)
{
	if (stepsToSleep == 0) {
		stepsToSleep = 30;
		onCanAggregateChanged(false);
		if (iMovingManager != 0) {
			iMovingManager->moving.insert(this);
		}
	}
}

	IMovingManager::IMovingManager()
	{
		current = moving.end();
	}

	void IMovingManager::remove(IMoving* iMoving)
	{
		if (current != moving.end() && *current == iMoving)
			current = moving.erase(current);
		else
			moving.erase(iMoving);
	}

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

void IMoving::setMovingManager(IMovingManager* _iMovingManager)
{
	if (iMovingManager != 0) {
		iMovingManager->remove(this);
	}
	iMovingManager = _iMovingManager;
	if (_iMovingManager != 0 && stepsToSleep > 0) {
		onCanAggregateChanged(false);
		if (iMovingManager != 0) {
			IMoving* m = this;
			iMovingManager->moving.insert(m);
		}
	}
}
}
