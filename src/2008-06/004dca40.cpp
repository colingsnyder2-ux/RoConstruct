// from server: 100% by auto
// roc 2008-06 004dca40  unit: RBX::ViewNew::ViewG3D  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dca40
//
// 004dca40  8b442408             mov eax, dword ptr [esp + 8]
// 004dca44  8b542404             mov edx, dword ptr [esp + 4]
// 004dca48  2bc2                 sub eax, edx
// 004dca4a  d1f8                 sar eax, 1
// 004dca4c  56                   push esi
// 004dca4d  8b742410             mov esi, dword ptr [esp + 0x10]
// 004dca51  8d0c00               lea ecx, [eax + eax]
// 004dca54  2bf1                 sub esi, ecx
// 004dca56  85c0                 test eax, eax
// 004dca58  7e0d                 jle 0x4dca67
// 004dca5a  51                   push ecx
// 004dca5b  52                   push edx
// 004dca5c  51                   push ecx
// 004dca5d  56                   push esi
// 004dca5e  ff1550288000         call dword ptr [0x802850]
// 004dca64  83c410               add esp, 0x10
// 004dca67  8bc6                 mov eax, esi
// 004dca69  5e                   pop esi
// 004dca6a  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
