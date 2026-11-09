// from server: 100% by auto
// roc 2009-06 00482c90  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482c90
//
// 00482c90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00482c94  8b542408             mov edx, dword ptr [esp + 8]
// 00482c98  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00482c9c  3bca                 cmp ecx, edx
// 00482c9e  7426                 je 0x482cc6
// 00482ca0  56                   push esi
// 00482ca1  85c0                 test eax, eax
// 00482ca3  7416                 je 0x482cbb
// 00482ca5  8b31                 mov esi, dword ptr [ecx]
// 00482ca7  8930                 mov dword ptr [eax], esi
// 00482ca9  8b7104               mov esi, dword ptr [ecx + 4]
// 00482cac  897004               mov dword ptr [eax + 4], esi
// 00482caf  8b7108               mov esi, dword ptr [ecx + 8]
// 00482cb2  897008               mov dword ptr [eax + 8], esi
// 00482cb5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00482cb8  89700c               mov dword ptr [eax + 0xc], esi
// 00482cbb  83c110               add ecx, 0x10
// 00482cbe  83c010               add eax, 0x10
// 00482cc1  3bca                 cmp ecx, edx
// 00482cc3  75dc                 jne 0x482ca1
// 00482cc5  5e                   pop esi
// 00482cc6  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
