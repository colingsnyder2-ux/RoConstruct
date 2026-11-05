#include "v8world/Edge.h"
#include "v8world/Primitive.h"

namespace RBX
{
	Edge::Edge(Primitive* prim0, Primitive* prim1)
		: prim0(prim0),
		  prim1(prim1),
		  edgeState(Sim::UNDEFINED),
		  index0(-1),
		  index1(-1),
		  inEdgeList(false)
	{
	}

	void Edge::setPrimitive(int i, Primitive* p)
	{
		RBXASSERT((i == 0) || (i == 1));

		if (i == 0)
			prim0 = p;
		else
			prim1 = p;
	}
}