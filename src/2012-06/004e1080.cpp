// from server: 100% by auto
// roc 2012-06 004e1080  unit: Ogre::RbxTextureCompositorSceneManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e1080
//
// 004e1080  51                   push ecx
// 004e1081  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e1085  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e1089  c6042400             mov byte ptr [esp], 0
// 004e108d  8b0424               mov eax, dword ptr [esp]
// 004e1090  50                   push eax
// 004e1091  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e1095  51                   push ecx
// 004e1096  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e109a  52                   push edx
// 004e109b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e109f  50                   push eax
// 004e10a0  51                   push ecx
// 004e10a1  52                   push edx
// 004e10a2  e839edffff           call 0x4dfde0
// 004e10a7  83c41c               add esp, 0x1c
// 004e10aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
