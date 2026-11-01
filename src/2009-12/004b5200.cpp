// from server: 100% by auto
// roc 2009-12 004b5200  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b5200
//
// 004b5200  51                   push ecx
// 004b5201  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b5205  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b5209  c6042400             mov byte ptr [esp], 0
// 004b520d  8b0424               mov eax, dword ptr [esp]
// 004b5210  50                   push eax
// 004b5211  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b5215  51                   push ecx
// 004b5216  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b521a  52                   push edx
// 004b521b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b521f  50                   push eax
// 004b5220  51                   push ecx
// 004b5221  52                   push edx
// 004b5222  e839efffff           call 0x4b4160
// 004b5227  83c41c               add esp, 0x1c
// 004b522a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
