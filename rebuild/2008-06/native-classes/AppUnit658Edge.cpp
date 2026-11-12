// 2008-06 native RBX::Edge rows (inactive) of the Edge unit 00659260..006592a9, against
// native-headers/AppUnit658/Edge.h. Verified by tests/record_native_app_unit658.py.
#include "AppUnit658/Edge.h"

namespace RBX
{
	// 00659260
	Edge::Edge(Primitive* prim0, Primitive* prim1)
		: edgeState(Sim::UNDEFINED),
		  prim0(prim0),
		  prim1(prim1),
		  index0(-1),
		  index1(-1),
		  inEdgeList(false)
	{
	}

	// 00659290
	void Edge::setPrimitive(int i, Primitive* p)
	{
		if (i == 0)
			prim0 = p;
		else
			prim1 = p;
	}
}
