// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Joint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the Joint unit (00645490..006456e0, 00645750): the
// destructor 00645490, the constructors 006455c0 / 006456a0, the scalar deleting destructor 00645680 (vtable
// 0084ad44 is emitted here), canBuildJointTight 00645560 / canBuildJointLoose 00645590. canBuildJoint 006454b0 needs
// the native Primitive (getCoordinateFrame, getFaceInWorld) and is not part of this unit; setPrimitive 006456e0 and
// setJointCoord 00645750 use v8world/World2008.h and the 2008 IPipelined::getWorld of IPipelined2008.h (this unit
// opts in to the kernel-stages IStage, KERNEL_STAGE 7).
#include "v8world/Joints2008.h"
#include "v8world/World2008.h"
#include "util/Math.h"

namespace RBX
{
	// 006455c0
	Joint::Joint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
	             const G3D::CoordinateFrame& _jointCoord1)
		: Edge(prim0, prim1),
		  jointOwner(NULL),
		  active(false)
	{
		jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
		jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
	}

	// 006456a0
	Joint::Joint()
		: Edge(NULL, NULL),
		  jointOwner(NULL),
		  active(false),
		  jointCoord0(),
		  jointCoord1()
	{
	}

	// 00645490 (only restores the vtable)
	Joint::~Joint()
	{
	}

	// Built through the opt-in kernel-stages IStage (native-flags) and the 2008 IPipelined::getWorld inline of
	// IPipelined2008.h (KERNEL_STAGE 7), with the World declaration of v8world/World2008.h. Earlier trial (lf13): with
	// the donor getWorld (out of line, 85 B with asserts, KERNEL_STAGE 8) the body was not exact.
	// 006456e0: IPipelined::getWorld inline (KERNEL_STAGE 7 -> upstream), World::onJointPrimitiveNulling 005e9240,
	// Edge::setPrimitive 00659290, World::onJointPrimitiveSet 005e9250.
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

	// 00645750: CoordinateFrame::operator!= 004765e0, World::removeJoint 005ea3a0, World::insertJoint 005ea320.
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

	// 00645590
	bool Joint::canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.05f, 0.05f);
	}

	// 00645560
	bool Joint::canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.01f, 0.01f);
	}
}
