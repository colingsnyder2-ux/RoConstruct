// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/engine-world
// 2008-06 native RBX::World rows that touch World fields past +0xb8 (inactive): createJoints(Primitive*, set*) 005ea4d0
// and destroyJoints(Primitive*, set*) 005ea3f0, rows of the World.cpp unit 005e9150..005eaeef.
// Batch 27 rewrite. The earlier draft of this file (get_78 / get_7c / stepPhysics / processGeometry) did not compile;
// 005e9170 / 005e9180 are World::getNumHashNodes / getMaxBucketSize (donor World.cpp order between getMetric 005e9160
// and onPrimitiveContactParametersChanged 005e9190) and are built in native-classes/AppUnit5E8_2008World.cpp against
// native-headers/v8world/SpatialHash2008.h.
// These two bodies cannot be built against engine-world v8world/World.h: there numLinkCalls / tempPrimitives sit 0xc
// lower (World() 005ea920 zeroes a second G3D::Array at +0xb8 that the header lacks) and the donor Primitive.h keeps
// joints in a linked list. This unit uses the NATIVE_WORLD_LAYOUT view of native-headers/v8world/World2008.h, the 2008
// Primitive of v8world/Primitive2008.h and the native Joint of v8world/Joints2008.h; ContactManager is the native
// v8world/ContactManager2008.h (batch 28: getPrimitivesTouchingExtents 0060d140 / onPrimitiveExtentsChanged 0060cc50 declared
// there) and the assembly is the 2008 Clump-based Assembly of v8world/AssemblyLayout.h (NATIVE_CLUMP_DECL).
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
#include "v8world/JointStage2008.h"
#include "v8world/CleanStage2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly (assemblyPrimBegin 005e5fa0 / End 005e5fc0)
#include "v8world/AssemblyLayout.h"
#include "v8world/SleepStage2008.h" // SleepStage::getAwakeAssemblies for computeFallen 005e9c40

namespace RBX
{
	// Unit-local copy of the donor tools/rbxgs v8world/JointBuilder.h declaration (that header includes the donor
	// v8world/Primitive.h, which cannot be combined with Primitive2008.h). 0064d410 ?canJoin@JointBuilder@RBX@@SAPAVJoint@2@PAVPrimitive@2@0@Z.
	class JointBuilder
	{
	public:
		static Joint* canJoin(Primitive* p0, Primitive* p1);
	};

	// File-static helper of the donor World.cpp (tools/openrbx v8world/World.cpp inIgnoreGroup, external-linkage free
	// function there; inline at every site, no code of its own in the 2008 binary). Batch 28 hypothesis for the register
	// residuals of 005ea4d0 / 005ea3f0: the ignore-group test as a helper holding its own null check.
	static bool inIgnoreGroup(std::set<Primitive*>* ignoreGroup, Primitive* p)
	{
		return ignoreGroup != NULL && ignoreGroup->find(p) != ignoreGroup->end();
	}

	// 005ea4d0 ?createJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z
	// (registry, reference vote; callers createJoints(Primitive*) 005ea5d0 and createJointsToWorld). Donor World.cpp body:
	// ++numLinkCalls (+0xec), tempPrimitives (+0xf0) resize(0, false) 00599a70, Primitive::getFastFuzzyExtents 005e7a50,
	// ContactManager::getPrimitivesTouchingExtents 0060d140, then per found primitive: set find 004ae060 against end(),
	// Primitive::getJoint(p0, p1) 005e7ce0, JointBuilder::canJoin 0064d410, insertJoint 005ea320 and the AutoJoin raise
	// 005e9940 under inJointNotification (+0xa5).
	// Batch 28: IDENTICAL to 005ea4d0 (252 B, relocations masked) with the inIgnoreGroup helper (batch 27 near miss 256 B:
	// p kept in ebx). Remaining blocker is registry only: the tempPrimitives resize call binds
	// ?resize@?$Array@PAVPrimitive@RBX@@@G3D@@QAEXH_N@Z to 005025c0 while the original calls 00599a70 (COMDAT twin; alias
	// proposal).
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

