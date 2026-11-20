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

#include "v8world/SpatialHash2008.h"
#include "v8world/Assembly.h"
namespace RBX
{
	int World::getNumHashNodes() const
	{
		return contactManager->getSpatialHash().getNodesOut();
	}

	int World::getMaxBucketSize() const
	{
		return contactManager->getSpatialHash().getMaxBucket();
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

#include "v8world/SimJobStage2008.h"
#include "v8world/SleepStage.h"
#include "v8world/ClumpStage.h"
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

	void World::onPrimitiveCanSleepChanged(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveCanSleepChanged(p);
	}

	void World::onPrimitiveAddedAnchor(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveAddedAnchor(p);
	}

	void World::onPrimitiveRemovingAnchor(Primitive* p)
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->onPrimitiveRemovingAnchor(p);
	}

	void World::update()
	{
		rbx_static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE))->process();
	}
}
