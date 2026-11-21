// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::CleanStage recovery, addresses 0064a420 / 0064a460 / 0064a510 (inactive draft).
// Statement order from the byte-exact analogs src/2008-06/0064a420.cpp, 0064a460.cpp, 0064a510.cpp.
// The 2008 bodies have no rbx_static_cast assertion, so the downstream stage is reached with a plain
// static_cast<IWorldStage*> rather than the donor IWorldStage::getDownstreamWS() inline.
#include "v8world/CleanStage2008.h"
#include "v8world/JointStage2008.h"
#include "v8world/Joints2008.h"

namespace RBX
{
	// 0064a420
	void CleanStage::sub_0064a420(Joint* j, Primitive* nulling)
	{
		if (j->downstreamOfStage(this))
			static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
	}

	// 0064a460
	void CleanStage::sub_0064a460(Joint* j, Primitive* p)
	{
		if (j->getPrimitive(0) && j->getPrimitive(1) && j->getPrimitive(0) != j->getPrimitive(1))
		{
			if (!j->downstreamOfStage(this))
				static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(j);
		}
		else
		{
			if (j->downstreamOfStage(this))
				static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
		}
	}

	// 0064a510
	void CleanStage::sub_0064a510(Edge* e)
	{
		if (e->downstreamOfStage(this))
			static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(e);
		e->removeFromPipeline(this);
	}
}
