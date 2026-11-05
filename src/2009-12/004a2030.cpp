// from server: 100% by auto
// roc 2009-12 004a2030  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2030
//
// 004a2030  51                   push ecx
// 004a2031  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a2035  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2039  c6042400             mov byte ptr [esp], 0
// 004a203d  8b0424               mov eax, dword ptr [esp]
// 004a2040  50                   push eax
// 004a2041  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2045  51                   push ecx
// 004a2046  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a204a  52                   push edx
// 004a204b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a204f  50                   push eax
// 004a2050  51                   push ecx
// 004a2051  52                   push edx
// 004a2052  e8a9f6ffff           call 0x4a1700
// 004a2057  83c41c               add esp, 0x1c
// 004a205a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
