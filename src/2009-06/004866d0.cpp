// from server: 100% by auto
// roc 2009-06 004866d0  unit: Ogre::RbxMeshPartAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004866d0
//
// 004866d0  51                   push ecx
// 004866d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004866d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004866d9  c6042400             mov byte ptr [esp], 0
// 004866dd  8b0424               mov eax, dword ptr [esp]
// 004866e0  50                   push eax
// 004866e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004866e5  51                   push ecx
// 004866e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004866ea  52                   push edx
// 004866eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 004866ef  50                   push eax
// 004866f0  51                   push ecx
// 004866f1  52                   push edx
// 004866f2  e8e9f6ffff           call 0x485de0
// 004866f7  83c41c               add esp, 0x1c
// 004866fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
