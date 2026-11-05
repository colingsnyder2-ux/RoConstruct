// from server: 100% by auto
// roc 2012-06 004f8cf0  unit: Ogre::UTVertexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f8cf0
//
// 004f8cf0  51                   push ecx
// 004f8cf1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f8cf5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f8cf9  c6042400             mov byte ptr [esp], 0
// 004f8cfd  8b0424               mov eax, dword ptr [esp]
// 004f8d00  50                   push eax
// 004f8d01  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f8d05  51                   push ecx
// 004f8d06  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f8d0a  52                   push edx
// 004f8d0b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f8d0f  50                   push eax
// 004f8d10  51                   push ecx
// 004f8d11  52                   push edx
// 004f8d12  e879feffff           call 0x4f8b90
// 004f8d17  83c41c               add esp, 0x1c
// 004f8d1a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
