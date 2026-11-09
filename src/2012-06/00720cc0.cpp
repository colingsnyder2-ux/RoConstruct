// from server: 100% by auto
// roc 2012-06 00720cc0  unit: RBX::VIAdornableCollector::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00720cc0
//
// 00720cc0  51                   push ecx
// 00720cc1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00720cc5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00720cc9  c6042400             mov byte ptr [esp], 0
// 00720ccd  8b0424               mov eax, dword ptr [esp]
// 00720cd0  50                   push eax
// 00720cd1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00720cd5  51                   push ecx
// 00720cd6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00720cda  52                   push edx
// 00720cdb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00720cdf  50                   push eax
// 00720ce0  51                   push ecx
// 00720ce1  52                   push edx
// 00720ce2  e8f9f7ffff           call 0x7204e0
// 00720ce7  83c41c               add esp, 0x1c
// 00720cea  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
