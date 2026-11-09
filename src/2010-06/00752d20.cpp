// from server: 100% by auto
// roc 2010-06 00752d20  unit: RBX::PrismPoly  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752d20
//
// 00752d20  56                   push esi
// 00752d21  8bf1                 mov esi, ecx
// 00752d23  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00752d26  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00752d29  b867666666           mov eax, 0x66666667
// 00752d2e  f7e9                 imul ecx
// 00752d30  c1fa04               sar edx, 4
// 00752d33  8bc2                 mov eax, edx
// 00752d35  c1e81f               shr eax, 0x1f
// 00752d38  57                   push edi
// 00752d39  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00752d3d  03c2                 add eax, edx
// 00752d3f  3bf8                 cmp edi, eax
// 00752d41  7206                 jb 0x752d49
// 00752d43  ff150ca99e00         call dword ptr [0x9ea90c]
// 00752d49  8b560c               mov edx, dword ptr [esi + 0xc]
// 00752d4c  8d0cbf               lea ecx, [edi + edi*4]
// 00752d4f  5f                   pop edi
// 00752d50  8d04ca               lea eax, [edx + ecx*8]
// 00752d53  5e                   pop esi
// 00752d54  c20400               ret 4
// standard library vector<pod40> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
