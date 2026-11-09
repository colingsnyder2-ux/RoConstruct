// from server: 100% by auto
// roc 2008-06 00515f50  unit: G3D::BinaryInput  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515f50
//
// 00515f50  8b442408             mov eax, dword ptr [esp + 8]
// 00515f54  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00515f58  56                   push esi
// 00515f59  8b742410             mov esi, dword ptr [esp + 0x10]
// 00515f5d  2bc1                 sub eax, ecx
// 00515f5f  2bf0                 sub esi, eax
// 00515f61  85c0                 test eax, eax
// 00515f63  7e0d                 jle 0x515f72
// 00515f65  50                   push eax
// 00515f66  51                   push ecx
// 00515f67  50                   push eax
// 00515f68  56                   push esi
// 00515f69  ff1550288000         call dword ptr [0x802850]
// 00515f6f  83c410               add esp, 0x10
// 00515f72  8bc6                 mov eax, esi
// 00515f74  5e                   pop esi
// 00515f75  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
