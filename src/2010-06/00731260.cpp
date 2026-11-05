// from server: 100% by auto
// roc 2010-06 00731260  unit: lua_exception  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731260
//
// 00731260  51                   push ecx
// 00731261  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00731265  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731269  c6042400             mov byte ptr [esp], 0
// 0073126d  8b0424               mov eax, dword ptr [esp]
// 00731270  50                   push eax
// 00731271  8b442414             mov eax, dword ptr [esp + 0x14]
// 00731275  51                   push ecx
// 00731276  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0073127a  52                   push edx
// 0073127b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0073127f  50                   push eax
// 00731280  51                   push ecx
// 00731281  52                   push edx
// 00731282  e899fbffff           call 0x730e20
// 00731287  83c41c               add esp, 0x1c
// 0073128a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
