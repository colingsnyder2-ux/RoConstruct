// from server: 100% by auto
// roc 2012-06 005a9ab0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a9ab0
//
// 005a9ab0  51                   push ecx
// 005a9ab1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a9ab5  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a9ab9  c6042400             mov byte ptr [esp], 0
// 005a9abd  8b0424               mov eax, dword ptr [esp]
// 005a9ac0  50                   push eax
// 005a9ac1  8b442414             mov eax, dword ptr [esp + 0x14]
// 005a9ac5  51                   push ecx
// 005a9ac6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005a9aca  52                   push edx
// 005a9acb  8b542414             mov edx, dword ptr [esp + 0x14]
// 005a9acf  50                   push eax
// 005a9ad0  51                   push ecx
// 005a9ad1  52                   push edx
// 005a9ad2  e8f9fcffff           call 0x5a97d0
// 005a9ad7  83c41c               add esp, 0x1c
// 005a9ada  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
