// from server: 100% by auto
// roc 2010-06 00752d60  unit: RBX::PrismPoly  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752d60
//
// 00752d60  56                   push esi
// 00752d61  8bf1                 mov esi, ecx
// 00752d63  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00752d66  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00752d69  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00752d6e  f7e9                 imul ecx
// 00752d70  c1fa03               sar edx, 3
// 00752d73  8bc2                 mov eax, edx
// 00752d75  c1e81f               shr eax, 0x1f
// 00752d78  57                   push edi
// 00752d79  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00752d7d  03c2                 add eax, edx
// 00752d7f  3bf8                 cmp edi, eax
// 00752d81  7206                 jb 0x752d89
// 00752d83  ff150ca99e00         call dword ptr [0x9ea90c]
// 00752d89  8d047f               lea eax, [edi + edi*2]
// 00752d8c  c1e004               shl eax, 4
// 00752d8f  03460c               add eax, dword ptr [esi + 0xc]
// 00752d92  5f                   pop edi
// 00752d93  5e                   pop esi
// 00752d94  c20400               ret 4
// standard library vector<pod48> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
