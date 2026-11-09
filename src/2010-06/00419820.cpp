// from server: 100% by auto
// roc 2010-06 00419820  unit: CRBXHTMLControlSite  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419820
//
// 00419820  56                   push esi
// 00419821  8bf1                 mov esi, ecx
// 00419823  8b06                 mov eax, dword ptr [esi]
// 00419825  57                   push edi
// 00419826  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041982a  85c0                 test eax, eax
// 0041982c  7404                 je 0x419832
// 0041982e  3b07                 cmp eax, dword ptr [edi]
// 00419830  7406                 je 0x419838
// 00419832  ff150ca99e00         call dword ptr [0x9ea90c]
// 00419838  8b4604               mov eax, dword ptr [esi + 4]
// 0041983b  2b4704               sub eax, dword ptr [edi + 4]
// 0041983e  5f                   pop edi
// 0041983f  c1f803               sar eax, 3
// 00419842  5e                   pop esi
// 00419843  c20400               ret 4
// standard library vector<double> (function ??G?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBEHABV01@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
