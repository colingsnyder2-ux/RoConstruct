// from server: 100% by auto
// roc 2012-06 009502f0  unit: RBX::AdvRotateTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009502f0
//
// 009502f0  51                   push ecx
// 009502f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009502f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 009502f9  c6042400             mov byte ptr [esp], 0
// 009502fd  8b0424               mov eax, dword ptr [esp]
// 00950300  50                   push eax
// 00950301  8b442414             mov eax, dword ptr [esp + 0x14]
// 00950305  51                   push ecx
// 00950306  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095030a  52                   push edx
// 0095030b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095030f  50                   push eax
// 00950310  51                   push ecx
// 00950311  52                   push edx
// 00950312  e8b9f8ffff           call 0x94fbd0
// 00950317  83c41c               add esp, 0x1c
// 0095031a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
