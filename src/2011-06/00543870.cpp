// from server: 100% by auto
// roc 2011-06 00543870  unit: G3D::BinaryInput  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543870
//
// 00543870  8b442408             mov eax, dword ptr [esp + 8]
// 00543874  8b542404             mov edx, dword ptr [esp + 4]
// 00543878  2bc2                 sub eax, edx
// 0054387a  d1f8                 sar eax, 1
// 0054387c  56                   push esi
// 0054387d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00543881  8d0c00               lea ecx, [eax + eax]
// 00543884  2bf1                 sub esi, ecx
// 00543886  85c0                 test eax, eax
// 00543888  7e0d                 jle 0x543897
// 0054388a  51                   push ecx
// 0054388b  52                   push edx
// 0054388c  51                   push ecx
// 0054388d  56                   push esi
// 0054388e  ff15fc09a400         call dword ptr [0xa409fc]
// 00543894  83c410               add esp, 0x10
// 00543897  8bc6                 mov eax, esi
// 00543899  5e                   pop esi
// 0054389a  c3                   ret 
// standard library vector<short> (function ??$_Copy_backward_opt@PAFPAFUrandom_access_iterator_tag@std@@@std@@YAPAFPAF00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
