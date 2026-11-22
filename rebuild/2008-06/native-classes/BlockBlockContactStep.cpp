// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact step path (inactive): computeIsColliding 00607c20, matchContactConnector
// 00607cc0, loadGeoPairEdgeEdge 00607ea0 and stepContact 00608830 (the Contact unit 00606b00..00608950).
// Field evidence: native-headers/leaves2008/BlockBlockContact2008.h (vtable 00843714, size 0x7c). Donor bodies:
// tools/rbxgs v8world/Contact.cpp (BlockBlockContact::matchContactConnector / loadGeoPairEdgeEdge).
//
// Declarations: the shared headers, included on the 2008 Body path (NATIVE_PRIMITIVE_NATIVE_BODY):
// v8world/Primitive2008.h (with the inline static aaBoxCollide read by 00607c20 / 00608830), v8kernel/Connector2008.h,
// v8world/GeoPair2008.h, v8world/Contact2008.h, v8world/Block2008.h and leaves2008/BlockBlockContact2008.h. No
// unit-local redeclaration is left. The bases IPipelined / Edge are the native 2008 ones (AppUnit658/Edge.h ->
// v8kernel/IPipelined2008.h).
// deleteUnmatchedConnectors 00607e00 is in Leaves2008BlockBlockContact.cpp (beside deleteAllConnectors 00607c60).
// intersectRectQuad 00608160 and computePlaneContact 00608580 (near miss) are here too (batch 39).
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

#include "v8world/Primitive2008.h"

// The shared 2008 declarations (batch 16): v8kernel/Connector2008.h on the 2008 Body path (Body2008.h / GeoPair2008.h
// / Point2008.h, with the match / setEdgeEdge / setBody forwarders), v8world/Contact2008.h (createConnector 00606e00,
// contactPairMatches / contactPairMisses), v8world/Block2008.h (getEdgeNormal, getEdgeVertex 00606b00; now on
// GeoPair2008.h) and leaves2008/BlockBlockContact2008.h (matchContactConnector 00607cc0, getBestPlaneEdge 00607280,
// block(int)). They replace the former unit-local GeoPair / Connector / ContactConnector / Contact / Block /
// BlockBlockContact / Primitive / EdgeList copies.
#include "v8kernel/Connector2008.h"
#include "v8world/Contact2008.h"
#include "v8world/Block2008.h"
#include "leaves2008/BlockBlockContact2008.h"

namespace RBX
{
	// Donor v8world/Contact.h inline (declared in BlockBlockContact2008.h; loadGeoPairEdgeEdge 00607ea0 reads the
	// geometry +0x9c of the primitive, 00607f3e..00607f42).
	inline Block* BlockBlockContact::block(int i)
	{
		return static_cast<Block*>(getPrimitive(i)->getGeometry());
	}

	// 00607280 (`ret 4`; header leaves2008/BlockBlockContact2008.h): donor v8world/Contact.cpp
	// BlockBlockContact::getBestPlaneEdge(bool& planeContact, float). The 2008 one keeps planeContact in the member
	// +0x5c, reads the body pv +0x94 without updatePV (Body::getPVUnsafe), the Block vertices +0x10 (getExtent), and
	// counts the cached separating axis: contactFeatureMatches 0097b888 when the cached body / axis still separates
	// (00607588), contactFeatureMisses 0097b88c after the plane loop (00607548). 10.0f is the float 00827490.
	// Not exact yet (batch 24): 1646 B against 1634, same control flow, calls, stores and constants. The divergences
	// are x87 operand order and stack slots only: in the plane loop the target forms column * rotation as
	// c.x*m00 + c.z*m20 + c.y*m10 and takes fabs before each product with *eTest (this build: m20*c.z first, all three
	// products, then fabs); in the edge loop the target keeps crossAxis * rotation in memory locals and its cross
	// product loads this-side operands first. Rejected: the native-flags without /fp:fast (1925 B, every float spilled,
	// and the unit loses exacts) and `*eTest * (column * rotation)` (1646 B, unchanged diff).
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

	// 00607c20
	bool BlockBlockContact::computeIsColliding(float overlapIgnored)
	{
		return Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(overlapIgnored);
	}

	// 00607cc0: donor v8world/Contact.cpp body; the 2008 one passes the bodies to createConnector 00606e00 and, after
	// a match, writes them into the matched connector (match accepts both body orders). Not exact yet: 316 B, same
	// instructions and stores, but this / i are allocated to esi / edi (original edi / esi) and connectors[i] is loaded
	// before the match arguments are pushed (original after). Rejected: a direct connectors[i]->geoPair.match call
	// (318 B) and a single `!matched[i] && ...` condition (unchanged). Batch 15 rejected: friend + direct
	// connectors[i]->geoPair.match (318 B: &data[i] early, deref late) and ContactConnector deriving from GeoPair at +0x8
	// (same 318 B). Batch 16: on the shared Connector2008.h / GeoPair2008.h / Contact2008.h declarations the diff is
	// unchanged (316 B, first divergence at insn 6: this / i in esi / edi, connectors[i] loaded into eax before the
	// pushes and `lea ecx, [eax + 8]`; the original loads it into ecx after `push param1` and adds 8). The identity
	// registry has only the placeholder func_00607cc0. Batch 17 rejected: connectors[i] in a named local before the
	// match call (316 B, unchanged diff at insn 6).
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

