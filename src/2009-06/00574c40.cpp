// from server: 100% by auto
// roc 2009-06 00574c40  unit: G3D::GCamera  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574c40
//
// 00574c40  8b442408             mov eax, dword ptr [esp + 8]
// 00574c44  8b542404             mov edx, dword ptr [esp + 4]
// 00574c48  2bc2                 sub eax, edx
// 00574c4a  56                   push esi
// 00574c4b  c1f803               sar eax, 3
// 00574c4e  57                   push edi
// 00574c4f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00574c53  8d0cc500000000       lea ecx, [eax*8]
// 00574c5a  8d3439               lea esi, [ecx + edi]
// 00574c5d  85c0                 test eax, eax
// 00574c5f  7e0d                 jle 0x574c6e
// 00574c61  51                   push ecx
// 00574c62  52                   push edx
// 00574c63  51                   push ecx
// 00574c64  57                   push edi
// 00574c65  ff155ce98900         call dword ptr [0x89e95c]
// 00574c6b  83c410               add esp, 0x10
// 00574c6e  5f                   pop edi
// 00574c6f  8bc6                 mov eax, esi
// 00574c71  5e                   pop esi
// 00574c72  c3                   ret 
// standard library vector<double> (function ??$_Copy_opt@PANPANUrandom_access_iterator_tag@std@@@std@@YAPANPAN00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
