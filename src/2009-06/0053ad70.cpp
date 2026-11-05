// from server: 100% by auto
// roc 2009-06 0053ad70  unit: RBX::VerticalCylinderBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053ad70
//
// 0053ad70  8b442408             mov eax, dword ptr [esp + 8]
// 0053ad74  8b542404             mov edx, dword ptr [esp + 4]
// 0053ad78  2bc2                 sub eax, edx
// 0053ad7a  d1f8                 sar eax, 1
// 0053ad7c  56                   push esi
// 0053ad7d  8b742410             mov esi, dword ptr [esp + 0x10]
// 0053ad81  8d0c00               lea ecx, [eax + eax]
// 0053ad84  2bf1                 sub esi, ecx
// 0053ad86  85c0                 test eax, eax
// 0053ad88  7e0d                 jle 0x53ad97
// 0053ad8a  51                   push ecx
// 0053ad8b  52                   push edx
// 0053ad8c  51                   push ecx
// 0053ad8d  56                   push esi
// 0053ad8e  ff155ce98900         call dword ptr [0x89e95c]
// 0053ad94  83c410               add esp, 0x10
// 0053ad97  8bc6                 mov eax, esi
// 0053ad99  5e                   pop esi
// 0053ad9a  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
