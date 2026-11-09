// from server: 100% by auto
// roc 2011-06 0072a450  unit: RBX::HandlesBase  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072a450
//
// 0072a450  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0072a454  8b542408             mov edx, dword ptr [esp + 8]
// 0072a458  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072a45c  3bca                 cmp ecx, edx
// 0072a45e  7420                 je 0x72a480
// 0072a460  56                   push esi
// 0072a461  85c0                 test eax, eax
// 0072a463  7410                 je 0x72a475
// 0072a465  8b31                 mov esi, dword ptr [ecx]
// 0072a467  8930                 mov dword ptr [eax], esi
// 0072a469  8b7104               mov esi, dword ptr [ecx + 4]
// 0072a46c  897004               mov dword ptr [eax + 4], esi
// 0072a46f  8b7108               mov esi, dword ptr [ecx + 8]
// 0072a472  897008               mov dword ptr [eax + 8], esi
// 0072a475  83c10c               add ecx, 0xc
// 0072a478  83c00c               add eax, 0xc
// 0072a47b  3bca                 cmp ecx, edx
// 0072a47d  75e2                 jne 0x72a461
// 0072a47f  5e                   pop esi
// 0072a480  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
