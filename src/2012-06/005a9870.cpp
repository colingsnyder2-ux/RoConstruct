// from server: 100% by auto
// roc 2012-06 005a9870  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a9870
//
// 005a9870  51                   push ecx
// 005a9871  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a9875  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a9879  c6042400             mov byte ptr [esp], 0
// 005a987d  8b0424               mov eax, dword ptr [esp]
// 005a9880  50                   push eax
// 005a9881  8b442414             mov eax, dword ptr [esp + 0x14]
// 005a9885  51                   push ecx
// 005a9886  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005a988a  52                   push edx
// 005a988b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005a988f  50                   push eax
// 005a9890  51                   push ecx
// 005a9891  52                   push edx
// 005a9892  e8c9fcffff           call 0x5a9560
// 005a9897  83c41c               add esp, 0x1c
// 005a989a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
