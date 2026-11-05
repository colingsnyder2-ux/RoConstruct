// from server: 100% by auto
// roc 2010-06 00786340  unit: RBX::HUMAN::GettingUp  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00786340
//
// 00786340  8b542404             mov edx, dword ptr [esp + 4]
// 00786344  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00786348  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078634c  3bd1                 cmp edx, ecx
// 0078634e  7429                 je 0x786379
// 00786350  56                   push esi
// 00786351  8b71ec               mov esi, dword ptr [ecx - 0x14]
// 00786354  83e914               sub ecx, 0x14
// 00786357  83e814               sub eax, 0x14
// 0078635a  8930                 mov dword ptr [eax], esi
// 0078635c  8b7104               mov esi, dword ptr [ecx + 4]
// 0078635f  897004               mov dword ptr [eax + 4], esi
// 00786362  8b7108               mov esi, dword ptr [ecx + 8]
// 00786365  897008               mov dword ptr [eax + 8], esi
// 00786368  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0078636b  89700c               mov dword ptr [eax + 0xc], esi
// 0078636e  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00786371  897010               mov dword ptr [eax + 0x10], esi
// 00786374  3bca                 cmp ecx, edx
// 00786376  75d9                 jne 0x786351
// 00786378  5e                   pop esi
// 00786379  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
