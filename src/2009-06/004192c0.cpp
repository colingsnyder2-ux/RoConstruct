// from server: 100% by auto
// roc 2009-06 004192c0  unit: CRBXHTMLControlSite  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004192c0
//
// 004192c0  56                   push esi
// 004192c1  8bf1                 mov esi, ecx
// 004192c3  8b06                 mov eax, dword ptr [esi]
// 004192c5  57                   push edi
// 004192c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004192ca  85c0                 test eax, eax
// 004192cc  7404                 je 0x4192d2
// 004192ce  3b07                 cmp eax, dword ptr [edi]
// 004192d0  7406                 je 0x4192d8
// 004192d2  ff15ace98900         call dword ptr [0x89e9ac]
// 004192d8  8b4604               mov eax, dword ptr [esi + 4]
// 004192db  2b4704               sub eax, dword ptr [edi + 4]
// 004192de  5f                   pop edi
// 004192df  c1f803               sar eax, 3
// 004192e2  5e                   pop esi
// 004192e3  c20400               ret 4
// standard library vector<double> (function ??G?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBEHABV01@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
