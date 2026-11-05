// from server: 100% by auto
// roc 2012-06 00478270  unit: CRobloxControlColorSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00478270
//
// 00478270  51                   push ecx
// 00478271  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00478275  8b542410             mov edx, dword ptr [esp + 0x10]
// 00478279  c6042400             mov byte ptr [esp], 0
// 0047827d  8b0424               mov eax, dword ptr [esp]
// 00478280  50                   push eax
// 00478281  8b442414             mov eax, dword ptr [esp + 0x14]
// 00478285  51                   push ecx
// 00478286  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047828a  52                   push edx
// 0047828b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0047828f  50                   push eax
// 00478290  51                   push ecx
// 00478291  52                   push edx
// 00478292  e889faffff           call 0x477d20
// 00478297  83c41c               add esp, 0x1c
// 0047829a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
