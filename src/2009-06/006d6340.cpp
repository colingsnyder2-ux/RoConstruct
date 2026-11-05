// from server: 100% by auto
// roc 2009-06 006d6340  unit: RBX::Mechanism  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6340
//
// 006d6340  51                   push ecx
// 006d6341  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006d6345  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d6349  c6042400             mov byte ptr [esp], 0
// 006d634d  8b0424               mov eax, dword ptr [esp]
// 006d6350  50                   push eax
// 006d6351  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d6355  51                   push ecx
// 006d6356  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006d635a  52                   push edx
// 006d635b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006d635f  50                   push eax
// 006d6360  51                   push ecx
// 006d6361  52                   push edx
// 006d6362  e839fcffff           call 0x6d5fa0
// 006d6367  83c41c               add esp, 0x1c
// 006d636a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
