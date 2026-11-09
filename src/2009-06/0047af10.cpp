// from server: 100% by auto
// roc 2009-06 0047af10  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047af10
//
// 0047af10  56                   push esi
// 0047af11  8bf1                 mov esi, ecx
// 0047af13  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0047af16  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0047af19  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047af1e  f7e9                 imul ecx
// 0047af20  d1fa                 sar edx, 1
// 0047af22  8bc2                 mov eax, edx
// 0047af24  c1e81f               shr eax, 0x1f
// 0047af27  57                   push edi
// 0047af28  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0047af2c  03c2                 add eax, edx
// 0047af2e  3bf8                 cmp edi, eax
// 0047af30  7206                 jb 0x47af38
// 0047af32  ff15ace98900         call dword ptr [0x89e9ac]
// 0047af38  8b560c               mov edx, dword ptr [esi + 0xc]
// 0047af3b  8d0c7f               lea ecx, [edi + edi*2]
// 0047af3e  5f                   pop edi
// 0047af3f  8d048a               lea eax, [edx + ecx*4]
// 0047af42  5e                   pop esi
// 0047af43  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
