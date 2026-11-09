// from server: 100% by auto
// roc 2012-06 004f95f0  unit: Ogre::UTVertexSurfaceTexTangent::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f95f0
//
// 004f95f0  51                   push ecx
// 004f95f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f95f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f95f9  c6042400             mov byte ptr [esp], 0
// 004f95fd  8b0424               mov eax, dword ptr [esp]
// 004f9600  50                   push eax
// 004f9601  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f9605  51                   push ecx
// 004f9606  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f960a  52                   push edx
// 004f960b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f960f  50                   push eax
// 004f9610  51                   push ecx
// 004f9611  52                   push edx
// 004f9612  e859feffff           call 0x4f9470
// 004f9617  83c41c               add esp, 0x1c
// 004f961a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
