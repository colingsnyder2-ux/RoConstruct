// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact loadGeoPairEdgeEdge 00607ea0 / loadGeoPairEdgeEdgePlane 00608030.
// Statement order from the byte-exact mined analogs src/2008-06/00607ea0.cpp and src/2008-06/00608030.cpp.
// Real declarations: native-headers/leaves2008/BlockBlockContact2008.h and its included 2008 engine headers.
// Both functions proved byte-exact (238 B / 296 B) with identity by agent_prove.py 2026-11-19.
//
// GEO_BLOCK(i) loads Primitive::geometry (Primitive +0x9c, documented in Primitive2008.h) from the Edge's
// prim0/prim1 array (Edge +0xc, documented in Edge.h). The byte-exact analogs use the direct field chain
// `bodies[i]->faces`; the public inline accessors getPrimitive(i)->getGeometry() carry an inline-call
// boundary that makes MSVC evaluate the getEdgeVertex argument before the object pointer, changing the
// register/spill plan. The direct field access reproduces the original schedule. No struct is defined here.
//
// The std::pair<int,float> scratch reproduces the analog's `struct Saved { int value; float extent; }`
// stack layout (int in the lower slot +0x10, float in +0x14) without defining a type in this unit.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <utility>
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

	// Direct geometry-pointer load: Edge::prim0[i] (+0xc) -> Primitive::geometry (+0x9c).
	#define GEO_BLOCK(i) ((Block*)(*(char**)(*(char**)((char*)this + 0xc + 4*(i)) + 0x9c)))

	// 00607ea0: the analog loads the two bodies (second/b1 then first/b0) into locals before create, then
	// computes mappedSecond (b1) before mappedFirst (b0). Match that statement order with real classes.
	void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(b0)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(b1)->getEdgeNormal(edge1);

		Body* body1 = getPrimitive(b1)->getBody();
		Body* body0 = getPrimitive(b0)->getBody();
		ContactConnector* matched = matchContactConnector(body0, body1, EDGE_EDGE_PAIR, edgeNormal0, edgeNormal1);

		const G3D::Vector3* offset1 = GEO_BLOCK(b1)->getEdgeVertex(edge1);
		const G3D::Vector3* offset0 = GEO_BLOCK(b0)->getEdgeVertex(edge0);
		matched->setEdgeEdge(offset0, offset1, edgeNormal0, edgeNormal1);
	}

	// 00608030: analog loads primitive1 (b1) / primitive0 (b0) bodies before create, computes saved.extent
	// from geometry0 (b0) first, then id1 (b1) before id0 (b0), then stores in setEdgeEdgePlane order.
	void BlockBlockContact::loadGeoPairEdgeEdgePlane(int edgeBody, int planeBody, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(edgeBody)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(planeBody)->getEdgeNormal(edge1);

		Body* body1 = getPrimitive(planeBody)->getBody();
		Body* body0 = getPrimitive(edgeBody)->getBody();
		ContactConnector* matched = matchContactConnector(body0, body1, EDGE_EDGE_PLANE_PAIR, edgeNormal0, edgeNormal1);

		Block* geometry0 = GEO_BLOCK(edgeBody);
		std::pair<int, float> saved;
		saved.second = geometry0->getGridSize()[edgeNormal0 % 3];
		saved.first = planeID;

		const G3D::Vector3* offset1 = GEO_BLOCK(planeBody)->getEdgeVertex(edge1);
		const G3D::Vector3* offset0 = geometry0->getEdgeVertex(edge0);
		matched->setEdgeEdgePlane(offset0, offset1, edgeNormal0, edgeNormal1, (NormalId)saved.first, saved.second);
	}
}
