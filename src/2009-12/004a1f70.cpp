// from server: 100% by auto
// roc 2009-12 004a1f70  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1f70
//
// 004a1f70  51                   push ecx
// 004a1f71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1f75  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1f79  c6042400             mov byte ptr [esp], 0
// 004a1f7d  8b0424               mov eax, dword ptr [esp]
// 004a1f80  50                   push eax
// 004a1f81  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1f85  51                   push ecx
// 004a1f86  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1f8a  52                   push edx
// 004a1f8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1f8f  50                   push eax
// 004a1f90  51                   push ecx
// 004a1f91  52                   push edx
// 004a1f92  e819d9ffff           call 0x49f8b0
// 004a1f97  83c41c               add esp, 0x1c
// 004a1f9a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
