// 2008-06 native RBX::MultiJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the MultiJoint unit (006468a0..00646ac0): init, both
// constructors, the destructor, putInKernel, addToMultiJoint, getPoint, removeFromKernel, isBroken and the scalar
// deleting destructor. getJointK 00646af0 reads the native Primitive's computed joint-K property and is not part of
// this unit yet.
// >>> native-status (generated) -- do not edit >>>
// WorldJointMulti | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7501bcc1 | roc native-status --write
#include "v8world/Joints2008.h"
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
}
