// from server: 100% by auto
// roc 2009-12 004aad20  unit: Ogre::GfxClustererPart  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aad20
//
// 004aad20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004aad24  8b542408             mov edx, dword ptr [esp + 8]
// 004aad28  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004aad2c  3bca                 cmp ecx, edx
// 004aad2e  741a                 je 0x4aad4a
// 004aad30  56                   push esi
// 004aad31  85c0                 test eax, eax
// 004aad33  740a                 je 0x4aad3f
// 004aad35  8b31                 mov esi, dword ptr [ecx]
// 004aad37  8930                 mov dword ptr [eax], esi
// 004aad39  8b7104               mov esi, dword ptr [ecx + 4]
// 004aad3c  897004               mov dword ptr [eax + 4], esi
// 004aad3f  83c108               add ecx, 8
// 004aad42  83c008               add eax, 8
// 004aad45  3bca                 cmp ecx, edx
// 004aad47  75e8                 jne 0x4aad31
// 004aad49  5e                   pop esi
// 004aad4a  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
