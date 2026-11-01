// from server: 100% by auto
// roc 2009-12 0040f590  unit: CChatPrompt  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040f590
//
// 0040f590  56                   push esi
// 0040f591  8bf1                 mov esi, ecx
// 0040f593  8b4610               mov eax, dword ptr [esi + 0x10]
// 0040f596  2b460c               sub eax, dword ptr [esi + 0xc]
// 0040f599  57                   push edi
// 0040f59a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040f59e  c1f803               sar eax, 3
// 0040f5a1  3bf8                 cmp edi, eax
// 0040f5a3  7206                 jb 0x40f5ab
// 0040f5a5  ff1560b79800         call dword ptr [0x98b760]
// 0040f5ab  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0040f5ae  8d04f9               lea eax, [ecx + edi*8]
// 0040f5b1  5f                   pop edi
// 0040f5b2  5e                   pop esi
// 0040f5b3  c20400               ret 4
// standard library vector<double> (function ??A?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
