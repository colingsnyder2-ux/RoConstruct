// from server: 100% by auto
// roc 2012-06 00852670  unit: RBX::CoreScript  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00852670
//
// 00852670  51                   push ecx
// 00852671  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00852675  8b542410             mov edx, dword ptr [esp + 0x10]
// 00852679  c6042400             mov byte ptr [esp], 0
// 0085267d  8b0424               mov eax, dword ptr [esp]
// 00852680  50                   push eax
// 00852681  8b442414             mov eax, dword ptr [esp + 0x14]
// 00852685  51                   push ecx
// 00852686  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0085268a  52                   push edx
// 0085268b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0085268f  50                   push eax
// 00852690  51                   push ecx
// 00852691  52                   push edx
// 00852692  e859fbffff           call 0x8521f0
// 00852697  83c41c               add esp, 0x1c
// 0085269a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
