// from server: 100% by auto
// roc 2007-08 0044c2c0  unit: CRobloxControlColorSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c2c0
//
// 0044c2c0  51                   push ecx
// 0044c2c1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c2c5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c2c9  c6042400             mov byte ptr [esp], 0
// 0044c2cd  8b0424               mov eax, dword ptr [esp]
// 0044c2d0  50                   push eax
// 0044c2d1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044c2d5  51                   push ecx
// 0044c2d6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044c2da  52                   push edx
// 0044c2db  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044c2df  50                   push eax
// 0044c2e0  51                   push ecx
// 0044c2e1  52                   push edx
// 0044c2e2  e8f9fdffff           call 0x44c0e0
// 0044c2e7  83c41c               add esp, 0x1c
// 0044c2ea  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
