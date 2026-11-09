// from server: 100% by auto
// roc 2011-06 00956170  unit: Ogre::UTVertexTangent3DTexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00956170
//
// 00956170  51                   push ecx
// 00956171  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00956175  8b542410             mov edx, dword ptr [esp + 0x10]
// 00956179  c6042400             mov byte ptr [esp], 0
// 0095617d  8b0424               mov eax, dword ptr [esp]
// 00956180  50                   push eax
// 00956181  8b442414             mov eax, dword ptr [esp + 0x14]
// 00956185  51                   push ecx
// 00956186  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095618a  52                   push edx
// 0095618b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095618f  50                   push eax
// 00956190  51                   push ecx
// 00956191  52                   push edx
// 00956192  e839feffff           call 0x955fd0
// 00956197  83c41c               add esp, 0x1c
// 0095619a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
