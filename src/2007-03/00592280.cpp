// from server: 100% by auto
// roc 2007-03 00592280  unit: seg_00590000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00592280
//
// 00592280  56                   push esi
// 00592281  8bf1                 mov esi, ecx
// 00592283  8b4610               mov eax, dword ptr [esi + 0x10]
// 00592286  85c0                 test eax, eax
// 00592288  7435                 je 0x5922bf
// 0059228a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0059228d  8b5608               mov edx, dword ptr [esi + 8]
// 00592290  8d4c08ff             lea ecx, [eax + ecx - 1]
// 00592294  8bc1                 mov eax, ecx
// 00592296  c1e804               shr eax, 4
// 00592299  3bd0                 cmp edx, eax
// 0059229b  7702                 ja 0x59229f
// 0059229d  2bc2                 sub eax, edx
// 0059229f  8b5604               mov edx, dword ptr [esi + 4]
// 005922a2  83e10f               and ecx, 0xf
// 005922a5  030c82               add ecx, dword ptr [edx + eax*4]
// 005922a8  51                   push ecx
// 005922a9  8d4e01               lea ecx, [esi + 1]
// 005922ac  ff1520e57700         call dword ptr [0x77e520]
// 005922b2  834610ff             add dword ptr [esi + 0x10], -1
// 005922b6  7507                 jne 0x5922bf
// 005922b8  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 005922bf  5e                   pop esi
// 005922c0  c3                   ret 
// standard library deque<char> (function ?pop_back@?$deque@DV?$allocator@D@std@@@std@@QAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
