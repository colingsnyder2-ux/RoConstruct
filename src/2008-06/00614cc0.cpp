// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8world/IMoving.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/IMoving.h"

#include "decomp.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d0be0
IMoving::IMoving() : iMovingManager(NULL), stepsToSleep(0)
{
}

bool IMoving::checkSleep()
{
	if (stepsToSleep > 1) {
		stepsToSleep--;

		return false;
	}

	stepsToSleep = 0;
	onCanAggregateChanged(true);

	return true;
}

void IMoving::makeMoving()
{
	if (iMovingManager != NULL) {
		iMovingManager->moved(this);
	}
}

// FUNCTION: WEBSERVICE 0x100d0c80
IMovingManager::~IMovingManager()
{
}

// FUNCTION: WEBSERVICE 0x100d0cc0
void IMovingManager::remove(IMoving* iMoving)
{
	if (current != moving.end() && *current == iMoving) {
		current = moving.erase(current);
	}
	else {
		moving.erase(iMoving);
	}
}

// FUNCTION: WEBSERVICE 0x100d0d50
void IMovingManager::onMovingHeartbeat()
{
	for (current = moving.begin(); current != moving.end();) {
		IMoving* m = *current;

		if (m->checkSleep()) {
			remove(m);
		}
		else {
			++current;
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d0de0
void IMoving::setMovingManager(IMovingManager* _iMovingManager)
{
	if (iMovingManager != NULL) {
		iMovingManager->remove(this);
	}

	iMovingManager = _iMovingManager;

	if (_iMovingManager != NULL && stepsToSleep > 0) {
		onCanAggregateChanged(false);
		makeMoving();
	}
}

// FUNCTION: WEBSERVICE 0x100d0e40
void IMoving::notifyMoved()
{
	if (stepsToSleep == 0) {
		stepsToSleep = 30;
		onCanAggregateChanged(false);
		makeMoving();
	}
}

// FUNCTION: WEBSERVICE 0x100d0e80
IMovingManager::IMovingManager()
{
	current = moving.end();
}

} // namespace RBX
