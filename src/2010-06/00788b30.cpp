// from server: 100% by auto
// roc 2010-06 00788b30  unit: RBX::HUMAN::GettingUp  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788b30
//
// 00788b30  51                   push ecx
// 00788b31  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00788b35  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788b39  c6042400             mov byte ptr [esp], 0
// 00788b3d  8b0424               mov eax, dword ptr [esp]
// 00788b40  50                   push eax
// 00788b41  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788b45  51                   push ecx
// 00788b46  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00788b4a  52                   push edx
// 00788b4b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00788b4f  50                   push eax
// 00788b50  51                   push ecx
// 00788b51  52                   push edx
// 00788b52  e809fdffff           call 0x788860
// 00788b57  83c41c               add esp, 0x1c
// 00788b5a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
