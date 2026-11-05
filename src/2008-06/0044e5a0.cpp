// from server: 100% by coldek
// from server: 100% by auto
// roc 2008-06 0044e5a0  unit: CRobloxControlColorSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e5a0
//
// 0044e5a0  51                   push ecx
// 0044e5a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e5a5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044e5a9  c6042400             mov byte ptr [esp], 0
// 0044e5ad  8b0424               mov eax, dword ptr [esp]
// 0044e5b0  50                   push eax
// 0044e5b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044e5b5  51                   push ecx
// 0044e5b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044e5ba  52                   push edx
// 0044e5bb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044e5bf  50                   push eax
// 0044e5c0  51                   push ecx
// 0044e5c1  52                   push edx
// 0044e5c2  e8d9feffff           call 0x44e4a0
// 0044e5c7  83c41c               add esp, 0x1c
// 0044e5ca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
