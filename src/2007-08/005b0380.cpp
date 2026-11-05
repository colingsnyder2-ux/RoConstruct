// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_joint_c01627d41bb4ae47.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_inline_3639f053c7370446.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	Joint::Joint(
		Primitive* prim0,
		Primitive* prim1,
		const G3D::CoordinateFrame& _jointCoord0,
		const G3D::CoordinateFrame& _jointCoord1)
		: Edge(prim0, prim1),
		  assoc()
	{
		jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
		jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
	}

	Joint::Joint()
		: Edge(NULL, NULL),
		  assoc(),
		  jointCoord0(),
		  jointCoord1()
	{
		RBXASSERT(jointCoord0 == G3D::CoordinateFrame());
		RBXASSERT(jointCoord1 == G3D::CoordinateFrame());
	}

	Joint::~Joint()
	{
		RBXASSERT(!jointOwner);
	}

	void Joint::setPrimitive(int i, Primitive* p)
	{
		if (p != getPrimitive(i))
		{
			World* world = getWorld();
			if (world && getPrimitive(i))
				world->onJointPrimitiveNulling(this, getPrimitive(i));
			Edge::setPrimitive(i, p);
			if (world && p)
				world->onJointPrimitiveSet(this, p);
		}
	}

	void Joint::setJointCoord(int i, const G3D::CoordinateFrame& c)
	{
		if (c != getJointCoord(i))
		{
			if (i == 0)
				jointCoord0 = c;
			else
				jointCoord1 = c;

			World* world = getWorld();
			if (world)
			{
				world->removeJoint(this);
				world->insertJoint(this);
			}
		}
	}

	bool Joint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax)
	{
		if (!Math::fuzzyAxisAligned(p0->getCoordinateFrame().rotation, p1->getCoordinateFrame().rotation, angleMax))
			return false;

		Face f0 = p0->getFaceInWorld(nId0);
		Face f1 = p1->getFaceInWorld(nId1);
		if (!Face::hasOverlap(f0, f1, 0.35f))
			return false;

		if (!Face::overlapWithinPlanes(f0, f1, planarMax))
			return false;

		return true;
	}

	bool Joint::canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.05f, 0.05f);
	}

	bool Joint::canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.01f, 0.01f);
	}

	bool Joint::isAssemblyJoint(Edge* e)
	{
		return getJointType(e) >= ANCHOR_JOINT;
	}
}
