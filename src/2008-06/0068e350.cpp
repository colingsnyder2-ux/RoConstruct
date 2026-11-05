// from server: 100% by auto
// roc 2008-06 0068e350  unit: Ogre::VRbxSky::?$SharedPtr  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068e350
//
// 0068e350  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068e354  8b542408             mov edx, dword ptr [esp + 8]
// 0068e358  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068e35c  3bca                 cmp ecx, edx
// 0068e35e  7420                 je 0x68e380
// 0068e360  56                   push esi
// 0068e361  85c0                 test eax, eax
// 0068e363  7410                 je 0x68e375
// 0068e365  8b31                 mov esi, dword ptr [ecx]
// 0068e367  8930                 mov dword ptr [eax], esi
// 0068e369  8b7104               mov esi, dword ptr [ecx + 4]
// 0068e36c  897004               mov dword ptr [eax + 4], esi
// 0068e36f  8b7108               mov esi, dword ptr [ecx + 8]
// 0068e372  897008               mov dword ptr [eax + 8], esi
// 0068e375  83c10c               add ecx, 0xc
// 0068e378  83c00c               add eax, 0xc
// 0068e37b  3bca                 cmp ecx, edx
// 0068e37d  75e2                 jne 0x68e361
// 0068e37f  5e                   pop esi
// 0068e380  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
