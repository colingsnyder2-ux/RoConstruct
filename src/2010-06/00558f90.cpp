// from server: 100% by auto
// roc 2010-06 00558f90  unit: G3D::BinaryInput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558f90
//
// 00558f90  8b442404             mov eax, dword ptr [esp + 4]
// 00558f94  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00558f98  3bc1                 cmp eax, ecx
// 00558f9a  740f                 je 0x558fab
// 00558f9c  56                   push esi
// 00558f9d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00558fa1  8a16                 mov dl, byte ptr [esi]
// 00558fa3  8810                 mov byte ptr [eax], dl
// 00558fa5  40                   inc eax
// 00558fa6  3bc1                 cmp eax, ecx
// 00558fa8  75f7                 jne 0x558fa1
// 00558faa  5e                   pop esi
// 00558fab  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