	// 005ea3f0 ?destroyJoints@World@RBX@@AAEXPAVPrimitive@2@PAV?$set@PAVPrimitive@RBX@@U?$less@PAVPrimitive@RBX@@@std@@V?$allocator@PAVPrimitive@RBX@@@4@@std@@@Z
	// (registry, reference vote). 2008 walks the joint array backwards by index (+0x3c size, Primitive 005e7ae0 per
	// index) where the donor follows getFirstJoint / getNextJoint; skips FREE_JOINT (9) and ANCHOR_JOINT (5) through the
	// virtual getJointType (slot 5), otherPrimitive inline (+0xc / +0x10), set find 004ae060, then the AutoDestroy raise
	// 005e99d0 on the +0x20 base under inJointNotification (+0xa5).
	// Batch 28: exact with the inIgnoreGroup helper (batch 27 near miss: end() register choice in the find block).
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

	// 005e91d0 (registry func_005e91d0; donor World::onAssemblyExtentsChanged, only caller Primitive::setCoordinateFrame
	// 005e8287): Assembly::assemblyPrimEnd 005e5fc0, then assemblyPrimBegin 005e5fa0, each primitive (++ 00647640) passed to
	// ContactManager::onPrimitiveExtentsChanged 0060cc50 through contactManager (+0x84). Moved here from
	// AppUnit5E8_2008World.cpp (batch 28), whose donor engine-world headers cannot see the 2008 Assembly.
	void World::onAssemblyExtentsChanged(Assembly* a)
	{
		PrimIterator end = a->assemblyPrimEnd();

		for (PrimIterator it = a->assemblyPrimBegin(); it != end; ++it)
		{
			contactManager->onPrimitiveExtentsChanged(*it);
		}
	}
	// 005e9e00 (registry placeholder func_005e9e00; openrbx World::doBreakJoints with destroyJoint inline: caller
	// World::step 005e9fd0): breakableJoints (+0xc4) walked with the iterator advanced before the test (++ 005e9340),
	// IPipelined::inKernel (currentStage slot 1 == 7, the kernel-stages StageType numbering) and Joint slot 7 isBroken,
	// then AutoDestroy raised on the +0x20 base (005e99d0) under inJointNotification (+0xa5).
	void World::doBreakJoints()
	{
		std::set<Joint*>::iterator it = breakableJoints.begin();

		while (it != breakableJoints.end())
		{
			Joint* joint = *it;
			++it;

			if (joint->inKernel() && joint->isBroken())
			{
				this->inJointNotification = true;
				Notifier<World, AutoDestroy>::raise(AutoDestroy(joint));
				this->inJointNotification = false;
			}
		}
	}

	// INFERRED: file-local helper (no code of its own): the 2008 moving test of an assembly (SleepInfo +0x18 behind a NULL
	// test, states AWAKE 3 / RECURSIVE_WAKE_PENDING 1 / WAKE_PENDING 2 in that order, as the SleepStage isMoving inline).
	static inline bool assemblyIsMoving(Assembly* a)
	{
		int state = AssemblyLayout::getSleepStatus(a);
		return state == 3 || state == 1 || state == 2;
	}

	// 005e9550 (registry placeholder func_005e9550; `ret 4`, caller World::step 005ea193); see World2008.h.
	void World::sub_005e9550(int unused)
	{
		for (int i = 0; i < primitives.size(); i++)
		{
			Primitive* p = primitives[i];
			Assembly* a = p->getAssembly();
			bool moving = assemblyIsMoving(a);

			if (moving && p != a->getRootClump()->getRootPrimitive())
				continue;

			p->getCoordinateFrame();

			if (!moving)
				p->getFastFuzzyExtents();
		}
	}

