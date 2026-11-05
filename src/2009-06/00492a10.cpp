// from server: 100% by auto
// roc 2009-06 00492a10  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00492a10
//
// 00492a10  51                   push ecx
// 00492a11  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00492a15  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492a19  c6042400             mov byte ptr [esp], 0
// 00492a1d  8b0424               mov eax, dword ptr [esp]
// 00492a20  50                   push eax
// 00492a21  8b442414             mov eax, dword ptr [esp + 0x14]
// 00492a25  51                   push ecx
// 00492a26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00492a2a  52                   push edx
// 00492a2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00492a2f  50                   push eax
// 00492a30  51                   push ecx
// 00492a31  52                   push edx
// 00492a32  e869efffff           call 0x4919a0
// 00492a37  83c41c               add esp, 0x1c
// 00492a3a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
