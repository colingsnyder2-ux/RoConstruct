// from server: 100% by auto
// roc 2010-06 009759d0  unit: RBX::RightAngleRampBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009759d0
//
// 009759d0  51                   push ecx
// 009759d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009759d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 009759d9  c6042400             mov byte ptr [esp], 0
// 009759dd  8b0424               mov eax, dword ptr [esp]
// 009759e0  50                   push eax
// 009759e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 009759e5  51                   push ecx
// 009759e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009759ea  52                   push edx
// 009759eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 009759ef  50                   push eax
// 009759f0  51                   push ecx
// 009759f1  52                   push edx
// 009759f2  e859feffff           call 0x975850
// 009759f7  83c41c               add esp, 0x1c
// 009759fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
