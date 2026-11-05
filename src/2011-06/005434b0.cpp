// from server: 100% by auto
// roc 2011-06 005434b0  unit: G3D::BinaryInput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005434b0
//
// 005434b0  8b442404             mov eax, dword ptr [esp + 4]
// 005434b4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005434b8  3bc1                 cmp eax, ecx
// 005434ba  740f                 je 0x5434cb
// 005434bc  56                   push esi
// 005434bd  8b742410             mov esi, dword ptr [esp + 0x10]
// 005434c1  8a16                 mov dl, byte ptr [esi]
// 005434c3  8810                 mov byte ptr [eax], dl
// 005434c5  40                   inc eax
// 005434c6  3bc1                 cmp eax, ecx
// 005434c8  75f7                 jne 0x5434c1
// 005434ca  5e                   pop esi
// 005434cb  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
