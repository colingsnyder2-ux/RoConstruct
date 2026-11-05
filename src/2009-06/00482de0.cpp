// from server: 100% by auto
// roc 2009-06 00482de0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482de0
//
// 00482de0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00482de4  85c9                 test ecx, ecx
// 00482de6  7620                 jbe 0x482e08
// 00482de8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00482dec  8b442404             mov eax, dword ptr [esp + 4]
// 00482df0  56                   push esi
// 00482df1  85c0                 test eax, eax
// 00482df3  740a                 je 0x482dff
// 00482df5  8b32                 mov esi, dword ptr [edx]
// 00482df7  8930                 mov dword ptr [eax], esi
// 00482df9  8b7204               mov esi, dword ptr [edx + 4]
// 00482dfc  897004               mov dword ptr [eax + 4], esi
// 00482dff  49                   dec ecx
// 00482e00  83c008               add eax, 8
// 00482e03  85c9                 test ecx, ecx
// 00482e05  77ea                 ja 0x482df1
// 00482e07  5e                   pop esi
// 00482e08  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
