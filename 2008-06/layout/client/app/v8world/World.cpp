#undef _RELEASEASSERT
#define NATIVE_WORLD_LAYOUT
#include <set>
#include <G3D/Array.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Extents.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/World2008.h"
#include "v8world/ContactManager2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly (assemblyPrimBegin 005e5fa0 / End 005e5fc0)
#include "v8world/AssemblyLayout.h"

namespace RBX
{
	class JointBuilder
	{
	public:
		static Joint* canJoin(Primitive* p0, Primitive* p1);
	};

	static bool inIgnoreGroup(std::set<Primitive*>* ignoreGroup, Primitive* p)
	{
		return ignoreGroup != NULL && ignoreGroup->find(p) != ignoreGroup->end();
	}

	void World::createJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
	{
		this->numLinkCalls++;
		this->tempPrimitives.fastClear();
		this->contactManager->getPrimitivesTouchingExtents(p->getFastFuzzyExtents(), p, this->tempPrimitives);

		for (int i = 0; i < this->tempPrimitives.length(); i++)
		{
			Primitive* currentPrim = this->tempPrimitives[i];

			if (!inIgnoreGroup(ignoreGroup, currentPrim))
			{
				if (!Primitive::getJoint(p, currentPrim))
				{
					Joint* canJoin = JointBuilder::canJoin(p, currentPrim);
					if (canJoin)
					{
						this->insertJoint(canJoin);
						this->inJointNotification = true;
						Notifier<World, AutoJoin>::raise(AutoJoin(canJoin));
						this->inJointNotification = false;
					}
				}
			}
		}
	}

	void World::destroyJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
	{
		for (int i = p->getNumJoints() - 1; i >= 0; i--)
		{
			Joint* j = p->getJoint(i);
			Joint::JointType jointType = j->getJointType();
			if (jointType != Joint::FREE_JOINT && jointType != Joint::ANCHOR_JOINT)
			{
				Primitive* otherPrim = j->otherPrimitive(p);
				if (!inIgnoreGroup(ignoreGroup, otherPrim))
				{
					this->inJointNotification = true;
					Notifier<World, AutoDestroy>::raise(AutoDestroy(j));
					this->inJointNotification = false;
				}
			}
		}
	}

	void World::onAssemblyExtentsChanged(Assembly* a)
	{
		PrimIterator end = a->assemblyPrimEnd();

		for (PrimIterator it = a->assemblyPrimBegin(); it != end; ++it)
		{
			contactManager->onPrimitiveExtentsChanged(*it);
		}
	}
}
