// 2008-06 native RBX::AssemblyStage (inactive); layout evidence in native-headers/AppUnit66C/AssemblyStage.h.
// Verified by tests/record_native_app_unit66c.py. Built here: stepWorld 0066f570, the destructor 0066f790 and the scalar
// deleting destructor 0066f8b0 (vtable 0084d1a4 is emitted here).
// Not built: AssemblyStage() 0066f800 news a 0x1ec-byte SleepStage (0064b8e0) that no native header declares;
// wakeAssembly 0066f510 / onAssemblyAdded 0066f530 / onAssemblyRemoving 0066f550 call SleepStage members 0064b890 /
// 0064aff0 / 0064b0a0; onEdgeAdded 0066f5f0 / onEdgeRemoving 0066f6e0 write the 2008 Assembly +0x14 flag and call the
// 2008 Primitive::getContact / getJoint (005e7ce0 / 005e7d30) on the Edge primitives (see the recorder's proposals);
// getStageType 006fa3f0 returns the 2008 ASSEMBLY_STAGE 4 (the donor IStage.h numbers it 3).
#include "AppUnit66C/AssemblyStage.h"
#include "v8world/Joints2008.h"

namespace RBX
{
	// 0066f790
	AssemblyStage::~AssemblyStage()
	{
	}

	// 0066f570: every joint's slot 13 (Joints2008.h stepWorld), then the downstream stage (IStage::stepWorld inline)
	void AssemblyStage::stepWorld(int worldStepId, int uiStepId, bool throttling)
	{
		for (std::set<Joint*>::iterator it = joints.begin(); it != joints.end(); ++it)
			(*it)->stepWorld();
		IStage::stepWorld(worldStepId, uiStepId, throttling);
	}
}
