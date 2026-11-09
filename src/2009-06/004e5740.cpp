// from server: 100% by auto
// roc 2009-06 004e5740  unit: CRobloxWnd::UserInputJob  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5740
//
// 004e5740  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004e5743  85c0                 test eax, eax
// 004e5745  7429                 je 0x4e5770
// 004e5747  ff4118               inc dword ptr [ecx + 0x18]
// 004e574a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004e574d  57                   push edi
// 004e574e  8b7914               mov edi, dword ptr [ecx + 0x14]
// 004e5751  03ff                 add edi, edi
// 004e5753  03ff                 add edi, edi
// 004e5755  3bfa                 cmp edi, edx
// 004e5757  5f                   pop edi
// 004e5758  7707                 ja 0x4e5761
// 004e575a  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 004e5761  83c0ff               add eax, -1
// 004e5764  89411c               mov dword ptr [ecx + 0x1c], eax
// 004e5767  7507                 jne 0x4e5770
// 004e5769  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 004e5770  c3                   ret 
// standard library deque<ptr> (function ?pop_front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
