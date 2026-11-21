// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0062c0c0 ?remove@?$list@PAVFlagStand@RBX@@V?$allocator@PAVFlagStand@RBX@@@std@@@std@@QAEXABQAVFlagStand@RBX@@@Z:
// explicit member instantiation of std::list<FlagStand*>::remove (150 B). Identity: registry decorated name
// (identity-closure, unique body); the body sits in the FlagStandService object range (0062c0c0..0062c2e0, next to
// FindClosestEmptyStandForFlag 0062c2e0) and erases through the pointer-list erase 005888f0. The list is
// FlagStandService::flagStands (v8datamodel/FlagStandService.h); UnregisterFlagStand calls remove.
#include <list>

namespace RBX { class FlagStand; }

template void std::list<RBX::FlagStand *, std::allocator<RBX::FlagStand *> >::remove(RBX::FlagStand * const &); // 0062c0c0
