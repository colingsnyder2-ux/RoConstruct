// from server: 100% by auto
// roc 2011-06 007e66e0  unit: RBX::AdvRotateTool  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e66e0
//
// 007e66e0  8b542404             mov edx, dword ptr [esp + 4]
// 007e66e4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e66e8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e66ec  3bd1                 cmp edx, ecx
// 007e66ee  7429                 je 0x7e6719
// 007e66f0  56                   push esi
// 007e66f1  8b71ec               mov esi, dword ptr [ecx - 0x14]
// 007e66f4  83e914               sub ecx, 0x14
// 007e66f7  83e814               sub eax, 0x14
// 007e66fa  8930                 mov dword ptr [eax], esi
// 007e66fc  8b7104               mov esi, dword ptr [ecx + 4]
// 007e66ff  897004               mov dword ptr [eax + 4], esi
// 007e6702  8b7108               mov esi, dword ptr [ecx + 8]
// 007e6705  897008               mov dword ptr [eax + 8], esi
// 007e6708  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007e670b  89700c               mov dword ptr [eax + 0xc], esi
// 007e670e  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007e6711  897010               mov dword ptr [eax + 0x10], esi
// 007e6714  3bca                 cmp ecx, edx
// 007e6716  75d9                 jne 0x7e66f1
// 007e6718  5e                   pop esi
// 007e6719  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
