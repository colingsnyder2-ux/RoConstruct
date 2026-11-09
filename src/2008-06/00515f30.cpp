// from server: 100% by auto
// roc 2008-06 00515f30  unit: G3D::BinaryInput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515f30
//
// 00515f30  8b442404             mov eax, dword ptr [esp + 4]
// 00515f34  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00515f38  3bc1                 cmp eax, ecx
// 00515f3a  740f                 je 0x515f4b
// 00515f3c  56                   push esi
// 00515f3d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00515f41  8a16                 mov dl, byte ptr [esi]
// 00515f43  8810                 mov byte ptr [eax], dl
// 00515f45  40                   inc eax
// 00515f46  3bc1                 cmp eax, ecx
// 00515f48  75f7                 jne 0x515f41
// 00515f4a  5e                   pop esi
// 00515f4b  c3                   ret 
// standard library vector<char> (function ??$_Fill@PADD@std@@YAXPAD0ABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
