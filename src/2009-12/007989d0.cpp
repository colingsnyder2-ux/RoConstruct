// from server: 100% by auto
// roc 2009-12 007989d0  unit: lua_exception  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007989d0
//
// 007989d0  51                   push ecx
// 007989d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007989d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007989d9  c6042400             mov byte ptr [esp], 0
// 007989dd  8b0424               mov eax, dword ptr [esp]
// 007989e0  50                   push eax
// 007989e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007989e5  51                   push ecx
// 007989e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007989ea  52                   push edx
// 007989eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007989ef  50                   push eax
// 007989f0  51                   push ecx
// 007989f1  52                   push edx
// 007989f2  e8d9faffff           call 0x7984d0
// 007989f7  83c41c               add esp, 0x1c
// 007989fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
