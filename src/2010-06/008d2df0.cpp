// from server: 100% by auto
// roc 2010-06 008d2df0  unit: Ogre::VisualEngine  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2df0
//
// 008d2df0  51                   push ecx
// 008d2df1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d2df5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d2df9  c6042400             mov byte ptr [esp], 0
// 008d2dfd  8b0424               mov eax, dword ptr [esp]
// 008d2e00  50                   push eax
// 008d2e01  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d2e05  51                   push ecx
// 008d2e06  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d2e0a  52                   push edx
// 008d2e0b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d2e0f  50                   push eax
// 008d2e10  51                   push ecx
// 008d2e11  52                   push edx
// 008d2e12  e8b9f9ffff           call 0x8d27d0
// 008d2e17  83c41c               add esp, 0x1c
// 008d2e1a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
