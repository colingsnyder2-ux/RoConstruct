// from server: 100% by auto
// roc 2010-06 008df5b0  unit: Ogre::RbxMaterialAdapter  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008df5b0
//
// 008df5b0  56                   push esi
// 008df5b1  8bf1                 mov esi, ecx
// 008df5b3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008df5b6  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 008df5b9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008df5be  f7e9                 imul ecx
// 008df5c0  d1fa                 sar edx, 1
// 008df5c2  8bc2                 mov eax, edx
// 008df5c4  c1e81f               shr eax, 0x1f
// 008df5c7  57                   push edi
// 008df5c8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008df5cc  03c2                 add eax, edx
// 008df5ce  3bf8                 cmp edi, eax
// 008df5d0  7206                 jb 0x8df5d8
// 008df5d2  ff150ca99e00         call dword ptr [0x9ea90c]
// 008df5d8  8b560c               mov edx, dword ptr [esi + 0xc]
// 008df5db  8d0c7f               lea ecx, [edi + edi*2]
// 008df5de  5f                   pop edi
// 008df5df  8d048a               lea eax, [edx + ecx*4]
// 008df5e2  5e                   pop esi
// 008df5e3  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
