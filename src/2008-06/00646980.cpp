// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/MultiJoint.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/MultiJoint.h"

#include "decomp.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Kernel.h"
#include "v8world/Primitive.h"

#include <algorithm>
#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1011fc10
void MultiJoint::init(int numBreaking)
{
	this->numBreakingConnectors = numBreaking;
	numConnector = 0;

	for (int i = 0; i < 4; ++i) {
		point[i * 2] = NULL;
		point[i * 2 + 1] = NULL;
		connector[i] = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x1011fc70
MultiJoint::MultiJoint(int numBreaking)
{
	init(numBreaking);
}

// FUNCTION: WEBSERVICE 0x1011fc90
MultiJoint::MultiJoint(
	Primitive* p0,
	Primitive* p1,
	const CoordinateFrame& jointCoord0,
	const CoordinateFrame& jointCoord1,
	int numBreaking
)
	: Joint(p0, p1, jointCoord0, jointCoord1)
{
	init(numBreaking);
}

// FUNCTION: WEBSERVICE 0x1011fcd0
MultiJoint::~MultiJoint()
{
}

// FUNCTION: WEBSERVICE 0x1011fce0
void MultiJoint::putInKernel(Kernel* _kernel)
{
	IPipelined::putInKernel(_kernel);
}

// FUNCTION: WEBSERVICE 0x1011fcf0
void MultiJoint::addToMultiJoint(Point* point0, Point* point1, Connector* _connector)
{
	point[numConnector * 2] = point0;
	point[numConnector * 2 + 1] = point1;

	this->connector[numConnector] = _connector;

	getKernel()->insertConnector(_connector);

	++numConnector;
}

// FUNCTION: WEBSERVICE 0x1011fd40
Point* MultiJoint::getPoint(int id)
{
	return point[id];
}

// FUNCTION: WEBSERVICE 0x1011fd50
void MultiJoint::removeFromKernel()
{
	for (int i = 0; i < numConnector; ++i) {
		getKernel()->deletePoint(point[i * 2]);
		getKernel()->deletePoint(point[i * 2 + 1]);

		point[i * 2] = NULL;
		point[i * 2 + 1] = NULL;

		getKernel()->removeConnector(connector[i]);

		delete connector[i];

		connector[i] = NULL;
	}

	numConnector = 0;

	IPipelined::removeFromKernel();
}

// FUNCTION: WEBSERVICE 0x1011fdf0
bool MultiJoint::isBroken() const
{
	for (int i = 0; i < numBreakingConnectors; ++i) {
		if (connector[i]->getBroken()) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1011fe60
float MultiJoint::getJointK()
{
	float k1 = getPrimitive(1)->getJointK();
	float k0 = getPrimitive(0)->getJointK();

	return std::min(k0, k1);
}

} // namespace RBX
