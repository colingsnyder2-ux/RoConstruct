// from server: 100% by auto
// roc 2010-06 00559000  unit: G3D::BinaryInput  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559000
//
// 00559000  8b442408             mov eax, dword ptr [esp + 8]
// 00559004  8b542404             mov edx, dword ptr [esp + 4]
// 00559008  2bc2                 sub eax, edx
// 0055900a  d1f8                 sar eax, 1
// 0055900c  56                   push esi
// 0055900d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00559011  8d0c00               lea ecx, [eax + eax]
// 00559014  2bf1                 sub esi, ecx
// 00559016  85c0                 test eax, eax
// 00559018  7e0d                 jle 0x559027
// 0055901a  51                   push ecx
// 0055901b  52                   push edx
// 0055901c  51                   push ecx
// 0055901d  56                   push esi
// 0055901e  ff1580a89e00         call dword ptr [0x9ea880]
// 00559024  83c410               add esp, 0x10
// 00559027  8bc6                 mov eax, esi
// 00559029  5e                   pop esi
// 0055902a  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
