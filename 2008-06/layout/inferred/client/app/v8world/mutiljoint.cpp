#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"

namespace RBX
{
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

	MultiJoint::MultiJoint(int numBreaking)
		: Joint()
	{
		init(numBreaking);
	}

	MultiJoint::MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0,
	                       const G3D::CoordinateFrame& jointCoord1, int numBreaking)
		: Joint(p0, p1, jointCoord0, jointCoord1)
	{
		init(numBreaking);
	}

	MultiJoint::~MultiJoint()
	{
	}

	void MultiJoint::putInKernel(Kernel* _kernel)
	{
		IPipelined::putInKernel(_kernel);
	}

	void MultiJoint::addToMultiJoint(Point* point0, Point* point1, Connector* _connector)
	{
		point[(numConnector*2)] = point0;
		point[(numConnector*2)+1] = point1;
		connector[numConnector] = _connector;

		getKernel()->insertConnector(_connector);
		++numConnector;
	}

	Point* MultiJoint::getPoint(int id)
	{
		return point[id];
	}

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

	bool MultiJoint::isBroken() const
	{
		for (int i = 0; i < numBreakingConnectors; i++)
		{
			if (connector[i]->getBroken())
				return true;
		}

		return false;
	}

	float MultiJoint::getJointK()
	{
		return std::min(getPrimitive(0)->getJointK(), getPrimitive(1)->getJointK());
	}
}
