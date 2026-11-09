// from server: 100% by auto
// roc 2011-06 005438a0  unit: G3D::BinaryInput  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005438a0
//
// 005438a0  8b442408             mov eax, dword ptr [esp + 8]
// 005438a4  8b542404             mov edx, dword ptr [esp + 4]
// 005438a8  2bc2                 sub eax, edx
// 005438aa  c1f803               sar eax, 3
// 005438ad  56                   push esi
// 005438ae  8b742410             mov esi, dword ptr [esp + 0x10]
// 005438b2  8d0cc500000000       lea ecx, [eax*8]
// 005438b9  2bf1                 sub esi, ecx
// 005438bb  85c0                 test eax, eax
// 005438bd  7e0d                 jle 0x5438cc
// 005438bf  51                   push ecx
// 005438c0  52                   push edx
// 005438c1  51                   push ecx
// 005438c2  56                   push esi
// 005438c3  ff15fc09a400         call dword ptr [0xa409fc]
// 005438c9  83c410               add esp, 0x10
// 005438cc  8bc6                 mov eax, esi
// 005438ce  5e                   pop esi
// 005438cf  c3                   ret 
// standard library vector<double> (function ??$_Copy_backward_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
