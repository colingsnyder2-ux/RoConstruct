// from server: 100% by auto
// roc 2012-06 0091d4c0  unit: seg_00910000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091d4c0
//
// 0091d4c0  51                   push ecx
// 0091d4c1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0091d4c5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0091d4c9  c6042400             mov byte ptr [esp], 0
// 0091d4cd  8b0424               mov eax, dword ptr [esp]
// 0091d4d0  50                   push eax
// 0091d4d1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0091d4d5  51                   push ecx
// 0091d4d6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0091d4da  52                   push edx
// 0091d4db  8b542414             mov edx, dword ptr [esp + 0x14]
// 0091d4df  50                   push eax
// 0091d4e0  51                   push ecx
// 0091d4e1  52                   push edx
// 0091d4e2  e849f7ffff           call 0x91cc30
// 0091d4e7  83c41c               add esp, 0x1c
// 0091d4ea  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
