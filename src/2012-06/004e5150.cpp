// from server: 100% by auto
// roc 2012-06 004e5150  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e5150
//
// 004e5150  51                   push ecx
// 004e5151  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e5155  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e5159  c6042400             mov byte ptr [esp], 0
// 004e515d  8b0424               mov eax, dword ptr [esp]
// 004e5160  50                   push eax
// 004e5161  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e5165  51                   push ecx
// 004e5166  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e516a  52                   push edx
// 004e516b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e516f  50                   push eax
// 004e5170  51                   push ecx
// 004e5171  52                   push edx
// 004e5172  e849f2ffff           call 0x4e43c0
// 004e5177  83c41c               add esp, 0x1c
// 004e517a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
