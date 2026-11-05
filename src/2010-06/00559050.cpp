// from server: 100% by auto
// roc 2010-06 00559050  unit: G3D::BinaryInput  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559050
//
// 00559050  8b442408             mov eax, dword ptr [esp + 8]
// 00559054  8b542404             mov edx, dword ptr [esp + 4]
// 00559058  2bc2                 sub eax, edx
// 0055905a  c1f803               sar eax, 3
// 0055905d  56                   push esi
// 0055905e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00559062  8d0cc500000000       lea ecx, [eax*8]
// 00559069  2bf1                 sub esi, ecx
// 0055906b  85c0                 test eax, eax
// 0055906d  7e0d                 jle 0x55907c
// 0055906f  51                   push ecx
// 00559070  52                   push edx
// 00559071  51                   push ecx
// 00559072  56                   push esi
// 00559073  ff1580a89e00         call dword ptr [0x9ea880]
// 00559079  83c410               add esp, 0x10
// 0055907c  8bc6                 mov eax, esi
// 0055907e  5e                   pop esi
// 0055907f  c3                   ret 
// standard library vector<double> (function ??$_Copy_backward_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
