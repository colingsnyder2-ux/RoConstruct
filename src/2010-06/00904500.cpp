// from server: 100% by auto
// roc 2010-06 00904500  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904500
//
// 00904500  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00904504  8b542408             mov edx, dword ptr [esp + 8]
// 00904508  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0090450c  3bca                 cmp ecx, edx
// 0090450e  7426                 je 0x904536
// 00904510  56                   push esi
// 00904511  85c0                 test eax, eax
// 00904513  7416                 je 0x90452b
// 00904515  8b31                 mov esi, dword ptr [ecx]
// 00904517  8930                 mov dword ptr [eax], esi
// 00904519  8b7104               mov esi, dword ptr [ecx + 4]
// 0090451c  897004               mov dword ptr [eax + 4], esi
// 0090451f  8b7108               mov esi, dword ptr [ecx + 8]
// 00904522  897008               mov dword ptr [eax + 8], esi
// 00904525  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00904528  89700c               mov dword ptr [eax + 0xc], esi
// 0090452b  83c110               add ecx, 0x10
// 0090452e  83c010               add eax, 0x10
// 00904531  3bca                 cmp ecx, edx
// 00904533  75dc                 jne 0x904511
// 00904535  5e                   pop esi
// 00904536  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
