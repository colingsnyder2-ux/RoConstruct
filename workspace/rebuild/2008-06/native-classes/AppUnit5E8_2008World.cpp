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
#ifdef NATIVE_APPUNIT5E8_PENDING
#include "v8world/CleanStage2008.h"
#endif

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

#include "v8world/SpatialHash.h"
#include "v8world/Assembly.h"
namespace RBX
{
	// Not exact (recorded with the reason): the 2008 SpatialHash / Assembly::PrimIterator differ from the donor.
	int World::getNumHashNodes() const
	{
		return contactManager->getSpatialHash().getNodesOut();
	}

	int World::getMaxBucketSize() const
	{
		return contactManager->getSpatialHash().getMaxBucket();
	}

	void World::onAssemblyExtentsChanged(RBX::Assembly * a)
	{
		Assembly::PrimIterator endIt = Assembly::PrimIterator::end(a);
		Assembly::PrimIterator beginIt = Assembly::PrimIterator::begin(a);
		for (; beginIt != endIt; ++beginIt)
		{
			contactManager->onPrimitiveExtentsChanged(*beginIt);
		}
	}

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

#ifdef NATIVE_APPUNIT5E8_PENDING
// Pending-build-only bodies: they need the 2008 first-stage type at World +0x88 (CleanStage, not JointStage) and the
// 2008 StageType values, both missing from the shared headers (proposals in tests/record_native_app_unit5e8_2008.py).
#include "v8world/SimJobStage2008.h"
#include "v8world/SleepStage.h"
namespace RBX
{
	void World::onJointPrimitiveNulling(Joint* j, Primitive* p)
	{
		jointStage->onJointPrimitiveNulling(j, p);
	}

	void World::onJointPrimitiveSet(Joint* j, Primitive* p)
	{
		jointStage->onJointPrimitiveSet(j, p);
	}

	SimJobStage& World::getSimJobStage()
	{
		return *rbx_static_cast<SimJobStage*>(jointStage->findStage(IStage::SIMJOB_STAGE));
	}

	SleepStage* World::getSleepStage()
	{
		return rbx_static_cast<SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE));
	}
}
#endif
