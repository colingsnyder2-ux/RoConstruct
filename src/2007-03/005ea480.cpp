// from server: 74% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8world/MutilJoint.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/MultiJoint.h"
#include "v8world/Primitive.h"

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

	MultiJoint::MultiJoint(
		Primitive* p0,
		Primitive* p1,
		const G3D::CoordinateFrame& jointCoord0,
		const G3D::CoordinateFrame& jointCoord1,
		int numBreaking)
		: Joint(p0, p1, jointCoord0, jointCoord1)
	{
		init(numBreaking);
	}

	MultiJoint::~MultiJoint()
	{
		RBXASSERT(connector[0] == NULL);
		RBXASSERT(numConnector == 0);
	}

	void MultiJoint::putInKernel(Kernel* _kernel)
	{
		IPipelined::putInKernel(_kernel);
	}

	void MultiJoint::addToMultiJoint(Point* point0, Point* point1, Connector* _connector)
	{
		RBXASSERT(numConnector < 4);

		point[(numConnector*2)] = point0;
		point[(numConnector*2)+1] = point1;
		connector[numConnector] = _connector;

		getKernel()->insertConnector(_connector);
		++numConnector;
	}

	Point* MultiJoint::getPoint(int id)
	{
		RBXASSERT(id < 8);
		RBXASSERT(point[id]);
		return point[id];
	}

	void MultiJoint::removeFromKernel()
	{
		RBXASSERT(this->inKernel());

		for (int i = 0; i < numConnector; i++)
		{
			RBXASSERT(point[(i*2)]);
			RBXASSERT(point[(i*2)+1]);

			getKernel()->deletePoint(point[(i*2)]);
			getKernel()->deletePoint(point[(i*2)+1]);
			point[(i*2)] = NULL;
			point[(i*2)+1] = NULL;

			RBXASSERT(connector[i]);

			getKernel()->removeConnector(connector[i]);
			delete connector[i];
			connector[i] = NULL;
		}

		numConnector = 0;

		IPipelined::removeFromKernel();
		RBXASSERT(!this->inKernel());
	}

	bool MultiJoint::isBroken() const
	{
		RBXASSERT(numBreakingConnectors <= numConnector);
		RBXASSERT(this->inKernel());

		for (int i = 0; i < numBreakingConnectors; i++)
		{
			RBXASSERT(connector[i]);
			if (connector[i]->getBroken())
				return true;
		}

		return false;
	}

	float MultiJoint::getJointK()
	{
		float k1 = getPrimitive(1)->getJointK();
		float k0 = getPrimitive(0)->getJointK();

		return G3D::min(k0, k1);
	}
}