// from server: 100% by auto
// roc 2012-06 00604910  unit: seg_00600000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00604910
//
// 00604910  8b442408             mov eax, dword ptr [esp + 8]
// 00604914  8b542404             mov edx, dword ptr [esp + 4]
// 00604918  2bc2                 sub eax, edx
// 0060491a  d1f8                 sar eax, 1
// 0060491c  56                   push esi
// 0060491d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00604921  8d0c00               lea ecx, [eax + eax]
// 00604924  2bf1                 sub esi, ecx
// 00604926  85c0                 test eax, eax
// 00604928  7e0d                 jle 0x604937
// 0060492a  51                   push ecx
// 0060492b  52                   push edx
// 0060492c  51                   push ecx
// 0060492d  56                   push esi
// 0060492e  ff15c02ab200         call dword ptr [0xb22ac0]
// 00604934  83c410               add esp, 0x10
// 00604937  8bc6                 mov eax, esi
// 00604939  5e                   pop esi
// 0060493a  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
