// from server: 100% by auto
// roc 2010-06 0096f670  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f670
//
// 0096f670  51                   push ecx
// 0096f671  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096f675  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096f679  c6042400             mov byte ptr [esp], 0
// 0096f67d  8b0424               mov eax, dword ptr [esp]
// 0096f680  50                   push eax
// 0096f681  8b442414             mov eax, dword ptr [esp + 0x14]
// 0096f685  51                   push ecx
// 0096f686  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0096f68a  52                   push edx
// 0096f68b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0096f68f  50                   push eax
// 0096f690  51                   push ecx
// 0096f691  52                   push edx
// 0096f692  e889feffff           call 0x96f520
// 0096f697  83c41c               add esp, 0x1c
// 0096f69a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
