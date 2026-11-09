// from server: 100% by auto
// roc 2007-08 0044ba60  unit: CRobloxControlColorSelector  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ba60
//
// 0044ba60  56                   push esi
// 0044ba61  8bf1                 mov esi, ecx
// 0044ba63  8b4604               mov eax, dword ptr [esi + 4]
// 0044ba66  85c0                 test eax, eax
// 0044ba68  57                   push edi
// 0044ba69  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0044ba6d  7419                 je 0x44ba88
// 0044ba6f  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044ba72  2bc8                 sub ecx, eax
// 0044ba74  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ba79  f7e9                 imul ecx
// 0044ba7b  d1fa                 sar edx, 1
// 0044ba7d  8bc2                 mov eax, edx
// 0044ba7f  c1e81f               shr eax, 0x1f
// 0044ba82  03c2                 add eax, edx
// 0044ba84  3bf8                 cmp edi, eax
// 0044ba86  7206                 jb 0x44ba8e
// 0044ba88  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044ba8e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044ba91  8d047f               lea eax, [edi + edi*2]
// 0044ba94  5f                   pop edi
// 0044ba95  8d0481               lea eax, [ecx + eax*4]
// 0044ba98  5e                   pop esi
// 0044ba99  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
