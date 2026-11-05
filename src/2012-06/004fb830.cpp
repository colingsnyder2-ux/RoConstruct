// from server: 100% by auto
// roc 2012-06 004fb830  unit: Ogre::UTVertexTangent3DTexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004fb830
//
// 004fb830  51                   push ecx
// 004fb831  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fb835  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fb839  c6042400             mov byte ptr [esp], 0
// 004fb83d  8b0424               mov eax, dword ptr [esp]
// 004fb840  50                   push eax
// 004fb841  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fb845  51                   push ecx
// 004fb846  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fb84a  52                   push edx
// 004fb84b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004fb84f  50                   push eax
// 004fb850  51                   push ecx
// 004fb851  52                   push edx
// 004fb852  e839feffff           call 0x4fb690
// 004fb857  83c41c               add esp, 0x1c
// 004fb85a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
