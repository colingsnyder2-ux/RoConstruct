// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_dynamic_82e412f75d8bd0e6.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Stats.h"
boost::shared_ptr<RBX::Stats::Item> cast_stats(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::Stats::Item>(p); }
