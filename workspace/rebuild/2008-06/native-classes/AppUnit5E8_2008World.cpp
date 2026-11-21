// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// 2008-06 native RBX::World rows of the World.cpp unit 005e9150..005eaeef (inactive), application range
// 005e8000..005f4000. Built against Colin's native-headers/engine-world/v8world/World.h and ContactManager.h (read-only;
// the recorder puts native-headers/engine-world first, as record_native_geometry_service.py does) and the native
// v8world/JointStage2008.h. Layout evidence used by these bodies (World() 005ea920): four Notifier bases at +0x0 /
// +0x20 / +0x40 / +0x60 (vtables 0083f8d8 / 0083f8c8 / 0083f8b8 / 0083f8a8), contactManager +0x84 (new 0x14,
// ContactManager(World*) 0060d260), first stage +0x88 (new 0x10, CleanStage(NULL, this) 0064a310), touch +0x8c,
// touchOther +0x98, inJointNotification +0xa5, primitives +0xac (size +0xb0). Members past +0xb8 (numJoints +0xe4,
// numContacts +0xe8, numLinkCalls +0xec) are off by 0xc in the header (see the recorder's PROPOSALS) and are not used.
// Verified by tests/record_native_app_unit5e8_2008.py.
#undef _RELEASEASSERT
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8world/Contact.h"
#include "v8world/IWorldStage.h"
#include "v8world/JointStage2008.h"
#include "v8world/CleanStage2008.h"

namespace RBX
{
	Kernel& World::getKernel()
	{
		return *jointStage->getKernel();
	}

	int World::getMetric(IWorldStage::MetricType metricType) const
	{
		return jointStage->getMetric(metricType);
	}

	void World::onPrimitiveContactParametersChanged(Primitive* p)
	{
		for (Contact* curContact = p->getFirstContact(); curContact != NULL; curContact = p->getNextContact(curContact))
		{
			curContact->onPrimitiveContactParametersChanged();
		}
	}

	void World::onPrimitiveExtentsChanged(Primitive* p)
	{
		contactManager->onPrimitiveExtentsChanged(p);
	}

	void World::onPrimitiveGeometryTypeChanged(Primitive* p)
	{
		contactManager->onPrimitiveGeometryTypeChanged(p);
	}

	void World::onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP)
	{
		touch.append(touchP);
		touchOther.append(touchOtherP);
	}
}

// 2008 SpatialHash layout (nodesOut +0x78, maxBucket +0x7c): 005e9170 / 005e9180; the donor SpatialHash.h is the 2009 one.
#include "v8world/SpatialHash2008.h"
#include "v8world/Assembly.h"
namespace RBX
{
	// 005e9170: mov eax, [ecx+0x84] (contactManager); mov ecx, [eax] (spatialHash); mov eax, [ecx+0x78]; ret.
	// Identity: the slot after getMetric 005e9160 and before onPrimitiveContactParametersChanged 005e9190 in donor
	// World.cpp order; registry placeholder func_005e9170.
	int World::getNumHashNodes() const
	{
		return contactManager->getSpatialHash().getNodesOut();
	}

	// 005e9180: same shape, [spatialHash+0x7c] (registry placeholder func_005e9180).
	int World::getMaxBucketSize() const
	{
		return contactManager->getSpatialHash().getMaxBucket();
	}

	// 005e91d0 World::onAssemblyExtentsChanged: built in native-classes/RBXWorldRecovery_005e9170.cpp (batch 28) against
	// the 2008 Assembly of v8world/AssemblyLayout.h (assemblyPrimBegin 005e5fa0 / assemblyPrimEnd 005e5fc0), which this
	// unit's donor engine-world headers cannot reach.

	void World::createJoints(Primitive *p)
	{
		createJoints(p, NULL);
	}

	void World::destroyJoints(Primitive *p)
	{
		destroyJoints(p, NULL);
	}

	void World::createJointsToWorld(const G3D::Array<Primitive*>& primitives)
	{
		std::set<Primitive*> ignore;
		for (int i = 0; i < primitives.size(); i++)
			ignore.insert(primitives[i]);

		for (int i = 0; i < primitives.size(); i++)
			createJoints(primitives[i], &ignore);
	}

	void World::destroyJointsToWorld(const G3D::Array<Primitive*>& primitives)
	{
		std::set<Primitive*> ignore;
		for (int i = 0; i < primitives.size(); i++)
			ignore.insert(primitives[i]);

		for (int i = 0; i < primitives.size(); i++)
			destroyJoints(primitives[i], &ignore);
	}

	void World::joinAll()
	{
		for (int i = 0; i < primitives.size(); i++)
			createJoints(primitives[i]);
	}

	template void Notifier<World, AutoJoin>::raise(AutoJoin) const;
	template void Notifier<World, AutoDestroy>::raise(AutoDestroy) const;
	template void Notifier<World, AssemblyPhysicsOn>::raise(AssemblyPhysicsOn) const;
	template void Notifier<World, AssemblyPhysicsOff>::raise(AssemblyPhysicsOff) const;
}

// World +0x88 is a CleanStage under the kernel-stages opt-in (first native-flags include; 2008 StageType numbering).
#include "v8world/SimJobStage2008.h"
#include "v8world/SleepStage.h"
#include "v8world/ClumpStage.h"
namespace RBX
{
	// 005e9240: mov ecx, [ecx+0x88]; jmp CleanStage::onJointPrimitiveNulling 0064a420
	void World::onJointPrimitiveNulling(Joint* j, Primitive* p)
	{
		jointStage->onJointPrimitiveNulling(j, p);
	}

	// 005e9250: tail call of CleanStage::onJointPrimitiveSet 0064a460
	void World::onJointPrimitiveSet(Joint* j, Primitive* p)
	{
		jointStage->onJointPrimitiveSet(j, p);
	}

	// 005e93b0: IStage::findStage walk (getStageType slot 1) for SIMJOB_STAGE 6
	SimJobStage& World::getSimJobStage()
	{
		return *rbx_static_cast<SimJobStage*>(jointStage->findStage(IStage::SIMJOB_STAGE));
	}

	// 005e93e0: IStage::findStage walk for SLEEP_STAGE 5
	SleepStage* World::getSleepStage()
	{
		return rbx_static_cast<SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE));
	}

	// 005e9460: findStage(CLUMP_STAGE 2) walk, then ClumpStage 0064cda0 (donor World.cpp order: onPrimitiveCanSleepChanged)
	void World::onPrimitiveCanSleepChanged(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveCanSleepChanged(p);
	}

	// 005e94a0: findStage(CLUMP_STAGE 2) walk, then ClumpStage::onPrimitiveAddedAnchor 0064cc40
	void World::onPrimitiveAddedAnchor(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveAddedAnchor(p);
	}

	// 005e94e0: findStage(CLUMP_STAGE 2) walk, then ClumpStage 0064ccf0 (anchor removal)
	void World::onPrimitiveRemovingAnchor(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveRemovingAnchor(p);
	}

	// 005e9520: findStage(CLUMP_STAGE 2) walk, then tail call of ClumpStage 0064cad0 (no argument: process)
	void World::update()
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->process();
	}
}
