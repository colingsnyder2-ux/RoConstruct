// from server: 100% by auto
// roc 2009-12 007b3600  unit: RBX::Assembly  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3600
//
// 007b3600  51                   push ecx
// 007b3601  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007b3605  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3609  c6042400             mov byte ptr [esp], 0
// 007b360d  8b0424               mov eax, dword ptr [esp]
// 007b3610  50                   push eax
// 007b3611  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b3615  51                   push ecx
// 007b3616  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007b361a  52                   push edx
// 007b361b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b361f  50                   push eax
// 007b3620  51                   push ecx
// 007b3621  52                   push edx
// 007b3622  e8b9fbffff           call 0x7b31e0
// 007b3627  83c41c               add esp, 0x1c
// 007b362a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
