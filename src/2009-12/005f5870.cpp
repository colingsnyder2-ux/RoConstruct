// from server: 100% by auto
// roc 2009-12 005f5870  unit: G3D::BinaryInput  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f5870
//
// 005f5870  8b442408             mov eax, dword ptr [esp + 8]
// 005f5874  8b542404             mov edx, dword ptr [esp + 4]
// 005f5878  2bc2                 sub eax, edx
// 005f587a  c1f803               sar eax, 3
// 005f587d  56                   push esi
// 005f587e  8b742410             mov esi, dword ptr [esp + 0x10]
// 005f5882  8d0cc500000000       lea ecx, [eax*8]
// 005f5889  2bf1                 sub esi, ecx
// 005f588b  85c0                 test eax, eax
// 005f588d  7e0d                 jle 0x5f589c
// 005f588f  51                   push ecx
// 005f5890  52                   push edx
// 005f5891  51                   push ecx
// 005f5892  56                   push esi
// 005f5893  ff15c0b79800         call dword ptr [0x98b7c0]
// 005f5899  83c410               add esp, 0x10
// 005f589c  8bc6                 mov eax, esi
// 005f589e  5e                   pop esi
// 005f589f  c3                   ret 
// standard library vector<double> (function ??$_Copy_backward_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
