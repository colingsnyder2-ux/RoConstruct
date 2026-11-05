// from server: 100% by auto
// roc 2012-06 005e0690  unit: RBX::BeveledBlockBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005e0690
//
// 005e0690  51                   push ecx
// 005e0691  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e0695  8b542410             mov edx, dword ptr [esp + 0x10]
// 005e0699  c6042400             mov byte ptr [esp], 0
// 005e069d  8b0424               mov eax, dword ptr [esp]
// 005e06a0  50                   push eax
// 005e06a1  8b442414             mov eax, dword ptr [esp + 0x14]
// 005e06a5  51                   push ecx
// 005e06a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005e06aa  52                   push edx
// 005e06ab  8b542414             mov edx, dword ptr [esp + 0x14]
// 005e06af  50                   push eax
// 005e06b0  51                   push ecx
// 005e06b1  52                   push edx
// 005e06b2  e889e2ffff           call 0x5de940
// 005e06b7  83c41c               add esp, 0x1c
// 005e06ba  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
