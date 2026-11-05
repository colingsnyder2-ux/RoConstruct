// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Running.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Running.h"

#include "util/Name.h"

namespace RBX {

const char sRunning[] = "Running";

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sRunning>();
template void RBX::Name::callDoDeclare<RBX::sRunning>();
