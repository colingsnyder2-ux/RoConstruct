// from server: 100% by auto
// roc 2011-06 00952e20  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00952e20
//
// 00952e20  51                   push ecx
// 00952e21  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00952e25  8b542410             mov edx, dword ptr [esp + 0x10]
// 00952e29  c6042400             mov byte ptr [esp], 0
// 00952e2d  8b0424               mov eax, dword ptr [esp]
// 00952e30  50                   push eax
// 00952e31  8b442414             mov eax, dword ptr [esp + 0x14]
// 00952e35  51                   push ecx
// 00952e36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00952e3a  52                   push edx
// 00952e3b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00952e3f  50                   push eax
// 00952e40  51                   push ecx
// 00952e41  52                   push edx
// 00952e42  e869feffff           call 0x952cb0
// 00952e47  83c41c               add esp, 0x1c
// 00952e4a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
