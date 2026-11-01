// from server: 100% by auto
// roc 2009-12 004bdd80  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bdd80
//
// 004bdd80  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004bdd84  8b542408             mov edx, dword ptr [esp + 8]
// 004bdd88  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bdd8c  3bca                 cmp ecx, edx
// 004bdd8e  7426                 je 0x4bddb6
// 004bdd90  56                   push esi
// 004bdd91  85c0                 test eax, eax
// 004bdd93  7416                 je 0x4bddab
// 004bdd95  8b31                 mov esi, dword ptr [ecx]
// 004bdd97  8930                 mov dword ptr [eax], esi
// 004bdd99  8b7104               mov esi, dword ptr [ecx + 4]
// 004bdd9c  897004               mov dword ptr [eax + 4], esi
// 004bdd9f  8b7108               mov esi, dword ptr [ecx + 8]
// 004bdda2  897008               mov dword ptr [eax + 8], esi
// 004bdda5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 004bdda8  89700c               mov dword ptr [eax + 0xc], esi
// 004bddab  83c110               add ecx, 0x10
// 004bddae  83c010               add eax, 0x10
// 004bddb1  3bca                 cmp ecx, edx
// 004bddb3  75dc                 jne 0x4bdd91
// 004bddb5  5e                   pop esi
// 004bddb6  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
