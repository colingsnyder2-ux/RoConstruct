// from server: 100% by auto
// roc 2011-06 0072a5e0  unit: RBX::HandlesBase  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072a5e0
//
// 0072a5e0  8b542408             mov edx, dword ptr [esp + 8]
// 0072a5e4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072a5e8  53                   push ebx
// 0072a5e9  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0072a5ed  3bda                 cmp ebx, edx
// 0072a5ef  7419                 je 0x72a60a
// 0072a5f1  56                   push esi
// 0072a5f2  57                   push edi
// 0072a5f3  83ea24               sub edx, 0x24
// 0072a5f6  83e824               sub eax, 0x24
// 0072a5f9  b909000000           mov ecx, 9
// 0072a5fe  8bf2                 mov esi, edx
// 0072a600  8bf8                 mov edi, eax
// 0072a602  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0072a604  3bd3                 cmp edx, ebx
// 0072a606  75eb                 jne 0x72a5f3
// 0072a608  5f                   pop edi
// 0072a609  5e                   pop esi
// 0072a60a  5b                   pop ebx
// 0072a60b  c3                   ret 
// standard library vector<pod36> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
