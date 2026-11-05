// from server: 100% by auto
// roc 2010-06 00558fb0  unit: G3D::BinaryInput  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558fb0
//
// 00558fb0  8b442408             mov eax, dword ptr [esp + 8]
// 00558fb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00558fb8  56                   push esi
// 00558fb9  8b742410             mov esi, dword ptr [esp + 0x10]
// 00558fbd  2bc1                 sub eax, ecx
// 00558fbf  2bf0                 sub esi, eax
// 00558fc1  85c0                 test eax, eax
// 00558fc3  7e0d                 jle 0x558fd2
// 00558fc5  50                   push eax
// 00558fc6  51                   push ecx
// 00558fc7  50                   push eax
// 00558fc8  56                   push esi
// 00558fc9  ff1580a89e00         call dword ptr [0x9ea880]
// 00558fcf  83c410               add esp, 0x10
// 00558fd2  8bc6                 mov eax, esi
// 00558fd4  5e                   pop esi
// 00558fd5  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
