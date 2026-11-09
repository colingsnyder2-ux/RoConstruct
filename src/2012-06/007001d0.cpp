// from server: 100% by auto
// roc 2012-06 007001d0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007001d0
//
// 007001d0  51                   push ecx
// 007001d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007001d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007001d9  c6042400             mov byte ptr [esp], 0
// 007001dd  8b0424               mov eax, dword ptr [esp]
// 007001e0  50                   push eax
// 007001e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007001e5  51                   push ecx
// 007001e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007001ea  52                   push edx
// 007001eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007001ef  50                   push eax
// 007001f0  51                   push ecx
// 007001f1  52                   push edx
// 007001f2  e859f5ffff           call 0x6ff750
// 007001f7  83c41c               add esp, 0x1c
// 007001fa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
