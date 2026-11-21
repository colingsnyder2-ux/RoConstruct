// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::AssemblyStage (inactive); layout evidence in native-headers/AppUnit66C/AssemblyStage.h.
// Verified by tests/record_native_app_unit66c.py. Built here: stepWorld 0066f570, the destructor 0066f790 and the scalar
// deleting destructor 0066f8b0 (vtable 0084d1a4 is emitted here).
// Built since batch 24: AssemblyStage() 0066f800 and the SleepStage(IStage*, World*) 0064b8e0 it news (0x1ec).
// Built since batch 25: wakeAssembly 0066f510 / onAssemblyAdded 0066f530 / onAssemblyRemoving 0066f550 (SleepStage members
// 0064b890 / 0064aff0 / 0064b0a0 declared in v8world/SleepStage2008.h). Not built: onEdgeAdded 0066f5f0 / onEdgeRemoving 0066f6e0 write the 2008 Assembly +0x14 flag and call the
// 2008 Primitive::getContact / getJoint (005e7ce0 / 005e7d30) on the Edge primitives (see the recorder's proposals);
// getStageType 006fa3f0 (ASSEMBLY_STAGE 4) is built through the kernel-stages opt-in (the donor IStage.h numbers it 3).
#include "AppUnit66C/AssemblyStage.h"
#include "v8world/Joints2008.h"
// SleepStage(IStage*, World*) 0064b8e0 (batch 24): the only stage AssemblyStage() 0066f800 creates; its own unit
// native-classes/SleepStage2008.cpp was read-only this batch, so the body is drafted here on the same headers.
#include "v8world/SleepStage2008.h"
#include "v8world/SimJobStage2008.h"
#include "util/Profiling.h"

namespace RBX
{
	// 006fa3f0 (folded `mov eax, 4`): ASSEMBLY_STAGE of the 2008 StageType (opt-in native-headers/kernel-stages v8kernel/IStage.h
	// through the native-flags line).
	IStage::StageType AssemblyStage::getStageType()
	{
		return ASSEMBLY_STAGE;
	}

	// 0064b8e0 (`ret 8`; native-headers/v8world/SleepStage2008.h): downstream = new(0x2c) SimJobStage(this, world)
	// 0064d300, upstream +0x4, world +0xc, vtable 0084b088; the eight vectors (4-byte proxy each), the counters +0xd0 /
	// +0xd4 = 0, +0xd8 = false, uiStepId +0xdc = -1, the six assembly sets (_Tree ctor 0064b2a0), both IndexArrays
	// zeroed, steppingJoints +0x1b8, +0x1d8 = 0, +0x1dc = false, then three new(0xc048) CodeProfiler 005c43a0 named
	// "Collision" 0084b0b4, "Wake" 0084b0ac and "Sleep" 0084b0a4 (donor SleepStage2.cpp names and member order).
	SleepStage::SleepStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new SimJobStage(this, world), world),
		  numContactsInStage(0),
		  numContactsInKernel(0),
		  throttling(false),
		  uiStepId(-1),
		  field1d8(0),
		  externalBodyForceAdded(false),
		  profilingCollision(new Profiling::CodeProfiler("Collision")),
		  profilingWake(new Profiling::CodeProfiler("Wake")),
		  profilingSleep(new Profiling::CodeProfiler("Sleep"))
	{
	}

	// 0066f800 (`ret 8`): downstream = new(0x1ec) SleepStage(this, world) 0064b8e0, upstream +0x4, world +0xc, vtable
	// 0084d1a4, then the two sets +0x10 / +0x30 (_Tree ctor 0064b2a0).
	AssemblyStage::AssemblyStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new SleepStage(this, world), world)
	{
	}

	// 0066f790
	AssemblyStage::~AssemblyStage()
	{
	}

	// 0066f570: every joint's slot 13 (Joints2008.h stepWorld), then the downstream stage (IStage::stepWorld inline)
	void AssemblyStage::stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
	{
		for (std::set<Joint*>::iterator it = joints.begin(); it != joints.end(); ++it)
			(*it)->stepWorld();
		IStage::stepWorld(worldStepId, uiStepId, throttling, moveBodiesTest);
	}

	// 0066f510 (`ret 4`): donor AssemblyStage::wakeAssembly -> SleepStage::onWakeUpRequest(a, false) 0064b890.
	void AssemblyStage::wakeAssembly(Assembly* assembly)
	{
		static_cast<SleepStage*>(getDownstream())->onWakeUpRequest(assembly, false);
	}

	// 0066f530 (`ret 4`): IPipelined::putInStage 00645830, then SleepStage::onAssemblyAdded 0064aff0.
	void AssemblyStage::onAssemblyAdded(Assembly* assembly)
	{
		assembly->putInStage(this);
		static_cast<SleepStage*>(getDownstream())->onAssemblyAdded(assembly);
	}

	// 0066f550 (`ret 4`): SleepStage::onAssemblyRemoving 0064b0a0, then IPipelined::removeFromStage 00645840.
	void AssemblyStage::onAssemblyRemoving(Assembly* assembly)
	{
		static_cast<SleepStage*>(getDownstream())->onAssemblyRemoving(assembly);
		assembly->removeFromStage(this);
	}
}
