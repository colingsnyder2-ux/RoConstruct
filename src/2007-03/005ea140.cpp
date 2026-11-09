// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IWorldStage.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/IWorldStage.h"

#include "decomp.h"
#include "v8world/Primitive.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x10126da0
void IWorldStage::onEdgeAdded(Edge* e)
{
	e->putInPipeline(this);

	static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(e);
}

// FUNCTION: WEBSERVICE 0x10126dc0
void IWorldStage::onEdgeRemoving(Edge* e)
{
	static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(e);

	e->removeFromStage(this);
}

} // namespace RBX
