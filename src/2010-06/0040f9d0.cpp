// from server: 100% by auto
// roc 2010-06 0040f9d0  unit: CChatPrompt  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f9d0
//
// 0040f9d0  56                   push esi
// 0040f9d1  8bf1                 mov esi, ecx
// 0040f9d3  8b4610               mov eax, dword ptr [esi + 0x10]
// 0040f9d6  2b460c               sub eax, dword ptr [esi + 0xc]
// 0040f9d9  57                   push edi
// 0040f9da  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040f9de  c1f803               sar eax, 3
// 0040f9e1  3bf8                 cmp edi, eax
// 0040f9e3  7206                 jb 0x40f9eb
// 0040f9e5  ff150ca99e00         call dword ptr [0x9ea90c]
// 0040f9eb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0040f9ee  8d04f9               lea eax, [ecx + edi*8]
// 0040f9f1  5f                   pop edi
// 0040f9f2  5e                   pop esi
// 0040f9f3  c20400               ret 4
// standard library vector<double> (function ??A?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
