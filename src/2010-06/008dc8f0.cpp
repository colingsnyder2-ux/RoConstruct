// from server: 100% by auto
// roc 2010-06 008dc8f0  unit: Ogre::RbxMaterialAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dc8f0
//
// 008dc8f0  51                   push ecx
// 008dc8f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008dc8f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dc8f9  c6042400             mov byte ptr [esp], 0
// 008dc8fd  8b0424               mov eax, dword ptr [esp]
// 008dc900  50                   push eax
// 008dc901  8b442414             mov eax, dword ptr [esp + 0x14]
// 008dc905  51                   push ecx
// 008dc906  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008dc90a  52                   push edx
// 008dc90b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008dc90f  50                   push eax
// 008dc910  51                   push ecx
// 008dc911  52                   push edx
// 008dc912  e8f9efffff           call 0x8db910
// 008dc917  83c41c               add esp, 0x1c
// 008dc91a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
