// from server: 100% by auto
// roc 2009-06 0048aa40  unit: Ogre::FileStreamDataStream  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048aa40
//
// 0048aa40  8b442408             mov eax, dword ptr [esp + 8]
// 0048aa44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0048aa48  56                   push esi
// 0048aa49  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048aa4d  2bc1                 sub eax, ecx
// 0048aa4f  2bf0                 sub esi, eax
// 0048aa51  85c0                 test eax, eax
// 0048aa53  7e0d                 jle 0x48aa62
// 0048aa55  50                   push eax
// 0048aa56  51                   push ecx
// 0048aa57  50                   push eax
// 0048aa58  56                   push esi
// 0048aa59  ff155ce98900         call dword ptr [0x89e95c]
// 0048aa5f  83c410               add esp, 0x10
// 0048aa62  8bc6                 mov eax, esi
// 0048aa64  5e                   pop esi
// 0048aa65  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
