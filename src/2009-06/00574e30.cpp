// from server: 100% by auto
// roc 2009-06 00574e30  unit: G3D::BinaryInput  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574e30
//
// 00574e30  56                   push esi
// 00574e31  8bf1                 mov esi, ecx
// 00574e33  8b4610               mov eax, dword ptr [esi + 0x10]
// 00574e36  2b460c               sub eax, dword ptr [esi + 0xc]
// 00574e39  57                   push edi
// 00574e3a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00574e3e  c1f803               sar eax, 3
// 00574e41  3bf8                 cmp edi, eax
// 00574e43  7206                 jb 0x574e4b
// 00574e45  ff15ace98900         call dword ptr [0x89e9ac]
// 00574e4b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00574e4e  8d04f9               lea eax, [ecx + edi*8]
// 00574e51  5f                   pop edi
// 00574e52  5e                   pop esi
// 00574e53  c20400               ret 4
// standard library vector<double> (function ??A?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
