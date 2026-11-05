// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/GettingUp.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/GettingUp.h"

#include "util/Name.h"

namespace RBX {

const char sGettingUp[] = "GettingUp";

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sGettingUp>();
template void RBX::Name::callDoDeclare<RBX::sGettingUp>();
