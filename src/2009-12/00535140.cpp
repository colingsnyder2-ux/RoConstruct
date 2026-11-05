// from server: 100% by auto
// roc 2009-12 00535140  unit: RBX::Network::IdSerializer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00535140
//
// 00535140  51                   push ecx
// 00535141  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00535145  8b542410             mov edx, dword ptr [esp + 0x10]
// 00535149  c6042400             mov byte ptr [esp], 0
// 0053514d  8b0424               mov eax, dword ptr [esp]
// 00535150  50                   push eax
// 00535151  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535155  51                   push ecx
// 00535156  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0053515a  52                   push edx
// 0053515b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053515f  50                   push eax
// 00535160  51                   push ecx
// 00535161  52                   push edx
// 00535162  e8e9f1ffff           call 0x534350
// 00535167  83c41c               add esp, 0x1c
// 0053516a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
