// from server: 100% by auto
// roc 2012-06 00819f60  unit: RBX::ChatService  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00819f60
//
// 00819f60  51                   push ecx
// 00819f61  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00819f65  8b542410             mov edx, dword ptr [esp + 0x10]
// 00819f69  c6042400             mov byte ptr [esp], 0
// 00819f6d  8b0424               mov eax, dword ptr [esp]
// 00819f70  50                   push eax
// 00819f71  8b442414             mov eax, dword ptr [esp + 0x14]
// 00819f75  51                   push ecx
// 00819f76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00819f7a  52                   push edx
// 00819f7b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00819f7f  50                   push eax
// 00819f80  51                   push ecx
// 00819f81  52                   push edx
// 00819f82  e889feffff           call 0x819e10
// 00819f87  83c41c               add esp, 0x1c
// 00819f8a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
