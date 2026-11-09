// from server: 100% by auto
// roc 2012-06 009502c0  unit: RBX::AdvRotateTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009502c0
//
// 009502c0  51                   push ecx
// 009502c1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009502c5  8b542410             mov edx, dword ptr [esp + 0x10]
// 009502c9  c6042400             mov byte ptr [esp], 0
// 009502cd  8b0424               mov eax, dword ptr [esp]
// 009502d0  50                   push eax
// 009502d1  8b442414             mov eax, dword ptr [esp + 0x14]
// 009502d5  51                   push ecx
// 009502d6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009502da  52                   push edx
// 009502db  8b542414             mov edx, dword ptr [esp + 0x14]
// 009502df  50                   push eax
// 009502e0  51                   push ecx
// 009502e1  52                   push edx
// 009502e2  e879f8ffff           call 0x94fb60
// 009502e7  83c41c               add esp, 0x1c
// 009502ea  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
