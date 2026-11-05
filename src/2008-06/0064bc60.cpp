// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_55a8d705f4093d42.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/SleepStage.h", "roc_unit_e122b107650b8d44.cpp")
#pragma include_alias("v8world/Assembly.h", "roc_unit_c2191b1d8d68a719.cpp")
#pragma include_alias("v8world/Clump.h", "roc_unit_9da8b0a292a9525e.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_1deee9af9b5e9e77.cpp")
#pragma include_alias("v8kernel/Body.h", "roc_unit_fdeff9a4ea2b6152.cpp")
#pragma include_alias("v8world/Edge.h", "roc_unit_ad178cfd636587c6.cpp")
#include "v8world/SleepStage.h"
#include "v8world/SimJobStage.h"
#include "v8kernel/Body.h"
#include "v8world/Joint.h"
namespace RBX {

bool SleepStage::isMoving(Assembly* assembly) {
 SleepInfo* info = assembly->getSleepInfo();
 return info && (info->state == Sim::AWAKE || info->state == Sim::RECURSIVE_WAKE_PENDING || info->state == Sim::WAKE_PENDING);
}
bool SleepStage::atLeastOneAssemblyMoving(Assembly* a0, Assembly* a1)
{
	return isMoving(a0) || isMoving(a1);
}
void SleepStage::stepJoints()
{
	

	

	JointSet::iterator it;

	for (it = (*reinterpret_cast<JointSet*>(reinterpret_cast<char*>(this) + 0x1b8)).begin(); it != (*reinterpret_cast<JointSet*>(reinterpret_cast<char*>(this) + 0x1b8)).end(); ++it) {
		Joint* j = *it;

		Primitive* prim0 = j->getPrimitive(0);
		Primitive* prim1 = j->getPrimitive(1);

		if (!(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0xd8)) || !prim0->getBody()->getCanThrottle() || !prim1->getBody()->getCanThrottle()) {
			if (!atLeastOneAssemblyMoving(prim0->getAssembly(), prim1->getAssembly())) {
				(*reinterpret_cast<std::vector<Joint*>*>(reinterpret_cast<char*>(this) + 0xb8)).push_back(j);
			}
		}
	}

	changeJointState((*reinterpret_cast<std::vector<Joint*>*>(reinterpret_cast<char*>(this) + 0xb8)), Sim::SLEEPING);
	(*reinterpret_cast<std::vector<Joint*>*>(reinterpret_cast<char*>(this) + 0xb8)).resize(0);
}
}
