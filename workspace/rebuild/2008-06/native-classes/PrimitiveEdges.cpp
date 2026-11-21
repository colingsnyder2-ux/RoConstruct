// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Primitive::getNextEdge 005e7b20 (inactive), a row of the original Primitive unit next to
// getFirstEdge 005e7b00 (native-classes/PrimitiveLifetime.cpp), getFirstJoint 005e7b90 and getNextJoint 005e7ba0
// (native-classes/PrimitiveState.cpp). Those units belong to other contributors, so this row has its own unit with
// the includes and flags of native-classes/PrimitiveState.cpp.
// Identity: declared INFERRED at 005e7b20 in native-headers/v8world/Primitive2008.h; the body walks prev's slot
// (Edge::getIndex: +0x14 when this is prim0 +0xc, else +0x18) like getNextJoint 005e7ba0, switching on the virtual
// Edge::getEdgeType (slot 3, +0xc): joints (+0x38 data / +0x3c size) then the first contact (+0x1c / +0x20). Donor
// tools/rbxgs v8world/Primitive.cpp getNextEdge (`next ? next : Joint::isJoint(e) ? contacts.first : NULL`).
#include <math.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"
#include "util/PV.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Contact2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"
#include "v8world/World2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 005e7b20
	Edge* Primitive::getNextEdge(Edge* prev) const
	{
		if (prev->getEdgeType() == Edge::JOINT)
		{
			int i = prev->getIndex(this) + 1;
			Edge* next = i < joints.edges.size() ? joints.edges[i] : NULL;
			if (next)
				return next;
			return contacts.edges.size() > 0 ? contacts.edges[0] : NULL;
		}
		else
		{
			int i = prev->getIndex(this) + 1;
			return i < contacts.edges.size() ? contacts.edges[i] : NULL;
		}
	}
}
