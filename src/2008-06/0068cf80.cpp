// from server: 100% by auto
// roc 2008-06 0068cf80  unit: Ogre::RbxSceneManagerFactory  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068cf80
//
// 0068cf80  56                   push esi
// 0068cf81  8bf1                 mov esi, ecx
// 0068cf83  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0068cf86  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0068cf89  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068cf8e  f7e9                 imul ecx
// 0068cf90  d1fa                 sar edx, 1
// 0068cf92  8bc2                 mov eax, edx
// 0068cf94  c1e81f               shr eax, 0x1f
// 0068cf97  57                   push edi
// 0068cf98  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0068cf9c  03c2                 add eax, edx
// 0068cf9e  3bf8                 cmp edi, eax
// 0068cfa0  7206                 jb 0x68cfa8
// 0068cfa2  ff1590288000         call dword ptr [0x802890]
// 0068cfa8  8b560c               mov edx, dword ptr [esi + 0xc]
// 0068cfab  8d0c7f               lea ecx, [edi + edi*2]
// 0068cfae  5f                   pop edi
// 0068cfaf  8d048a               lea eax, [edx + ecx*4]
// 0068cfb2  5e                   pop esi
// 0068cfb3  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
