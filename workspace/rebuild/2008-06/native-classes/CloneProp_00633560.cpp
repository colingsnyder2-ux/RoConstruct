// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// Name registrations of the original Value unit (00634000 range) that AppUnit634_2008Value.cpp does not instantiate.
// 00633560 'jmp 006332d0' and 00633580 'jmp 006333b0': each tail-calls the doDeclare whose .data name relocation is
// 0095da08 ?sVector3Value@RBX@@3PADA / 0095da24 ?sColor3Value@RBX@@3PADA (registry), between callDoDeclare<sIntValue>
// 00633520 and callDoDeclare<sDoubleValue> 00633540 (AppUnit634_2008Value.cpp / ValueDouble2008.cpp).
// (The former sHint clone row here bound to no target: candidates 00401a00 / 00406700, identity not established.)
#include "v8datamodel/Value.h"
#include "util/Name.h"

template void RBX::Name::callDoDeclare<RBX::sVector3Value>(); // 00633560
template void RBX::Name::callDoDeclare<RBX::sColor3Value>();  // 00633580
