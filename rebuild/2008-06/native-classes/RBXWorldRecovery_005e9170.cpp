// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/engine-world
// 2008-06 native RBX::World rows that touch World fields past +0xb8 (inactive): createJoints(Primitive*, set*) 005ea4d0
// and destroyJoints(Primitive*, set*) 005ea3f0, rows of the World.cpp unit 005e9150..005eaeef.
// Batch 27 rewrite. The earlier draft of this file (get_78 / get_7c / stepPhysics / processGeometry) did not compile;
// 005e9170 / 005e9180 are World::getNumHashNodes / getMaxBucketSize (donor World.cpp order between getMetric 005e9160
// and onPrimitiveContactParametersChanged 005e9190) and are built in native-classes/AppUnit5E8_2008World.cpp against
// native-headers/v8world/SpatialHash2008.h.
// These two bodies cannot be built against engine-world v8world/World.h: there numLinkCalls / tempPrimitives sit 0xc
// lower (World() 005ea920 zeroes a second G3D::Array at +0xb8 that the header lacks) and the donor Primitive.h keeps
// joints in a linked list. This unit uses the NATIVE_WORLD_LAYOUT view of native-headers/v8world/World2008.h, the 2008
// Primitive of v8world/Primitive2008.h and the native Joint of v8world/Joints2008.h; ContactManager comes from the
// engine-world v8world/ContactManager.h (getPrimitivesTouchingExtents 0060d140 is not declared in ContactManager2008.h).
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
#include "v8world/ContactManager.h"

namespace RBX
{
	// Unit-local copy of the donor tools/rbxgs v8world/JointBuilder.h declaration (that header includes the donor
	// v8world/Primitive.h, which cannot be combined with Primitive2008.h). 0064d410 ?canJoin@JointBuilder@RBX@@SAPAVJoint@2@PAVPrimitive@2@0@Z.
	class JointBuilder
	{
	public:
		static Joint* canJoin(Primitive* p0, Primitive* p1);
	};

	// 005ea4d0 ?createJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z
	// (registry, reference vote; callers createJoints(Primitive*) 005ea5d0 and createJointsToWorld). Donor World.cpp body:
	// ++numLinkCalls (+0xec), tempPrimitives (+0xf0) resize(0, false) 00599a70, Primitive::getFastFuzzyExtents 005e7a50,
	// ContactManager::getPrimitivesTouchingExtents 0060d140, then per found primitive: set find 004ae060 against end(),
	// Primitive::getJoint(p0, p1) 005e7ce0, JointBuilder::canJoin 0064d410, insertJoint 005ea320 and the AutoJoin raise
	// 005e9940 under inJointNotification (+0xa5).
	// NEAR MISS (batch 27): 256 B against 252. Same calls, constants and control flow; register allocation differs: the
	// target keeps p on the stack (reloaded at 005ea56d) and currentPrim in ebx, pushing ebx / ebp only after the size
	// test, and spills both words of end() before the find call; this build keeps p in ebx from the prologue.
	// Rejected: const find (static_cast to const set*, the registry spells 004ae060 as the const find: unchanged) and
	// `end() == find(x)` operand order (254 B, worse).
	void World::createJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
	{
		this->numLinkCalls++;
		this->tempPrimitives.fastClear();
		this->contactManager->getPrimitivesTouchingExtents(p->getFastFuzzyExtents(), p, this->tempPrimitives);

		for (int i = 0; i < this->tempPrimitives.length(); i++)
		{
			Primitive* currentPrim = this->tempPrimitives[i];

			if (ignoreGroup == NULL || ignoreGroup->find(currentPrim) == ignoreGroup->end())
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

	// 005ea3f0 ?destroyJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z
	// (registry, reference vote). 2008 walks the joint array backwards by index (+0x3c size, Primitive 005e7ae0 per
	// index) where the donor follows getFirstJoint / getNextJoint; skips FREE_JOINT (9) and ANCHOR_JOINT (5) through the
	// virtual getJointType (slot 5), otherPrimitive inline (+0xc / +0x10), set find 004ae060, then the AutoDestroy raise
	// 005e99d0 on the +0x20 base under inJointNotification (+0xa5).
	// NEAR MISS (batch 27): 198 B, size equal; only the find / end() block differs (005ea44a..005ea47b): the target loads
	// the end() head into eax and stores it after both pushes, this build uses ecx and stores it between the pushes.
	// Rejected: const find (unchanged) and `end() == find(x)` (186 B, frame shrinks to 0x14).
	void World::destroyJoints(Primitive* p, std::set<Primitive*>* ignoreGroup)
	{
		for (int i = p->getNumJoints() - 1; i >= 0; i--)
		{
			Joint* j = p->getJoint(i);
			Joint::JointType jointType = j->getJointType();
			if (jointType != Joint::FREE_JOINT && jointType != Joint::ANCHOR_JOINT)
			{
				Primitive* otherPrim = j->otherPrimitive(p);
				if (ignoreGroup == NULL || ignoreGroup->find(otherPrim) == ignoreGroup->end())
				{
					this->inJointNotification = true;
					Notifier<World, AutoDestroy>::raise(AutoDestroy(j));
					this->inJointNotification = false;
				}
			}
		}
	}
}
