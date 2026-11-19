#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <math.h>
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Connector2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Ball2008.h"
#include "util/Math.h"

namespace RBX
{
	static const IStage::StageType kernelStageType = static_cast<IStage::StageType>(7);

	// Donor v8world/Contact.h inline accessor declared in Contact2008.h (rbx_static_cast of getGeometry; no code of its
	// own).
	inline Ball* BallBallContact::ball(int i)
	{
		return static_cast<Ball*>(getPrimitive(i)->getGeometry());
	}

	bool BallBallContact::computeIsColliding(float overlapIgnored)
	{
		float b0Radius = ball(0)->getRadius();
		float b1Radius = ball(1)->getRadius();

		G3D::Vector3 delta = getPrimitive(1)->getBody()->getPVUnsafe().position.translation
			- getPrimitive(0)->getBody()->getPVUnsafe().position.translation;
		float b0b1RadiusSum = b0Radius + b1Radius;

		if (b0b1RadiusSum > Math::longestVector3Component(delta))
			return delta.magnitude() < (b0b1RadiusSum - overlapIgnored);
		else
			return false;
	}

	bool BallBallContact::stepContact()
	{
		if (BallBallContact::computeIsColliding(0.0f))
		{
			if (inStage(kernelStageType))
			{
				if (!ballBallConnector)
					ballBallConnector = createConnector(getPrimitive(0)->getBody(), getPrimitive(1)->getBody());

				ballBallConnector->setBallBall(ball(0)->getRadius(), ball(1)->getRadius());
			}
			return true;
		}
		else
		{
			deleteAllConnectors();
		}

		return false;
	}
}

#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3int16.h>
#include "AppUnit658/Edge.h"
#include "v8kernel/KernelIndex.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"

#include "v8world/Block2008.h"
#include "leaves2008/BlockBlockContact2008.h"

namespace RBX
{
	inline Block* BlockBlockContact::block(int i)
	{
		return static_cast<Block*>(getPrimitive(i)->getGeometry());
	}

	bool BlockBlockContact::computeIsColliding(float overlapIgnored)
	{
		return Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(overlapIgnored);
	}

	ContactConnector* BlockBlockContact::matchContactConnector(Body* b0, Body* b1, GeoPairType _pairType, int param0, int param1)
	{
		for (int i = 0; i < matched.size(); i++)
		{
			if (matched[i] == false)
			{
				if (connectors[i]->match(b0, b1, _pairType, param0, param1))
				{
					matched[i] = true;
					Contact::contactPairMatches++;
					connectors[i]->setBody(0, b0);
					connectors[i]->setBody(1, b1);
					return connectors[i];
				}
			}
		}

		Contact::contactPairMisses++;
		ContactConnector* connector = createConnector(b0, b1);
		connectors.append(connector);
		matched.append(true);
		return connector;
	}

	void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(b0)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(b1)->getEdgeNormal(edge1);

		ContactConnector* matched = matchContactConnector(
			getPrimitive(b0)->getBody(),
			getPrimitive(b1)->getBody(),
			EDGE_EDGE_PAIR,
			edgeNormal0,
			edgeNormal1);

		matched->setEdgeEdge(
			block(b0)->getEdgeVertex(edge0),
			block(b1)->getEdgeVertex(edge1),
			edgeNormal0,
			edgeNormal1);
	}

	void BlockBlockContact::loadGeoPairEdgeEdgePlane(int edgeBody, int planeBody, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(edgeBody)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(planeBody)->getEdgeNormal(edge1);

		ContactConnector* matched = matchContactConnector(
			getPrimitive(edgeBody)->getBody(),
			getPrimitive(planeBody)->getBody(),
			EDGE_EDGE_PLANE_PAIR,
			edgeNormal0,
			edgeNormal1);

		const G3D::Vector3& gridSize = getPrimitive(edgeBody)->getGeometry()->getGridSize();
		float edgeLength = gridSize[edgeNormal0 % 3];
		NormalId plane = planeID;

		matched->setEdgeEdgePlane(
			block(edgeBody)->getEdgeVertex(edge0),
			block(planeBody)->getEdgeVertex(edge1),
			edgeNormal0,
			edgeNormal1,
			plane,
			edgeLength);
	}

	bool BlockBlockContact::stepContact()
	{
		if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(0.0f))
			separation = -1.0f;
		else
			separation = 1e9f;
		updateConnectors();
		return separation <= 0.0f;
	}
}
