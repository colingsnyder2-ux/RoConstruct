// from server: 100% by auto
// roc 2012-06 004e4f50  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e4f50
//
// 004e4f50  51                   push ecx
// 004e4f51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e4f55  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e4f59  c6042400             mov byte ptr [esp], 0
// 004e4f5d  8b0424               mov eax, dword ptr [esp]
// 004e4f60  50                   push eax
// 004e4f61  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e4f65  51                   push ecx
// 004e4f66  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e4f6a  52                   push edx
// 004e4f6b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e4f6f  50                   push eax
// 004e4f70  51                   push ecx
// 004e4f71  52                   push edx
// 004e4f72  e8f9edffff           call 0x4e3d70
// 004e4f77  83c41c               add esp, 0x1c
// 004e4f7a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
