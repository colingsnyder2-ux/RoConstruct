// from server: 100% by auto
// roc 2009-06 00574f10  unit: G3D::BinaryInput  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574f10
//
// 00574f10  8b442408             mov eax, dword ptr [esp + 8]
// 00574f14  8b542404             mov edx, dword ptr [esp + 4]
// 00574f18  2bc2                 sub eax, edx
// 00574f1a  c1f803               sar eax, 3
// 00574f1d  56                   push esi
// 00574f1e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00574f22  8d0cc500000000       lea ecx, [eax*8]
// 00574f29  2bf1                 sub esi, ecx
// 00574f2b  85c0                 test eax, eax
// 00574f2d  7e0d                 jle 0x574f3c
// 00574f2f  51                   push ecx
// 00574f30  52                   push edx
// 00574f31  51                   push ecx
// 00574f32  56                   push esi
// 00574f33  ff155ce98900         call dword ptr [0x89e95c]
// 00574f39  83c410               add esp, 0x10
// 00574f3c  8bc6                 mov eax, esi
// 00574f3e  5e                   pop esi
// 00574f3f  c3                   ret 
// standard library vector<double> (function ??$_Copy_backward_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
