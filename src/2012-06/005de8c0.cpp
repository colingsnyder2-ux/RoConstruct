// from server: 100% by auto
// roc 2012-06 005de8c0  unit: RBX::BeveledBlockBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005de8c0
//
// 005de8c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005de8c4  8b542408             mov edx, dword ptr [esp + 8]
// 005de8c8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005de8cc  3bca                 cmp ecx, edx
// 005de8ce  7428                 je 0x5de8f8
// 005de8d0  56                   push esi
// 005de8d1  8b31                 mov esi, dword ptr [ecx]
// 005de8d3  8930                 mov dword ptr [eax], esi
// 005de8d5  8b7104               mov esi, dword ptr [ecx + 4]
// 005de8d8  897004               mov dword ptr [eax + 4], esi
// 005de8db  8b7108               mov esi, dword ptr [ecx + 8]
// 005de8de  897008               mov dword ptr [eax + 8], esi
// 005de8e1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005de8e4  89700c               mov dword ptr [eax + 0xc], esi
// 005de8e7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005de8ea  897010               mov dword ptr [eax + 0x10], esi
// 005de8ed  83c114               add ecx, 0x14
// 005de8f0  83c014               add eax, 0x14
// 005de8f3  3bca                 cmp ecx, edx
// 005de8f5  75da                 jne 0x5de8d1
// 005de8f7  5e                   pop esi
// 005de8f8  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
