// from server: 100% by auto
// roc 2012-06 00864480  unit: VWiniInetRequest_source::?$stream_buffer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864480
//
// 00864480  51                   push ecx
// 00864481  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00864485  8b542410             mov edx, dword ptr [esp + 0x10]
// 00864489  c6042400             mov byte ptr [esp], 0
// 0086448d  8b0424               mov eax, dword ptr [esp]
// 00864490  50                   push eax
// 00864491  8b442414             mov eax, dword ptr [esp + 0x14]
// 00864495  51                   push ecx
// 00864496  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086449a  52                   push edx
// 0086449b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0086449f  50                   push eax
// 008644a0  51                   push ecx
// 008644a1  52                   push edx
// 008644a2  e8c9f8ffff           call 0x863d70
// 008644a7  83c41c               add esp, 0x1c
// 008644aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
