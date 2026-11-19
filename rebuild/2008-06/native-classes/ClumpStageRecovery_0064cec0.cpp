// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::ClumpStage::onEdgeAdded 0064cec0 and onEdgeRemoving 0064cf10 (inactive). Evidence in
// native-headers/v8world/ClumpStage2008.h; vtable 0084b14c slots 4 / 5. Both bodies read the edge's slot 3
// (Edge::getEdgeType, JOINT == 0) and, for joints, the edge's slot 12 (Joint::canStepUi, offset 0x30), maintain the
// +0x10 set of Edge* pointers, and reach the IWorldStage base bodies (native-classes/AppUnit668IWorldStage.cpp:
// 00669cf0 onEdgeAdded / 00669d10 onEdgeRemoving) through a qualified non-virtual call. The call order differs per
// slot: onEdgeAdded forwards to the base first and then maintains the set; onEdgeRemoving erases from the set first
// and then forwards. The +0x10 set stores the Edge* argument itself (mov [local], esi; lea arg, &local).
// IWorldStage::onEdgeAdded / onEdgeRemoving come from the donor IWorldStage (included via ClumpStage2008.h); both
// bodies are built by native-classes/AppUnit668IWorldStage.cpp.
#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"

namespace RBX
{
	// 0064cec0
	void ClumpStage::onEdgeAdded(Edge* e)
	{
		IWorldStage::onEdgeAdded(e);
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.insert(entry);
		}
	}

	// 0064cf10
	void ClumpStage::onEdgeRemoving(Edge* e)
	{
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.erase(entry);
		}
		IWorldStage::onEdgeRemoving(e);
	}
}
