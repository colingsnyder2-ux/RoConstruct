// from server: 100% by auto
// roc 2011-06 00450fd0  unit: RBX::MergeBinder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00450fd0
//
// 00450fd0  51                   push ecx
// 00450fd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00450fd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00450fd9  c6042400             mov byte ptr [esp], 0
// 00450fdd  8b0424               mov eax, dword ptr [esp]
// 00450fe0  50                   push eax
// 00450fe1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00450fe5  51                   push ecx
// 00450fe6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00450fea  52                   push edx
// 00450feb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00450fef  50                   push eax
// 00450ff0  51                   push ecx
// 00450ff1  52                   push edx
// 00450ff2  e8c93a1c00           call 0x614ac0
// 00450ff7  83c41c               add esp, 0x1c
// 00450ffa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
