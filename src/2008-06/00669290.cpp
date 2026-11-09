// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_a131fea3a0b22e82.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "roc_unit_06b51b5fb9d6afa0.cpp"
#include "v8world/Assembly.h"
#include "v8world/AssemblyStage.h"
namespace RBX {
void TreeStage::undirtyAssembly(Assembly* a)
{
	reinterpret_cast<std::set<Assembly*>*>(reinterpret_cast<char*>(this) + 0x38)->erase(a);

	if (a->inPipeline()) {
		if (a->downstreamOfStage(this)) {
			static_cast<AssemblyStage*>(getDownstream())->onAssemblyRemoving(a);
		}

		a->removeFromPipeline(this);
	}
}
}
