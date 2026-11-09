// from server: 100% by auto
// roc 2009-06 0048a920  unit: Ogre::RbxMeshPartAdapter  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048a920
//
// 0048a920  56                   push esi
// 0048a921  8bf1                 mov esi, ecx
// 0048a923  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048a926  2b460c               sub eax, dword ptr [esi + 0xc]
// 0048a929  57                   push edi
// 0048a92a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0048a92e  3bf8                 cmp edi, eax
// 0048a930  7206                 jb 0x48a938
// 0048a932  ff15ace98900         call dword ptr [0x89e9ac]
// 0048a938  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048a93b  03c7                 add eax, edi
// 0048a93d  5f                   pop edi
// 0048a93e  5e                   pop esi
// 0048a93f  c20400               ret 4
// standard library vector<char> (function ??A?$vector@DV?$allocator@D@std@@@std@@QBEABDI@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
