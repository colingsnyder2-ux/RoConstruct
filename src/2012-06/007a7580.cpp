// from server: 100% by auto
// roc 2012-06 007a7580  unit: RBX::KeyframeSequence  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a7580
//
// 007a7580  51                   push ecx
// 007a7581  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a7585  8b542410             mov edx, dword ptr [esp + 0x10]
// 007a7589  c6042400             mov byte ptr [esp], 0
// 007a758d  8b0424               mov eax, dword ptr [esp]
// 007a7590  50                   push eax
// 007a7591  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a7595  51                   push ecx
// 007a7596  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a759a  52                   push edx
// 007a759b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a759f  50                   push eax
// 007a75a0  51                   push ecx
// 007a75a1  52                   push edx
// 007a75a2  e8b947d5ff           call 0x4fbd60
// 007a75a7  83c41c               add esp, 0x1c
// 007a75aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
