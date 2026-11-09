// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_c44f118534f0d81e.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "roc_unit_ce7d53437b6472d5.cpp")
#include "roc_unit_06b51b5fb9d6afa0.cpp"
namespace RBX {
// Recovered delegated helper; cleanEdge is a native prototype/codegen analogue,
// not identification of the original helper name.
void TreeStage::cleanEdge(Edge* e) {
 if (e->downstreamOfStage(this)) getDownstreamWS()->onEdgeRemoving(e);
 eraseEdge(e);
}
void TreeStage::eraseEdge(Edge* e) {
 if (e->getInEdgeList()) {
  reinterpret_cast<std::set<Edge*>*>(reinterpret_cast<char*>(this) + 0x58)->erase(e);
  e->setInEdgeList(false);
 }
}
}
