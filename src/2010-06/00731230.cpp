// from server: 100% by auto
// roc 2010-06 00731230  unit: lua_exception  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731230
//
// 00731230  51                   push ecx
// 00731231  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00731235  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731239  c6042400             mov byte ptr [esp], 0
// 0073123d  8b0424               mov eax, dword ptr [esp]
// 00731240  50                   push eax
// 00731241  8b442414             mov eax, dword ptr [esp + 0x14]
// 00731245  51                   push ecx
// 00731246  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0073124a  52                   push edx
// 0073124b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0073124f  50                   push eax
// 00731250  51                   push ecx
// 00731251  52                   push edx
// 00731252  e869fbffff           call 0x730dc0
// 00731257  83c41c               add esp, 0x1c
// 0073125a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
