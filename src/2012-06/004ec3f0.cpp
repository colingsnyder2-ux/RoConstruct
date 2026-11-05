// from server: 100% by auto
// roc 2012-06 004ec3f0  unit: Ogre::RbxEntity  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ec3f0
//
// 004ec3f0  8b442408             mov eax, dword ptr [esp + 8]
// 004ec3f4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004ec3f8  56                   push esi
// 004ec3f9  8b742410             mov esi, dword ptr [esp + 0x10]
// 004ec3fd  2bc1                 sub eax, ecx
// 004ec3ff  2bf0                 sub esi, eax
// 004ec401  85c0                 test eax, eax
// 004ec403  7e0d                 jle 0x4ec412
// 004ec405  50                   push eax
// 004ec406  51                   push ecx
// 004ec407  50                   push eax
// 004ec408  56                   push esi
// 004ec409  ff15c02ab200         call dword ptr [0xb22ac0]
// 004ec40f  83c410               add esp, 0x10
// 004ec412  8bc6                 mov eax, esi
// 004ec414  5e                   pop esi
// 004ec415  c3                   ret 
// standard library vector<char> (function ??$_Copy_backward_opt@PADPADUrandom_access_iterator_tag@std@@@std@@YAPADPAD00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
