// from server: 100% by auto
// roc 2012-06 0062f6a0  unit: G3D::BinaryInput  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f6a0
//
// 0062f6a0  8b442408             mov eax, dword ptr [esp + 8]
// 0062f6a4  8b542404             mov edx, dword ptr [esp + 4]
// 0062f6a8  2bc2                 sub eax, edx
// 0062f6aa  c1f803               sar eax, 3
// 0062f6ad  56                   push esi
// 0062f6ae  8b742410             mov esi, dword ptr [esp + 0x10]
// 0062f6b2  8d0cc500000000       lea ecx, [eax*8]
// 0062f6b9  2bf1                 sub esi, ecx
// 0062f6bb  85c0                 test eax, eax
// 0062f6bd  7e0d                 jle 0x62f6cc
// 0062f6bf  51                   push ecx
// 0062f6c0  52                   push edx
// 0062f6c1  51                   push ecx
// 0062f6c2  56                   push esi
// 0062f6c3  ff15c02ab200         call dword ptr [0xb22ac0]
// 0062f6c9  83c410               add esp, 0x10
// 0062f6cc  8bc6                 mov eax, esi
// 0062f6ce  5e                   pop esi
// 0062f6cf  c3                   ret 
// standard library vector<double> (function ??$_Copy_backward_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
