// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact loadGeoPairPointPlane 00607f90 (inactive draft).
// Evidence: native-headers/leaves2008/BlockBlockContact2008.h, donor v8world/Contact.cpp loadGeoPairPointPlane,
// donor v8world/Block.h getFaceVertex / v8kernel/Pair.h setPointPlane. Byte-exact analog src/2008-06/00607f90.cpp.
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
#include "v8kernel/Connector2008.h"
#include "v8world/Contact2008.h"
#include "v8world/Block2008.h"
#include "leaves2008/BlockBlockContact2008.h"

namespace RBX
{
	// donor v8world/Contact.h inline (declared in BlockBlockContact2008.h); needs the complete 2008 Block.
	inline Block* BlockBlockContact::block(int i)
	{
		return static_cast<Block*>(getPrimitive(i)->getGeometry());
	}

	// 00607f90: right-to-left evaluation builds the plane face vertex first, then the point vertex, then
	// setPointPlane stores normalID1, point0ID, offset0, offset1, geoPairType (connector +0x24/+0x28/+0xc/+0x10/+8).
	void BlockBlockContact::loadGeoPairPointPlane(int pointBody, int planeBody, int pointID, NormalId pointFaceID, NormalId planeFaceID)
	{
		ContactConnector* matched = matchContactConnector(
			getPrimitive(pointBody)->getBody(),
			getPrimitive(planeBody)->getBody(),
			POINT_PLANE_PAIR,
			pointID,
			planeFaceID);

		matched->getGeoPair().setPointPlane(
			planeFaceID,
			pointID,
			static_cast<Block*>(getPrimitive(pointBody)->getGeometry())->getFaceVertex(pointFaceID, pointID),
			static_cast<Block*>(getPrimitive(planeBody)->getGeometry())->getFaceVertex(planeFaceID, 0));
	}

	// 00607ea0 PARKED (three variants): 238 B, same size; first divergence at insn 60. The candidate loads
	// edge1 before geometry(b1), spills offset1 to +0x18 instead of +0x20, and schedules the two geometry loads
	// in the opposite order. Named locals (offset1 only, edgeBlock0, edgeBlock1) did not change the register plan.
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

		Block* edgeBlock1 = block(b1);
		const G3D::Vector3* offset1 = edgeBlock1->getEdgeVertex(edge1);
		Block* edgeBlock0 = block(b0);
		matched->setEdgeEdge(edgeBlock0->getEdgeVertex(edge0), offset1, edgeNormal0, edgeNormal1);
	}

	// 00608030: same scheduling idea; plane/edgeLength locals placed so the target's +0x14/+0x10 spill slots
	// (edgeLength / planeID) and the offset0-before-offset1 store order can be reproduced.
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

		// PARKED (three variants): 296 B, same size, but edgeLength/planeID spill slots (+0x14/+0x10) and the
		// offset0/offset1 store order are scheduled differently from the target. Best documented near-miss
		// (BlockBlockContactStep.cpp) kept; no source order found that reproduces the original register plan.
		matched->setEdgeEdgePlane(
			block(edgeBody)->getEdgeVertex(edge0),
			block(planeBody)->getEdgeVertex(edge1),
			edgeNormal0,
			edgeNormal1,
			plane,
			edgeLength);
	}
}
