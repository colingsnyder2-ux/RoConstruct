// from server: 100% by auto
// roc 2012-06 004fae80  unit: Ogre::UTVertexTangent3DTexColorIndexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004fae80
//
// 004fae80  51                   push ecx
// 004fae81  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fae85  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fae89  c6042400             mov byte ptr [esp], 0
// 004fae8d  8b0424               mov eax, dword ptr [esp]
// 004fae90  50                   push eax
// 004fae91  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fae95  51                   push ecx
// 004fae96  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fae9a  52                   push edx
// 004fae9b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004fae9f  50                   push eax
// 004faea0  51                   push ecx
// 004faea1  52                   push edx
// 004faea2  e839feffff           call 0x4face0
// 004faea7  83c41c               add esp, 0x1c
// 004faeaa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
