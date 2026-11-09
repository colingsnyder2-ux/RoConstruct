// from server: 100% by auto
// roc 2009-12 00490ab0  unit: Ogre::RbxEntity  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490ab0
//
// 00490ab0  8b442408             mov eax, dword ptr [esp + 8]
// 00490ab4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00490ab8  56                   push esi
// 00490ab9  8b742410             mov esi, dword ptr [esp + 0x10]
// 00490abd  2bc1                 sub eax, ecx
// 00490abf  2bf0                 sub esi, eax
// 00490ac1  85c0                 test eax, eax
// 00490ac3  7e0d                 jle 0x490ad2
// 00490ac5  50                   push eax
// 00490ac6  51                   push ecx
// 00490ac7  50                   push eax
// 00490ac8  56                   push esi
// 00490ac9  ff15c0b79800         call dword ptr [0x98b7c0]
// 00490acf  83c410               add esp, 0x10
// 00490ad2  8bc6                 mov eax, esi
// 00490ad4  5e                   pop esi
// 00490ad5  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
