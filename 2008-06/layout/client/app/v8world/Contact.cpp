#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Connector2008.h"
#include "v8world/Ball2008.h"
#include "v8world/Block2008.h"
#include "v8kernel/Body2008.h"
#include <G3D/Vector3int16.h>

namespace RBX
{
	static const IStage::StageType kernelStageType = static_cast<IStage::StageType>(7);

	// Donor v8world/Contact.h inline accessors declared in Contact2008.h (rbx_static_cast of getGeometry; no code of
	// their own).
	inline Ball* BallBlockContact::ball()
	{
		return static_cast<Ball*>(ballPrim()->getGeometry());
	}
	inline Block* BallBlockContact::block()
	{
		return static_cast<Block*>(blockPrim()->getGeometry());
	}

	bool BallBlockContact::computeIsColliding(int& onBorder, G3D::Vector3int16& clip, G3D::Vector3& projectionInBlock,
		float overlapIgnored)
	{
		Primitive* ballPrimitive = ballPrim();
		Primitive* blockPrimitive = blockPrim();

		if (Primitive::aaBoxCollide(*ballPrimitive, *blockPrimitive))
		{
			Body* ballBody = ballPrimitive->getBody();
			Body* blockBody = blockPrimitive->getBody();

			const PV& ballPV = ballBody->getPVUnsafe();
			const PV& blockPV = blockBody->getPVUnsafe();

			G3D::Vector3 blockToBall = ballPV.position.translation - blockPV.position.translation;

			projectionInBlock = blockPV.position.rotation.transpose() * blockToBall;

			block()->projectToFace(projectionInBlock, clip, onBorder);

			G3D::Vector3 blockPtWorld = blockPV.position.pointToWorldSpace(projectionInBlock);

			return (blockPtWorld - ballPV.position.translation).magnitude() < ball()->getRadius() - overlapIgnored;
		}

		return false;
	}

	bool BallBlockContact::stepContact()
	{
		G3D::Vector3int16 clip(0, 0, 0);
		G3D::Vector3 projectionInBlock(0.0f, 0.0f, 0.0f);
		int onBorder;

		if (BallBlockContact::computeIsColliding(onBorder, clip, projectionInBlock, 0.0f))
		{
			if (inStage(kernelStageType))
			{
				if (!ballBlockConnector)
					ballBlockConnector = createConnector(ballPrim()->getBody(), blockPrim()->getBody());

				const G3D::Vector3* offset;
				NormalId normId;
				GeoPairType ballInsideType;

				if (onBorder)
					ballInsideType = block()->getBallBlockInfo(onBorder, clip, offset, normId);
				else
					ballInsideType = block()->getBallInsideInfo(projectionInBlock, offset, normId);

				ballBlockConnector->setBallBlock(ball()->getRadius(), offset, normId, ballInsideType);
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
#include "AppUnit658/Edge.h"
#include "v8kernel/KernelIndex.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"

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

	int BlockBlockContact::intersectRectQuad(G3D::Vector2& planeRect, G3D::Vector2 (&otherQuad)[4])
	{
		bool quadCrossRect[4][4];

		bool quadIn[4] = {true, true, true, true};

		int foundCounter = 0;

		for (int i = 3; i >= 0; i--)
		{
			if (otherQuad[i].y <= planeRect.y)
			{
				quadCrossRect[0][i] = true;
			}
			else
			{
				quadCrossRect[0][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].x >= -planeRect.x)
			{
				quadCrossRect[1][i] = true;
			}
			else
			{
				quadCrossRect[1][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].y >= -planeRect.y)
			{
				quadCrossRect[2][i] = true;
			}
			else
			{
				quadCrossRect[2][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].x <= planeRect.x)
			{
				quadCrossRect[3][i] = true;
			}
			else
			{
				quadCrossRect[3][i] = false;
				quadIn[i] = false;
			}
		}

		for (int i = 3; i >= 0; i--)
		{
			if (quadIn[i])
			{
				loadGeoPairPointPlane(bOther, bPlane, i, otherPlaneID, planeID);
				foundCounter++;
			}
		}

		if (foundCounter == 4)
			return foundCounter;
		else
		{
			bool rectCrossQuad[4][4];
			G3D::Vector2 rect[4];
			rect[0] = G3D::Vector2(planeRect.x, planeRect.y);
			rect[1] = G3D::Vector2(-planeRect.x, planeRect.y);
			rect[2] = G3D::Vector2(-planeRect.x, -planeRect.y);
			rect[3] = G3D::Vector2(planeRect.x, -planeRect.y);

			bool rectIn[4] = {true, true, true, true};

			for (int i = 3; i >= 0; i--)
			{
				G3D::Vector2& current = otherQuad[i];
				G3D::Vector2& currentO = otherQuad[(i + 3) % 4];
				for (int j = 0; j < 4; j++)
				{
					G3D::Vector2 math1 = rect[j] - current;
					G3D::Vector2 math2 = currentO - current;

					if ((math2.x * math1.y) - (math2.y * math1.x) >= 0.0f)
					{
						rectCrossQuad[i][j] = true;
					}
					else
					{
						rectCrossQuad[i][j] = false;
						rectIn[j] = false;
					}
				}
			}

			int wasZero = foundCounter == 0;

			for (int i = 0; i < 4; i++)
			{
				if (rectIn[i])
				{
					loadGeoPairPointPlane(bPlane, bOther, i, planeID, otherPlaneID);
					foundCounter++;
				}
			}

			if (wasZero && foundCounter == 4)
				return foundCounter;
			else
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 3; j >= 0; j--)
					{
						if (quadCrossRect[i][j] != quadCrossRect[i][(j + 3) % 4] && rectCrossQuad[j][i] != rectCrossQuad[j][(i + 1) % 4])
						{
							loadGeoPairEdgeEdgePlane(bOther, bPlane, block(bOther)->faceVertexToEdge(otherPlaneID, (j + 3) % 4), block(bPlane)->faceVertexToEdge(planeID, i));
							foundCounter++;
						}
					}
				}
				return foundCounter;
			}
		}
	}

