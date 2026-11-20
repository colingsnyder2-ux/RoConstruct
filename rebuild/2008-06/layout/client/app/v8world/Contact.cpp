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

	bool BlockBlockContact::getBestPlaneEdge(float overlapIgnored)
	{
		float bestPlaneLength = Math::inf();
		float bestEdgeLength = Math::inf();
		float lastPlaneLength = Math::inf();
		int lastFeature[2] = {feature[0], feature[1]};
		bool checkLastFeature = (lastFeature[0] >= 0 && lastFeature[0] < 6) || (lastFeature[1] >= 0 && lastFeature[1] < 6);

		for (int i = cachedBody; i < cachedBody + 2; i++)
		{
			int baseId = i % 2;
			int testId = (i + 1) % 2;

			const G3D::CoordinateFrame& primPV0 = getPrimitive(baseId)->getBody()->getPVUnsafe().position;
			const G3D::CoordinateFrame& primPV1 = getPrimitive(testId)->getBody()->getPVUnsafe().position;
			const G3D::Vector3* eBase = &block(baseId)->getExtent();
			const G3D::Vector3* eTest = &block(testId)->getExtent();

			G3D::Vector3 delta = primPV1.translation - primPV0.translation;
			G3D::Vector3 rotTransMul = delta * primPV0.rotation;

			for (int j = cachedAxis; j < cachedAxis + 3; j++)
			{
				int axisId = j % 3;

				float what = Math::taxiCabMagnitude(primPV0.rotation.getColumn(axisId) * primPV1.rotation * *eTest) + (*eBase)[axisId] - fabs(rotTransMul[axisId]);

				if (what > overlapIgnored)
				{
					if (checkLastFeature && lastFeature[baseId] % 3 == axisId)
						lastPlaneLength = what;

					if (what < bestPlaneLength)
					{
						bestPlaneLength = what;
						feature[baseId] = rotTransMul[axisId] > 0.0f ? axisId : axisId + 3;
						feature[testId] = -1;
						cachedBody = baseId;
						cachedAxis = axisId;
						planeContact = true;
					}
				}
				else
				{
					cachedBody = baseId;
					cachedAxis = axisId;
					Contact::contactFeatureMatches++;
					return false;
				}
			}
		}
		Contact::contactFeatureMisses++;

		if (checkLastFeature)
		{
			if (feature[0] != lastFeature[0] || feature[1] != lastFeature[1])
			{
				if (!(bestPlaneLength * 1.01f < lastPlaneLength))
				{
					bestPlaneLength = lastPlaneLength;
					feature[0] = lastFeature[0];
					feature[1] = lastFeature[1];
				}
			}
		}

		const G3D::CoordinateFrame& primPV0 = getPrimitive(0)->getBody()->getPVUnsafe().position;
		const G3D::CoordinateFrame& primPV1 = getPrimitive(1)->getBody()->getPVUnsafe().position;
		const G3D::Vector3* e0 = &block(0)->getExtent();
		const G3D::Vector3* e1 = &block(1)->getExtent();

		G3D::Vector3 p0p1 = primPV1.translation - primPV0.translation;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				G3D::Vector3 crossAxis = primPV0.rotation.getColumn(i).cross(primPV1.rotation.getColumn(j));
				if (crossAxis.unitize() <= 0.001f)
					return planeContact;

				float p0p1inCrossAxis = crossAxis.dot(p0p1);

				G3D::Vector3 crossAxisMulPV0rot = crossAxis * primPV0.rotation;
				G3D::Vector3 crossAxisMulPV1rot = crossAxis * primPV1.rotation;

				float what = Math::taxiCabMagnitude(crossAxisMulPV0rot * *e0) + Math::taxiCabMagnitude(crossAxisMulPV1rot * *e1) - fabs(p0p1inCrossAxis);
				if (what > overlapIgnored)
				{
					if (what < bestEdgeLength)
					{
						bestEdgeLength = what;

						if (what * 10.0f < bestPlaneLength)
						{
							if (p0p1inCrossAxis > 0.0f)
							{
								feature[0] = block(0)->getClosestEdge(primPV0.rotation, (NormalId)i, crossAxis) + 6;
								feature[1] = block(1)->getClosestEdge(primPV1.rotation, (NormalId)j, -crossAxis) + 6;
							}
							else
							{
								feature[0] = block(0)->getClosestEdge(primPV0.rotation, (NormalId)i, -crossAxis) + 6;
								feature[1] = block(1)->getClosestEdge(primPV1.rotation, (NormalId)j, crossAxis) + 6;
							}
							planeContact = false;
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
		return true;
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
