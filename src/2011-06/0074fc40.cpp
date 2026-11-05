// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_dynamic_7e244a2254b0e965.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/Gui.h"
boost::shared_ptr<RBX::TextDisplay> cast_text(boost::shared_ptr<RBX::Instance> const& p) { return boost::dynamic_pointer_cast<RBX::TextDisplay>(p); }
