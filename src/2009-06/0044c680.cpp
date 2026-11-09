// from server: 100% by auto
// roc 2009-06 0044c680  unit: CRobloxControlColorSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c680
//
// 0044c680  51                   push ecx
// 0044c681  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c685  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c689  c6042400             mov byte ptr [esp], 0
// 0044c68d  8b0424               mov eax, dword ptr [esp]
// 0044c690  50                   push eax
// 0044c691  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044c695  51                   push ecx
// 0044c696  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044c69a  52                   push edx
// 0044c69b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044c69f  50                   push eax
// 0044c6a0  51                   push ecx
// 0044c6a1  52                   push edx
// 0044c6a2  e8d9feffff           call 0x44c580
// 0044c6a7  83c41c               add esp, 0x1c
// 0044c6aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
