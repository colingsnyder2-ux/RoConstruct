#include "AppUnit658/Edge.h"

namespace RBX
{
	Edge::Edge(Primitive* prim0, Primitive* prim1)
		: edgeState(Sim::UNDEFINED),
		  prim0(prim0),
		  prim1(prim1),
		  index0(-1),
		  index1(-1),
		  inEdgeList(false)
	{
	}

	void Edge::setPrimitive(int i, Primitive* p)
	{
		if (i == 0)
			prim0 = p;
		else
			prim1 = p;
	}
}