	int BlockBlockContact::computePlaneContact()
	{
		if (feature[0] >= 0)
		{
			planeID = (NormalId)feature[0];
			bPlane = 0;
			bOther = 1;
		}
		else
		{
			planeID = (NormalId)feature[1];
			bPlane = 1;
			bOther = 0;
		}

		const G3D::CoordinateFrame& otherFrame = getPrimitive(bOther)->getBody()->getPVUnsafe().position;
		const G3D::CoordinateFrame& planeFrame = getPrimitive(bPlane)->getBody()->getPVUnsafe().position;

		G3D::CoordinateFrame otherToPlane = planeFrame.inverse() * otherFrame;

		Block* otherBlock = block(bOther);
		Block* planeBlock = block(bPlane);

		G3D::Vector3 otherVertexPlaneCoords = Math::getWorldNormal(planeID, planeFrame);
		otherPlaneID = Math::getClosestObjectNormalId(-otherVertexPlaneCoords, otherFrame.rotation);

		G3D::Vector2 planeRect = planeBlock->getProjectedVertex(*(planeBlock->getFaceVertex(planeID, 0)), planeID);

		G3D::Vector2 otherQuad[4] = {};

		for (int i = 0; i < 4; i++)
		{
			G3D::Vector3 world = otherToPlane.pointToWorldSpace(*(otherBlock->getFaceVertex(otherPlaneID, i)));
			otherQuad[i] = otherBlock->getProjectedVertex(world, planeID);
		}
		return intersectRectQuad(planeRect, otherQuad);
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

#include "v8kernel/Kernel2008.h" // the 2008 Kernel (removeConnector 005fb1f0); formerly the donor v8kernel/Kernel.h
#include "v8kernel/Connector.h"

namespace RBX
{
	Contact::Contact(Primitive* prim0, Primitive* prim1)
		: Edge(prim0, prim1),
		  lastContactStep(-1),
		  steppingIndex(-1),
		  jointK(0),
		  elasticJointK(0),
		  kFriction(0)
	{
	}

	void Contact::deleteConnector(ContactConnector*& c)
	{
		getKernel()->removeConnector(c);
		delete c;
		c = NULL;
	}

	ContactConnector::ContactConnector(float _k, float _kNeg, float _kFriction)
		: geoPair()
	{
		k = _k;
		kNeg = _kNeg;
		kFriction = _kFriction;
		frictionOffset = G3D::Vector3::zero();
		firstApproach = 0;
		threshold = 0;
		forceMagLast = 0;
	}
}
