// from server: 100% by auto
// roc 2010-06 00902540  unit: Ogre::RbxArchiveFactory  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902540
//
// 00902540  51                   push ecx
// 00902541  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00902545  8b542410             mov edx, dword ptr [esp + 0x10]
// 00902549  c6042400             mov byte ptr [esp], 0
// 0090254d  8b0424               mov eax, dword ptr [esp]
// 00902550  50                   push eax
// 00902551  8b442414             mov eax, dword ptr [esp + 0x14]
// 00902555  51                   push ecx
// 00902556  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0090255a  52                   push edx
// 0090255b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0090255f  50                   push eax
// 00902560  51                   push ecx
// 00902561  52                   push edx
// 00902562  e869f9ffff           call 0x901ed0
// 00902567  83c41c               add esp, 0x1c
// 0090256a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