	// 00607ea0: donor v8world/Contact.cpp body; the 2008 setEdgeEdge leaves the bodies to matchContactConnector.
	// Not exact yet: 240 B against 238; identical up to the first getEdgeVertex call, then this build loads both
	// Block pointers before it (the original loads block(b0) after it) and stores offset0 after the normals.
	// Rejected: direct matched->geoPair.setEdgeEdge (unchanged); batch 15: donor body arguments passed and ignored
	// (unchanged); block(int) out of line and auto-inlined (unchanged). Closest (238 B, same size, register / spill
	// slot differences only): separate statements offset1 = block(b1)->getEdgeVertex(edge1), then offset0, then
	// setEdgeEdge(offset0, offset1, ...); not kept (no evidence for that source order). Batch 16 (shared headers):
	// unchanged 240 B; rejected: the call chained on the matchContactConnector result (252 B, the edge normals move
	// after the prologue), the separate-statement form again (238 B, same register / spill-slot diff at insn 60), and
	// named Block* locals for block(b1) / block(b0) (238 B, identical to the separate-statement form). In the original
	// block(b) is loaded before the edge argument of each getEdgeVertex call and offset1 is spilled to the edge1 slot.
	// Batch 17 rejected: only offset1 as a named local, offset0 left inside the setEdgeEdge call (238 B, the same
	// insn-60 diff as the separate-statement form).
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

	// 00608030: donor v8world/Contact.cpp body; the 2008 setEdgeEdgePlane leaves the bodies to matchContactConnector.
	// Not exact yet: 296 B, same size; edgeLength / planeID are spilled as in the original ([esp+0x14] / [esp+0x10]
	// slots swapped) but the second getEdgeVertex argument load and the +0xc / +0x10 store order are scheduled
	// differently. Rejected: no locals (292 B, no spill), only the block pointer in a local (same diff), offset1 in
	// a named local (308 B), local declaration order swapped (296 B, planeID load moves before the block load).
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

	// 00608160 (`ret 8`; header leaves2008/BlockBlockContact2008.h): donor v8world/Contact.cpp
	// BlockBlockContact::intersectRectQuad. The rect/quad classification loop is unrolled (quadIn [esp+0x10],
	// quadCrossRect [esp+0x18], rectCrossQuad [esp+0x28], rect [esp+0x38], rectIn in the dead planeRect argument
	// slot); no RBXASSERT survives in the release body.
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

	// 00608580 (?computePlaneContact@BlockBlockContact@RBX@@AAEHXZ, `ret`): donor v8world/Contact.cpp body. Called by
	// updateConnectors 006087a0 when planeContact +0x5c is set. The 2008 one reads the body pv +0x94 without updatePV
	// (00608585..006085cb: Primitive +0xa0 -> Body, `add reg, 0x94`), calls CoordinateFrame::inverse 00478330 and
	// operator* 00476700, inlines Math::getWorldNormal (`imul 0x55555556` = id / 3, id % 3 column, 1 - 2 * (id / 3)),
	// calls getClosestObjectNormalId 005de560 on the negated normal, Block::getProjectedVertex 00647c70 on the plane
	// block (geometry +0x9c) and then on the other block for each of the four zero-initialised quad corners
	// (face-vertex table 0084aec8), and returns intersectRectQuad 00608160.
	// Near miss (batch 39: the guard is gone, intersectRectQuad 00608160 is declared in
	// leaves2008/BlockBlockContact2008.h and defined above). Batch 31 measured 513 B against 531 with a scratch
	// header (frame 0xa0 against 0x80). In this unit, with the real declaration and the intersectRectQuad body
	// beside it, it is 531 B against 531 with the same frame; the first divergence is insn 62 (0060864a): the
	// scalar * Vector3 of the inlined getWorldNormal (target `fld st0; fmulp st3`, here `fmul st2, st0`), then the
	// x87 row-sum order in the inlined pointToWorldSpace (target y*m01 + z*m02 + x*m00). Both are the batch 27
	// exhausted x87 commutative-operand category; no trials spent on them. Rejected (batch 31):
	// the normal as an unnamed temporary (unchanged), `G3D::Vector2 otherQuad[4];` without `= {}` (unchanged),
	// planeFrame.toObjectSpace(otherFrame) (503 B, emits an out-of-line toObjectSpace call instead of
	// inverse 00478330 + operator* 00476700).
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

	// 00608830: separation -1.0f (0081c3b8) when colliding, else 1e9 (0082d030); then updateConnectors 006087a0.
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
