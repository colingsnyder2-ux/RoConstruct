// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_callbackreturn24copy588e163430274344.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Visit.h"
struct Text {char data[24];Text(const Text&);~Text();};
template void RBX::Reflection::BoundFuncDesc<RBX::Visit,Text(void),0>::call<Text>(RBX::Visit*, RBX::Reflection::Value&) const;
