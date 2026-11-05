// from server: 100% by auto
// roc 2009-12 004a2000  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2000
//
// 004a2000  51                   push ecx
// 004a2001  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a2005  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2009  c6042400             mov byte ptr [esp], 0
// 004a200d  8b0424               mov eax, dword ptr [esp]
// 004a2010  50                   push eax
// 004a2011  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2015  51                   push ecx
// 004a2016  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a201a  52                   push edx
// 004a201b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a201f  50                   push eax
// 004a2020  51                   push ecx
// 004a2021  52                   push edx
// 004a2022  e819efffff           call 0x4a0f40
// 004a2027  83c41c               add esp, 0x1c
// 004a202a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
