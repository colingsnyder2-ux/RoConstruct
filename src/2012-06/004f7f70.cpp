// from server: 100% by auto
// roc 2012-06 004f7f70  unit: Ogre::RbxMeshPartAdapter  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f7f70
//
// 004f7f70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004f7f74  8b542408             mov edx, dword ptr [esp + 8]
// 004f7f78  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004f7f7c  3bca                 cmp ecx, edx
// 004f7f7e  7420                 je 0x4f7fa0
// 004f7f80  56                   push esi
// 004f7f81  85c0                 test eax, eax
// 004f7f83  7410                 je 0x4f7f95
// 004f7f85  8b31                 mov esi, dword ptr [ecx]
// 004f7f87  8930                 mov dword ptr [eax], esi
// 004f7f89  8b7104               mov esi, dword ptr [ecx + 4]
// 004f7f8c  897004               mov dword ptr [eax + 4], esi
// 004f7f8f  8b7108               mov esi, dword ptr [ecx + 8]
// 004f7f92  897008               mov dword ptr [eax + 8], esi
// 004f7f95  83c10c               add ecx, 0xc
// 004f7f98  83c00c               add eax, 0xc
// 004f7f9b  3bca                 cmp ecx, edx
// 004f7f9d  75e2                 jne 0x4f7f81
// 004f7f9f  5e                   pop esi
// 004f7fa0  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
