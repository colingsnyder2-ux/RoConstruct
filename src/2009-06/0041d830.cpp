// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_b57b21091ea11ae0.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "script/Script.h"
#undef private
boost::shared_ptr<RBX::Script> cast_script(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::Script>(p); }