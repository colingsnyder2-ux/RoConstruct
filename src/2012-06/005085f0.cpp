// from server: 100% by auto
// roc 2012-06 005085f0  unit: Ogre::RbxSceneUpdater  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005085f0
//
// 005085f0  51                   push ecx
// 005085f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005085f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 005085f9  c6042400             mov byte ptr [esp], 0
// 005085fd  8b0424               mov eax, dword ptr [esp]
// 00508600  50                   push eax
// 00508601  8b442414             mov eax, dword ptr [esp + 0x14]
// 00508605  51                   push ecx
// 00508606  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0050860a  52                   push edx
// 0050860b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0050860f  50                   push eax
// 00508610  51                   push ecx
// 00508611  52                   push edx
// 00508612  e839fbffff           call 0x508150
// 00508617  83c41c               add esp, 0x1c
// 0050861a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
