// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 IWorldStage::onEdgeAdded / onEdgeRemoving (inactive): the out-of-line bodies of the donor v8world/IWorldStage.h
// declarations (donor v8world/IWorldStage.cpp shape; RBXASSERTs compiled out). ClumpStage::onEdgeAdded 0064cec0 and
// onEdgeRemoving 0064cf10 call them non-virtually (0064cecc / 0064cf46). Verified by tests/record_native_app_unit668.py.
// IWorldStage::getMetric 0064a3d0 is built by native-classes/IWorldStage2008.cpp (kernel-stages owner), not here.
#include "v8world/IWorldStage.h"
#include "v8world/Edge.h"

namespace RBX
{
	// 00669cf0
	void IWorldStage::onEdgeAdded(Edge* e)
	{
		e->putInPipeline(this);
		getDownstreamWS()->onEdgeAdded(e);
	}

	// 00669d10
	void IWorldStage::onEdgeRemoving(Edge* e)
	{
		getDownstreamWS()->onEdgeRemoving(e);
		e->removeFromStage(this);
	}
}
