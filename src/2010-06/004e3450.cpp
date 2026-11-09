// from server: 100% by auto
// roc 2010-06 004e3450  unit: RBX::Network::IdSerializer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e3450
//
// 004e3450  51                   push ecx
// 004e3451  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e3455  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e3459  c6042400             mov byte ptr [esp], 0
// 004e345d  8b0424               mov eax, dword ptr [esp]
// 004e3460  50                   push eax
// 004e3461  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e3465  51                   push ecx
// 004e3466  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e346a  52                   push edx
// 004e346b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004e346f  50                   push eax
// 004e3470  51                   push ecx
// 004e3471  52                   push edx
// 004e3472  e8e9f1ffff           call 0x4e2660
// 004e3477  83c41c               add esp, 0x1c
// 004e347a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
