// from server: 100% by auto
// roc 2009-12 004a1fa0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1fa0
//
// 004a1fa0  51                   push ecx
// 004a1fa1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1fa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1fa9  c6042400             mov byte ptr [esp], 0
// 004a1fad  8b0424               mov eax, dword ptr [esp]
// 004a1fb0  50                   push eax
// 004a1fb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1fb5  51                   push ecx
// 004a1fb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1fba  52                   push edx
// 004a1fbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1fbf  50                   push eax
// 004a1fc0  51                   push ecx
// 004a1fc1  52                   push edx
// 004a1fc2  e8d9dfffff           call 0x49ffa0
// 004a1fc7  83c41c               add esp, 0x1c
// 004a1fca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
