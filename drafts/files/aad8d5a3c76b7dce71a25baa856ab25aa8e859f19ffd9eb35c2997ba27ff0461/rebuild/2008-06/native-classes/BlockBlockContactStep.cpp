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
// Parked: computePlaneContact 00608580 needs Body pv +0x94 without updatePV, the Block face-vertex table 0084aec8 and
// intersectRectQuad 00608160.
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
	// registry has only the placeholder func_00607cc0.
	ContactConnector* BlockBlockContact::matchContactConnector(Body* b0, Body* b1, GeoPairType _pairType, int param0, int param1)
	{
		for (int i = 0; i < matched.size(); i++)
		{
			if (matched[i] == false)
			{
				ContactConnector* connector = connectors[i];
				if (connector->match(b0, b1, _pairType, param0, param1))
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
