// from server: 100% by auto
// roc 2011-06 00954f50  unit: Ogre::UTVertexTangent3DTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00954f50
//
// 00954f50  51                   push ecx
// 00954f51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00954f55  8b542410             mov edx, dword ptr [esp + 0x10]
// 00954f59  c6042400             mov byte ptr [esp], 0
// 00954f5d  8b0424               mov eax, dword ptr [esp]
// 00954f60  50                   push eax
// 00954f61  8b442414             mov eax, dword ptr [esp + 0x14]
// 00954f65  51                   push ecx
// 00954f66  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00954f6a  52                   push edx
// 00954f6b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00954f6f  50                   push eax
// 00954f70  51                   push ecx
// 00954f71  52                   push edx
// 00954f72  e859feffff           call 0x954dd0
// 00954f77  83c41c               add esp, 0x1c
// 00954f7a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
