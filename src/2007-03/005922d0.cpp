// from server: 100% by auto
// roc 2007-03 005922d0  unit: seg_00590000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005922d0
//
// 005922d0  56                   push esi
// 005922d1  8bf1                 mov esi, ecx
// 005922d3  837e1000             cmp dword ptr [esi + 0x10], 0
// 005922d7  7440                 je 0x592319
// 005922d9  8b460c               mov eax, dword ptr [esi + 0xc]
// 005922dc  8b5604               mov edx, dword ptr [esi + 4]
// 005922df  8bc8                 mov ecx, eax
// 005922e1  c1e904               shr ecx, 4
// 005922e4  83e00f               and eax, 0xf
// 005922e7  03048a               add eax, dword ptr [edx + ecx*4]
// 005922ea  8d4e01               lea ecx, [esi + 1]
// 005922ed  50                   push eax
// 005922ee  ff1520e57700         call dword ptr [0x77e520]
// 005922f4  83460c01             add dword ptr [esi + 0xc], 1
// 005922f8  8b4e08               mov ecx, dword ptr [esi + 8]
// 005922fb  8b460c               mov eax, dword ptr [esi + 0xc]
// 005922fe  c1e104               shl ecx, 4
// 00592301  3bc8                 cmp ecx, eax
// 00592303  7707                 ja 0x59230c
// 00592305  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0059230c  834610ff             add dword ptr [esi + 0x10], -1
// 00592310  7507                 jne 0x592319
// 00592312  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00592319  5e                   pop esi
// 0059231a  c3                   ret 
// standard library deque<char> (function ?pop_front@?$deque@DV?$allocator@D@std@@@std@@QAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
