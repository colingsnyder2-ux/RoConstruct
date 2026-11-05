// from server: 100% by auto
// roc 2010-06 00455150  unit: CRobloxControlMaterialSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00455150
//
// 00455150  51                   push ecx
// 00455151  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00455155  8b542410             mov edx, dword ptr [esp + 0x10]
// 00455159  c6042400             mov byte ptr [esp], 0
// 0045515d  8b0424               mov eax, dword ptr [esp]
// 00455160  50                   push eax
// 00455161  8b442414             mov eax, dword ptr [esp + 0x14]
// 00455165  51                   push ecx
// 00455166  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0045516a  52                   push edx
// 0045516b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0045516f  50                   push eax
// 00455170  51                   push ecx
// 00455171  52                   push edx
// 00455172  e859feffff           call 0x454fd0
// 00455177  83c41c               add esp, 0x1c
// 0045517a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
