#include "v8kernel/Connector2008.h"

namespace RBX
{
	Body* PointToPointBreakConnector::getBody(int i)
	{
		return i == 0 ? point0->getBody() : point1->getBody();
	}

	RotateConnector::RotateConnector(Point* base0, Point* ray0, Point* ref0, Point* ref1, float kValue, float armLength)
		: k(kValue * armLength * armLength),
		  base0(base0),
		  ray0(ray0),
		  ref0(ref0),
		  ref1(ref1),
		  lastRotation(0.0f),
		  windings(0)
	{
	}

	Body* RotateConnector::getBody(int i)
	{
		return i == 0 ? ref0->getBody() : ref1->getBody();
	}

	float PointToPointBreakConnector::potentialEnergy()
	{
		float distance = (point1->getWorldPos() - point0->getWorldPos()).length();
		return k * distance * distance * 0.5f;
	}

	bool ContactConnector::canThrottle() const
	{
		return geoPair.getBody(0)->getCanThrottle() && geoPair.getBody(1)->getCanThrottle();
	}
}
