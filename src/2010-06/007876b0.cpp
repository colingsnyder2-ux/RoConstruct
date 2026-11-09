// from server: 100% by auto
// roc 2010-06 007876b0  unit: RBX::HUMAN::GettingUp  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007876b0
//
// 007876b0  51                   push ecx
// 007876b1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007876b5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007876b9  c6042400             mov byte ptr [esp], 0
// 007876bd  8b0424               mov eax, dword ptr [esp]
// 007876c0  50                   push eax
// 007876c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007876c5  51                   push ecx
// 007876c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007876ca  52                   push edx
// 007876cb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007876cf  50                   push eax
// 007876d0  51                   push ecx
// 007876d1  52                   push edx
// 007876d2  e899f9ffff           call 0x787070
// 007876d7  83c41c               add esp, 0x1c
// 007876da  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
