// Source-derived helpers required by ClumpStage2/Assembly2/SleepStage2.
// Bodies from openrbx Guid.cpp, Primitive.cpp, MotorJoint.cpp and Link.cpp.
#include "util/Guid.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include "v8world/MotorJoint.h"
#include "v8kernel/Body.h"
namespace RBX {
using G3D::CoordinateFrame;
// Guid::compare(const Guid*, const Guid*): native (Guid.cpp). That body calls Name::compare(Name&, Name&)
// (native 0041faa0, not yet recovered); behavioural stand-in keeping the former ordering: identical
// scopes equal, NULL scope first, else name order.
inline int Name::compare(Name& a, Name& b)
{
	if (&a == &b)
		return 0;
	if (&a == NULL)
		return -1;
	if (&b == NULL)
		return 1;
	return a.name.compare(b.name);
}

int Guid::compare(const Guid* a0, const Guid* a1, const Guid* b0, const Guid* b1)
{
	int a = compare(a0, a1);
	int b = compare(b0, b1);
	const Guid* worseA = a == 1 ? a0 : a1;
	int order = compare(worseA, b == 1 ? b0 : b1);

	if (order != -1) {
		if (order != 0) {
			return order == 1;
		}

		const Guid* betterA = a == 1 ? a1 : a0;

		return compare(betterA, b == 1 ? b1 : b0);
	}

	return -1;
}

Primitive* Primitive::downstreamPrimitive(Joint* j)
{
	Primitive* answer = j->getPrimitive(0);
	Primitive* other = j->getPrimitive(1);

	if (other != NULL && answer->clumpDepth <= other->clumpDepth) {
		answer = other;
	}

	return answer;
}

RevoluteLink* MotorJoint::resetLink()
{
	int index = getPrimitive(1)->getBody()->getParent() != getPrimitive(0)->getBody();

	link->reset(index == 0 ? jointCoord0 : jointCoord1, index == 1 ? jointCoord0 : jointCoord1);

	link->setJointAngle(currentAngle);

	return link;
}

void Link::reset(const CoordinateFrame& parentC, const CoordinateFrame& childC)
{
	parentCoord = parentC;
	childCoord = childC;
	childCoordInverse = childC.inverse();
}
Sim::EdgeState Edge::getEdgeState() const { return edgeState; }
void Edge::setEdgeState(Sim::EdgeState value) { edgeState = value; }
bool Edge::getInEdgeList() const { return inEdgeList; }
void Edge::setInEdgeList(bool value) { inEdgeList = value; }
}
