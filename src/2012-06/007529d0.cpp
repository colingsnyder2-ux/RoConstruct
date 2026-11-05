// from server: 100% by auto
// roc 2012-06 007529d0  unit: RBX::PartInstance  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007529d0
//
// 007529d0  51                   push ecx
// 007529d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007529d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007529d9  c6042400             mov byte ptr [esp], 0
// 007529dd  8b0424               mov eax, dword ptr [esp]
// 007529e0  50                   push eax
// 007529e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007529e5  51                   push ecx
// 007529e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007529ea  52                   push edx
// 007529eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007529ef  50                   push eax
// 007529f0  51                   push ecx
// 007529f1  52                   push edx
// 007529f2  e819e3ffff           call 0x750d10
// 007529f7  83c41c               add esp, 0x1c
// 007529fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
