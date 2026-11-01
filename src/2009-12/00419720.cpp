// from server: 100% by auto
// roc 2009-12 00419720  unit: CRBXHTMLControlSite  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419720
//
// 00419720  56                   push esi
// 00419721  8bf1                 mov esi, ecx
// 00419723  8b06                 mov eax, dword ptr [esi]
// 00419725  57                   push edi
// 00419726  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041972a  85c0                 test eax, eax
// 0041972c  7404                 je 0x419732
// 0041972e  3b07                 cmp eax, dword ptr [edi]
// 00419730  7406                 je 0x419738
// 00419732  ff1560b79800         call dword ptr [0x98b760]
// 00419738  8b4604               mov eax, dword ptr [esi + 4]
// 0041973b  2b4704               sub eax, dword ptr [edi + 4]
// 0041973e  5f                   pop edi
// 0041973f  c1f803               sar eax, 3
// 00419742  5e                   pop esi
// 00419743  c20400               ret 4
// standard library vector<double> (function ??G?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBEHABV01@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
