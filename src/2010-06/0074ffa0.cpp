// from server: 100% by auto
// roc 2010-06 0074ffa0  unit: RBX::Humanoid  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074ffa0
//
// 0074ffa0  51                   push ecx
// 0074ffa1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0074ffa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074ffa9  c6042400             mov byte ptr [esp], 0
// 0074ffad  8b0424               mov eax, dword ptr [esp]
// 0074ffb0  50                   push eax
// 0074ffb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0074ffb5  51                   push ecx
// 0074ffb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074ffba  52                   push edx
// 0074ffbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0074ffbf  50                   push eax
// 0074ffc0  51                   push ecx
// 0074ffc1  52                   push edx
// 0074ffc2  e8b9fbffff           call 0x74fb80
// 0074ffc7  83c41c               add esp, 0x1c
// 0074ffca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
