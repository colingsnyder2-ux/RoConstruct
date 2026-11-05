// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_espclaude_872167d21248def9.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "v8world/Joint.h"
#include "v8world/World.h"
#include "v8world/IWorldStage.h"
#undef private
#include "decomp.h"
#include <cstddef>

namespace RBX {

// exe build has one stage fewer than OpenRBX: KERNEL_STAGE == 7
static inline World* exGetWorld(IPipelined* p)
{
	if (p->currentStage == NULL) {
		return NULL;
	}

	IStage* stage;

	if (p->currentStage->getStageType() != (IStage::StageType)7) {
		stage = p->currentStage;
	}
	else {
		stage = p->currentStage->getUpstream();
	}

	return static_cast<IWorldStage*>(stage)->getWorld();
}

void Joint::setJointCoord(int i, const CoordinateFrame& c)
{
	if (c != getJointCoord(i)) {
		if (i == 0) {
			jointCoord0 = c;
		}
		else {
			jointCoord1 = c;
		}

		if (World* world = exGetWorld(this)) {
			world->removeJoint(this);
			world->insertJoint(this);
		}
	}
}

}
