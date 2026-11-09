// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_23e2bd1bdfa1e1b4.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "v8datamodel/ModelInstance.h"
#undef private
boost::shared_ptr<RBX::ModelInstance> cast_model(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::ModelInstance>(p); }