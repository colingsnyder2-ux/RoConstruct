// from server: 100% by auto
// roc 2009-12 00491c80  unit: Ogre::RbxEntity  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491c80
//
// 00491c80  56                   push esi
// 00491c81  8bf1                 mov esi, ecx
// 00491c83  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00491c86  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00491c89  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491c8e  f7e9                 imul ecx
// 00491c90  d1fa                 sar edx, 1
// 00491c92  8bc2                 mov eax, edx
// 00491c94  c1e81f               shr eax, 0x1f
// 00491c97  57                   push edi
// 00491c98  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00491c9c  03c2                 add eax, edx
// 00491c9e  3bf8                 cmp edi, eax
// 00491ca0  7206                 jb 0x491ca8
// 00491ca2  ff1560b79800         call dword ptr [0x98b760]
// 00491ca8  8b560c               mov edx, dword ptr [esi + 0xc]
// 00491cab  8d0c7f               lea ecx, [edi + edi*2]
// 00491cae  5f                   pop edi
// 00491caf  8d048a               lea eax, [edx + ecx*4]
// 00491cb2  5e                   pop esi
// 00491cb3  c20400               ret 4
// standard library vector<pod12> (function ??A?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
