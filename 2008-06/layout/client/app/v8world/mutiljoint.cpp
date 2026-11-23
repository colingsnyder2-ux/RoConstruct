// =============================================================================
// mutiljoint.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/mutiljoint.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