	// 005e9bb0 (registry placeholder func_005e9bb0; caller World::step 005e9fd0 inside a Profiling::Mark); see World2008.h.
	void World::sub_005e9bb0()
	{
		unknownB8.resize(0);

		for (int i = 0; i < primitives.size(); i++)
		{
			Primitive* p = primitives[i];
			Assembly* a = p->getAssembly();

			if (assemblyIsMoving(a))
			{
				unknownB8.append(p);

				if (p != a->getRootClump()->getRootPrimitive())
					p->getCoordinateFrame();

				p->getFastFuzzyExtents();
			}
		}
	}

	// 005e9c40 (registry placeholder func_005e9c40; openrbx World::computeFallen, caller Workspace::step 005a2580): IStage
	// findStage(SLEEP_STAGE 5) from the first stage (+0x88), the awake assemblies (+0x120), the assembly root primitive's
	// getCoordinateFrame 005e82c0 translation.y (+0x28) against [0083f8a0], then assemblyPrimEnd 005e5fc0 /
	// assemblyPrimBegin 005e5fa0 / ++ 00647640 and the inline G3D::Array::append.
	void World::computeFallen(G3D::Array<Primitive*>& fallen) const
	{
		const SleepStage::AssemblySet& awake = static_cast<SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE))->getAwakeAssemblies();

		for (SleepStage::AssemblySet::const_iterator cIt = awake.begin(); cIt != awake.end(); cIt++)
		{
			Assembly* assembly = *cIt;

			if (assembly->getRootClump()->getRootPrimitive()->getCoordinateFrame().translation.y < -500.0f)
			{
				PrimIterator pEnd = assembly->assemblyPrimEnd();

				for (PrimIterator it = assembly->assemblyPrimBegin(); it != pEnd; ++it)
				{
					Primitive* p = *it;

					if (p->getCoordinateFrame().translation.y < -500.0f)
						fallen.append(p);
				}
			}
		}
	}

	// insertPrimitive / removePrimitive: declared by v8world/World2008.h (the +0xac member is the donor IndexArray),
	// v8world/Primitive2008.h (worldIndexFunc, friend World) and v8world/ContactManager2008.h (onPrimitiveAdded 0060cc30
	// / onPrimitiveRemoved 0060cc40, `mov ecx, [ecx]` spatialHash, tail jumps) since batch 46. Measured batch 44 with
	// scratch copies: both IDENTICAL (005e98f0 69 B, 005ea8b0 99 B). The first stage (+0x88) is the CleanStage
	// (CleanStage2008.h: onPrimitiveAdded 0064a3e0 / onPrimitiveRemoving 0064a400, called directly, not through IStage).

	// 005e98f0 (registry placeholder func_005e98f0; openrbx World::insertPrimitive; caller PartInstance::onAncestorChanged
	// 0059ab3a): primitives.fastAppend (worldIndex +0x50 = size, Array::append 0059a190), world +0x58 = this, then the
	// first stage and the ContactManager.
	void World::insertPrimitive(Primitive* p)
	{
		primitives.fastAppend(p);
		p->world = this;

		static_cast<CleanStage*>(jointStage)->onPrimitiveAdded(p);
		contactManager->onPrimitiveAdded(p);
	}

	// 005ea8b0 (registry placeholder func_005ea8b0; openrbx World::removePrimitive; caller PartInstance::onAncestorChanged
	// 0059ab21): destroyJoints(p, NULL) 005ea3f0, ContactManager 0060cc40, first stage 0064a400, primitives.fastRemove
	// (last element moved into p's slot, resize 00599a70, worldIndex = -1), world = NULL.
	void World::removePrimitive(Primitive* p)
	{
		destroyJoints(p, NULL);

		contactManager->onPrimitiveRemoved(p);

		static_cast<CleanStage*>(jointStage)->onPrimitiveRemoving(p);

		primitives.fastRemove(p);

		p->world = NULL;
	}

}
