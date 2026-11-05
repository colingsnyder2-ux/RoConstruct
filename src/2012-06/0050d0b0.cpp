// from server: 100% by auto
// roc 2012-06 0050d0b0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050d0b0
//
// 0050d0b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050d0b4  8b542408             mov edx, dword ptr [esp + 8]
// 0050d0b8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050d0bc  3bca                 cmp ecx, edx
// 0050d0be  7426                 je 0x50d0e6
// 0050d0c0  56                   push esi
// 0050d0c1  85c0                 test eax, eax
// 0050d0c3  7416                 je 0x50d0db
// 0050d0c5  8b31                 mov esi, dword ptr [ecx]
// 0050d0c7  8930                 mov dword ptr [eax], esi
// 0050d0c9  8b7104               mov esi, dword ptr [ecx + 4]
// 0050d0cc  897004               mov dword ptr [eax + 4], esi
// 0050d0cf  8b7108               mov esi, dword ptr [ecx + 8]
// 0050d0d2  897008               mov dword ptr [eax + 8], esi
// 0050d0d5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0050d0d8  89700c               mov dword ptr [eax + 0xc], esi
// 0050d0db  83c110               add ecx, 0x10
// 0050d0de  83c010               add eax, 0x10
// 0050d0e1  3bca                 cmp ecx, edx
// 0050d0e3  75dc                 jne 0x50d0c1
// 0050d0e5  5e                   pop esi
// 0050d0e6  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
