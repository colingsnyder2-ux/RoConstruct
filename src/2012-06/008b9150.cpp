// from server: 100% by auto
// roc 2012-06 008b9150  unit: seg_008b0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b9150
//
// 008b9150  51                   push ecx
// 008b9151  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008b9155  8b542410             mov edx, dword ptr [esp + 0x10]
// 008b9159  c6042400             mov byte ptr [esp], 0
// 008b915d  8b0424               mov eax, dword ptr [esp]
// 008b9160  50                   push eax
// 008b9161  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b9165  51                   push ecx
// 008b9166  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b916a  52                   push edx
// 008b916b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b916f  50                   push eax
// 008b9170  51                   push ecx
// 008b9171  52                   push edx
// 008b9172  e8c9f8ffff           call 0x8b8a40
// 008b9177  83c41c               add esp, 0x1c
// 008b917a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
