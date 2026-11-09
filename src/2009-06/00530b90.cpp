// from server: 100% by auto
// roc 2009-06 00530b90  unit: RBX::BeveledBlockBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00530b90
//
// 00530b90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00530b94  8b542408             mov edx, dword ptr [esp + 8]
// 00530b98  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00530b9c  3bca                 cmp ecx, edx
// 00530b9e  7428                 je 0x530bc8
// 00530ba0  56                   push esi
// 00530ba1  8b31                 mov esi, dword ptr [ecx]
// 00530ba3  8930                 mov dword ptr [eax], esi
// 00530ba5  8b7104               mov esi, dword ptr [ecx + 4]
// 00530ba8  897004               mov dword ptr [eax + 4], esi
// 00530bab  8b7108               mov esi, dword ptr [ecx + 8]
// 00530bae  897008               mov dword ptr [eax + 8], esi
// 00530bb1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00530bb4  89700c               mov dword ptr [eax + 0xc], esi
// 00530bb7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00530bba  897010               mov dword ptr [eax + 0x10], esi
// 00530bbd  83c114               add ecx, 0x14
// 00530bc0  83c014               add eax, 0x14
// 00530bc3  3bca                 cmp ecx, edx
// 00530bc5  75da                 jne 0x530ba1
// 00530bc7  5e                   pop esi
// 00530bc8  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
