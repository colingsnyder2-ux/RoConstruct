// from server: 100% by auto
// roc 2012-06 00462bd0  unit: RBX::MergeBinder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00462bd0
//
// 00462bd0  51                   push ecx
// 00462bd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00462bd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00462bd9  c6042400             mov byte ptr [esp], 0
// 00462bdd  8b0424               mov eax, dword ptr [esp]
// 00462be0  50                   push eax
// 00462be1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00462be5  51                   push ecx
// 00462be6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00462bea  52                   push edx
// 00462beb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00462bef  50                   push eax
// 00462bf0  51                   push ecx
// 00462bf1  52                   push edx
// 00462bf2  e879feffff           call 0x462a70
// 00462bf7  83c41c               add esp, 0x1c
// 00462bfa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
