// from server: 100% by auto
// roc 2011-06 007e6660  unit: RBX::AdvRotateTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e6660
//
// 007e6660  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e6664  8b542408             mov edx, dword ptr [esp + 8]
// 007e6668  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e666c  3bca                 cmp ecx, edx
// 007e666e  7428                 je 0x7e6698
// 007e6670  56                   push esi
// 007e6671  8b31                 mov esi, dword ptr [ecx]
// 007e6673  8930                 mov dword ptr [eax], esi
// 007e6675  8b7104               mov esi, dword ptr [ecx + 4]
// 007e6678  897004               mov dword ptr [eax + 4], esi
// 007e667b  8b7108               mov esi, dword ptr [ecx + 8]
// 007e667e  897008               mov dword ptr [eax + 8], esi
// 007e6681  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007e6684  89700c               mov dword ptr [eax + 0xc], esi
// 007e6687  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007e668a  897010               mov dword ptr [eax + 0x10], esi
// 007e668d  83c114               add ecx, 0x14
// 007e6690  83c014               add eax, 0x14
// 007e6693  3bca                 cmp ecx, edx
// 007e6695  75da                 jne 0x7e6671
// 007e6697  5e                   pop esi
// 007e6698  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
