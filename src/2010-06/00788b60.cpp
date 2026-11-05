// from server: 100% by auto
// roc 2010-06 00788b60  unit: RBX::HUMAN::GettingUp  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788b60
//
// 00788b60  51                   push ecx
// 00788b61  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00788b65  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788b69  c6042400             mov byte ptr [esp], 0
// 00788b6d  8b0424               mov eax, dword ptr [esp]
// 00788b70  50                   push eax
// 00788b71  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788b75  51                   push ecx
// 00788b76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00788b7a  52                   push edx
// 00788b7b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00788b7f  50                   push eax
// 00788b80  51                   push ecx
// 00788b81  52                   push edx
// 00788b82  e839fdffff           call 0x7888c0
// 00788b87  83c41c               add esp, 0x1c
// 00788b8a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
