// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Seated.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Seated.h"

#include "util/Name.h"

namespace RBX {

const char sSeated[] = "Seated";

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sSeated>();
template void RBX::Name::callDoDeclare<RBX::sSeated>();
