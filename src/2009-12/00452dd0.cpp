// from server: 100% by auto
// roc 2009-12 00452dd0  unit: CRobloxControlColorSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00452dd0
//
// 00452dd0  51                   push ecx
// 00452dd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00452dd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00452dd9  c6042400             mov byte ptr [esp], 0
// 00452ddd  8b0424               mov eax, dword ptr [esp]
// 00452de0  50                   push eax
// 00452de1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00452de5  51                   push ecx
// 00452de6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452dea  52                   push edx
// 00452deb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00452def  50                   push eax
// 00452df0  51                   push ecx
// 00452df1  52                   push edx
// 00452df2  e8a9fdffff           call 0x452ba0
// 00452df7  83c41c               add esp, 0x1c
// 00452dfa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
