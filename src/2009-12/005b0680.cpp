// from server: 100% by auto
// roc 2009-12 005b0680  unit: seg_005b0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0680
//
// 005b0680  8b442408             mov eax, dword ptr [esp + 8]
// 005b0684  8b542404             mov edx, dword ptr [esp + 4]
// 005b0688  2bc2                 sub eax, edx
// 005b068a  d1f8                 sar eax, 1
// 005b068c  56                   push esi
// 005b068d  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b0691  8d0c00               lea ecx, [eax + eax]
// 005b0694  2bf1                 sub esi, ecx
// 005b0696  85c0                 test eax, eax
// 005b0698  7e0d                 jle 0x5b06a7
// 005b069a  51                   push ecx
// 005b069b  52                   push edx
// 005b069c  51                   push ecx
// 005b069d  56                   push esi
// 005b069e  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b06a4  83c410               add esp, 0x10
// 005b06a7  8bc6                 mov eax, esi
// 005b06a9  5e                   pop esi
// 005b06aa  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
