// from server: 100% by auto
// roc 2012-06 006df5d0  unit: RBX::VFunctionalTest::?$FactoryProduct::Creator  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006df5d0
//
// 006df5d0  51                   push ecx
// 006df5d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006df5d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006df5d9  c6042400             mov byte ptr [esp], 0
// 006df5dd  8b0424               mov eax, dword ptr [esp]
// 006df5e0  50                   push eax
// 006df5e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 006df5e5  51                   push ecx
// 006df5e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006df5ea  52                   push edx
// 006df5eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 006df5ef  50                   push eax
// 006df5f0  51                   push ecx
// 006df5f1  52                   push edx
// 006df5f2  e8b9b9ffff           call 0x6dafb0
// 006df5f7  83c41c               add esp, 0x1c
// 006df5fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
