// from server: 100% by auto
// roc 2010-06 00558fe0  unit: G3D::BinaryInput  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558fe0
//
// 00558fe0  8b442404             mov eax, dword ptr [esp + 4]
// 00558fe4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00558fe8  3bc1                 cmp eax, ecx
// 00558fea  7413                 je 0x558fff
// 00558fec  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00558ff0  56                   push esi
// 00558ff1  668b32               mov si, word ptr [edx]
// 00558ff4  668930               mov word ptr [eax], si
// 00558ff7  83c002               add eax, 2
// 00558ffa  3bc1                 cmp eax, ecx
// 00558ffc  75f3                 jne 0x558ff1
// 00558ffe  5e                   pop esi
// 00558fff  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
