// from server: 100% by auto
// roc 2008-06 00515ea0  unit: G3D::BinaryInput  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515ea0
//
// 00515ea0  56                   push esi
// 00515ea1  8bf1                 mov esi, ecx
// 00515ea3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00515ea6  2b460c               sub eax, dword ptr [esi + 0xc]
// 00515ea9  57                   push edi
// 00515eaa  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00515eae  d1f8                 sar eax, 1
// 00515eb0  3bf8                 cmp edi, eax
// 00515eb2  7206                 jb 0x515eba
// 00515eb4  ff1590288000         call dword ptr [0x802890]
// 00515eba  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00515ebd  8d0479               lea eax, [ecx + edi*2]
// 00515ec0  5f                   pop edi
// 00515ec1  5e                   pop esi
// 00515ec2  c20400               ret 4
// standard library vector<short> (function ??A?$vector@FV?$allocator@F@std@@@std@@QBEABFI@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
