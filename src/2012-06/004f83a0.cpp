// from server: 100% by auto
// roc 2012-06 004f83a0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f83a0
//
// 004f83a0  51                   push ecx
// 004f83a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f83a5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f83a9  c6042400             mov byte ptr [esp], 0
// 004f83ad  8b0424               mov eax, dword ptr [esp]
// 004f83b0  50                   push eax
// 004f83b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f83b5  51                   push ecx
// 004f83b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f83ba  52                   push edx
// 004f83bb  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f83bf  50                   push eax
// 004f83c0  51                   push ecx
// 004f83c1  52                   push edx
// 004f83c2  e899feffff           call 0x4f8260
// 004f83c7  83c41c               add esp, 0x1c
// 004f83ca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
