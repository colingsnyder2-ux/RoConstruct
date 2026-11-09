// from server: 100% by auto
// roc 2011-06 00779c70  unit: seg_00770000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00779c70
//
// 00779c70  51                   push ecx
// 00779c71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00779c75  8b542410             mov edx, dword ptr [esp + 0x10]
// 00779c79  c6042400             mov byte ptr [esp], 0
// 00779c7d  8b0424               mov eax, dword ptr [esp]
// 00779c80  50                   push eax
// 00779c81  8b442414             mov eax, dword ptr [esp + 0x14]
// 00779c85  51                   push ecx
// 00779c86  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00779c8a  52                   push edx
// 00779c8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00779c8f  50                   push eax
// 00779c90  51                   push ecx
// 00779c91  52                   push edx
// 00779c92  e819fcffff           call 0x7798b0
// 00779c97  83c41c               add esp, 0x1c
// 00779c9a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
