// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_e1a01b692367fffa.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DataModel.h"
boost::shared_ptr<RBX::DataModel> cast_dm(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::DataModel>(p); }
