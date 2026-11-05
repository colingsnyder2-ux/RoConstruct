// from server: 100% by auto
// roc 2007-03 0044a2d0  unit: seg_00440000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044a2d0
//
// 0044a2d0  56                   push esi
// 0044a2d1  8bf1                 mov esi, ecx
// 0044a2d3  8b4604               mov eax, dword ptr [esi + 4]
// 0044a2d6  85c0                 test eax, eax
// 0044a2d8  57                   push edi
// 0044a2d9  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0044a2dd  7419                 je 0x44a2f8
// 0044a2df  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044a2e2  2bc8                 sub ecx, eax
// 0044a2e4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044a2e9  f7e9                 imul ecx
// 0044a2eb  d1fa                 sar edx, 1
// 0044a2ed  8bc2                 mov eax, edx
// 0044a2ef  c1e81f               shr eax, 0x1f
// 0044a2f2  03c2                 add eax, edx
// 0044a2f4  3bf8                 cmp edi, eax
// 0044a2f6  7206                 jb 0x44a2fe
// 0044a2f8  ff1544e97700         call dword ptr [0x77e944]
// 0044a2fe  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044a301  8d047f               lea eax, [edi + edi*2]
// 0044a304  5f                   pop edi
// 0044a305  8d0481               lea eax, [ecx + eax*4]
// 0044a308  5e                   pop esi
// 0044a309  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
