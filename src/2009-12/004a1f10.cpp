// from server: 100% by auto
// roc 2009-12 004a1f10  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1f10
//
// 004a1f10  51                   push ecx
// 004a1f11  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1f15  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1f19  c6042400             mov byte ptr [esp], 0
// 004a1f1d  8b0424               mov eax, dword ptr [esp]
// 004a1f20  50                   push eax
// 004a1f21  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1f25  51                   push ecx
// 004a1f26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1f2a  52                   push edx
// 004a1f2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1f2f  50                   push eax
// 004a1f30  51                   push ecx
// 004a1f31  52                   push edx
// 004a1f32  e839cbffff           call 0x49ea70
// 004a1f37  83c41c               add esp, 0x1c
// 004a1f3a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
