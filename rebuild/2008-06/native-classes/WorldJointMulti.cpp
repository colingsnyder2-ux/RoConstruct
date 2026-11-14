// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::MultiJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the MultiJoint unit (006468a0..00646ac0): init, both
// constructors, the destructor, putInKernel, addToMultiJoint, getPoint, removeFromKernel, isBroken and the scalar
// deleting destructor. getJointK 00646af0 follows the scalar deleting destructor 00646ac0 and reads the native
// Primitive's computed joint-K property (ComputeProp<float> +0xec of native-headers/v8world/Primitive2008.h), so this
// unit includes Primitive2008.h next to Joints2008.h (the pattern of AppUnit5E4MotorJoint.cpp).
// >>> native-status (generated) -- do not edit >>>
// WorldJointMulti | 2008-06 | draft (no current byte proof)
// 0/9 mapped addresses byte-exact | 9 unproved | no mapped strings | by auto (+1) (mixed 2)
// <<< native-status | src 7501bcc1 | roc native-status --write
#define NATIVE_IPIPELINED2008_DONOR   // Joints2008.h reaches the donor IPipelined through v8world/Edge.h
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"

namespace RBX
{
	// 006468a0
	void MultiJoint::init(int numBreaking)
	{
		numBreakingConnectors = numBreaking;
		numConnector = 0;

		for (int i = 0; i < 4; i++)
		{
			point[(i*2)] = NULL;
			point[(i*2)+1] = NULL;
			connector[i] = NULL;
		}
	}

	// 00646900
	MultiJoint::MultiJoint(int numBreaking)
		: Joint()
	{
		init(numBreaking);
	}

	// 00646920
	MultiJoint::MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0,
	                       const G3D::CoordinateFrame& jointCoord1, int numBreaking)
		: Joint(p0, p1, jointCoord0, jointCoord1)
	{
		init(numBreaking);
	}

	// 00646960 (vtable store, tail jump to ~Joint)
	MultiJoint::~MultiJoint()
	{
	}

	// 00646970 (tail jump to IPipelined::putInKernel 00645830)
	void MultiJoint::putInKernel(Kernel* _kernel)
	{
		IPipelined::putInKernel(_kernel);
	}

	// 00646980: IPipelined::getKernel 00645850, Kernel::insertConnector 005fb160.
	void MultiJoint::addToMultiJoint(Point* point0, Point* point1, Connector* _connector)
	{
		point[(numConnector*2)] = point0;
		point[(numConnector*2)+1] = point1;
		connector[numConnector] = _connector;

		getKernel()->insertConnector(_connector);
		++numConnector;
	}

	// 006469d0
	Point* MultiJoint::getPoint(int id)
	{
		return point[id];
	}

	// 006469e0: per connector Kernel::removeConnector 005fb1f0 and the virtual deleting destructor, then
	// Kernel::deletePoint 005fb3c0 for both points; tail jump to IPipelined::removeFromKernel 00645860.
	void MultiJoint::removeFromKernel()
	{
		for (int i = 0; i < numConnector; i++)
		{
			getKernel()->removeConnector(connector[i]);
			delete connector[i];

			getKernel()->deletePoint(point[(i*2)]);
			getKernel()->deletePoint(point[(i*2)+1]);
			point[(i*2)] = NULL;
			point[(i*2)+1] = NULL;
			connector[i] = NULL;
		}

		numConnector = 0;

		IPipelined::removeFromKernel();
	}

	// 00646a80: Connector slot 3 (getBroken)
	bool MultiJoint::isBroken() const
	{
		for (int i = 0; i < numBreakingConnectors; i++)
		{
			if (connector[i]->getBroken())
				return true;
		}

		return false;
	}

	// 00646af0 (?getJointK@MultiJoint@RBX@@IAEMXZ; callers 006466f5, 00646833, GlueJoint::putInKernel 0064734e):
	// both inline ComputeProp<float>::getValue (+0xec, dirty +0xf0, object +0xf4, getFunc +0xf8), prim1 (+0x10)
	// evaluated first, then the inline std::min. Needs /fp:fast (the sibling joint units' flags): without it the min
	// compare is `fstp; fld; fld; fcompp` (108 B) where the original keeps the value (`fst; fcomp [esp]`, 102 B).
	float MultiJoint::getJointK()
	{
		return std::min(getPrimitive(0)->getJointK(), getPrimitive(1)->getJointK());
	}
}
