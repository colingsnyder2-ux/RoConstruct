// from server: 100% by auto
// roc 2011-06 00746240  unit: RBX::Animator  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00746240
//
// 00746240  51                   push ecx
// 00746241  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00746245  8b542410             mov edx, dword ptr [esp + 0x10]
// 00746249  c6042400             mov byte ptr [esp], 0
// 0074624d  8b0424               mov eax, dword ptr [esp]
// 00746250  50                   push eax
// 00746251  8b442414             mov eax, dword ptr [esp + 0x14]
// 00746255  51                   push ecx
// 00746256  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074625a  52                   push edx
// 0074625b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0074625f  50                   push eax
// 00746260  51                   push ecx
// 00746261  52                   push edx
// 00746262  e839fbffff           call 0x745da0
// 00746267  83c41c               add esp, 0x1c
// 0074626a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
