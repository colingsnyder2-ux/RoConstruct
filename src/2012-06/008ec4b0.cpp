// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_dynamic_dbd57f6ec402f31c.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"
boost::shared_ptr<RBX::PartInstance> cast_part(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::PartInstance>(p); }
