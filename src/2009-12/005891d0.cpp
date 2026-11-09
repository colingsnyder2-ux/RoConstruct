// from server: 100% by auto
// roc 2009-12 005891d0  unit: RBX::BeveledBlockBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005891d0
//
// 005891d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005891d4  8b542408             mov edx, dword ptr [esp + 8]
// 005891d8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005891dc  3bca                 cmp ecx, edx
// 005891de  7428                 je 0x589208
// 005891e0  56                   push esi
// 005891e1  8b31                 mov esi, dword ptr [ecx]
// 005891e3  8930                 mov dword ptr [eax], esi
// 005891e5  8b7104               mov esi, dword ptr [ecx + 4]
// 005891e8  897004               mov dword ptr [eax + 4], esi
// 005891eb  8b7108               mov esi, dword ptr [ecx + 8]
// 005891ee  897008               mov dword ptr [eax + 8], esi
// 005891f1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005891f4  89700c               mov dword ptr [eax + 0xc], esi
// 005891f7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005891fa  897010               mov dword ptr [eax + 0x10], esi
// 005891fd  83c114               add ecx, 0x14
// 00589200  83c014               add eax, 0x14
// 00589203  3bca                 cmp ecx, edx
// 00589205  75da                 jne 0x5891e1
// 00589207  5e                   pop esi
// 00589208  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
