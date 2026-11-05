// from server: 100% by auto
// roc 2011-06 005434d0  unit: G3D::BinaryInput  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005434d0
//
// 005434d0  8b442404             mov eax, dword ptr [esp + 4]
// 005434d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005434d8  3bc1                 cmp eax, ecx
// 005434da  7413                 je 0x5434ef
// 005434dc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005434e0  56                   push esi
// 005434e1  668b32               mov si, word ptr [edx]
// 005434e4  668930               mov word ptr [eax], si
// 005434e7  83c002               add eax, 2
// 005434ea  3bc1                 cmp eax, ecx
// 005434ec  75f3                 jne 0x5434e1
// 005434ee  5e                   pop esi
// 005434ef  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
