// from server: 100% by auto
// roc 2010-06 008df650  unit: Ogre::RbxMaterialAdapter  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008df650
//
// 008df650  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008df654  8b542408             mov edx, dword ptr [esp + 8]
// 008df658  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008df65c  3bca                 cmp ecx, edx
// 008df65e  7420                 je 0x8df680
// 008df660  56                   push esi
// 008df661  85c0                 test eax, eax
// 008df663  7410                 je 0x8df675
// 008df665  8b31                 mov esi, dword ptr [ecx]
// 008df667  8930                 mov dword ptr [eax], esi
// 008df669  8b7104               mov esi, dword ptr [ecx + 4]
// 008df66c  897004               mov dword ptr [eax + 4], esi
// 008df66f  8b7108               mov esi, dword ptr [ecx + 8]
// 008df672  897008               mov dword ptr [eax + 8], esi
// 008df675  83c10c               add ecx, 0xc
// 008df678  83c00c               add eax, 0xc
// 008df67b  3bca                 cmp ecx, edx
// 008df67d  75e2                 jne 0x8df661
// 008df67f  5e                   pop esi
// 008df680  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
