// from server: 100% by auto
// roc 2011-06 00955860  unit: Ogre::UTVertexTangent3DTexColorIndexSurfaceTex::?$SpecializedMeshGen  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00955860
//
// 00955860  51                   push ecx
// 00955861  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00955865  8b542410             mov edx, dword ptr [esp + 0x10]
// 00955869  c6042400             mov byte ptr [esp], 0
// 0095586d  8b0424               mov eax, dword ptr [esp]
// 00955870  50                   push eax
// 00955871  8b442414             mov eax, dword ptr [esp + 0x14]
// 00955875  51                   push ecx
// 00955876  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095587a  52                   push edx
// 0095587b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095587f  50                   push eax
// 00955880  51                   push ecx
// 00955881  52                   push edx
// 00955882  e839feffff           call 0x9556c0
// 00955887  83c41c               add esp, 0x1c
// 0095588a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
