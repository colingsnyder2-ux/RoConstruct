// from server: 100% by auto
// roc 2008-06 004dcd60  unit: RBX::ViewNew::ViewG3D  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dcd60
//
// 004dcd60  51                   push ecx
// 004dcd61  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dcd65  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dcd69  c6042400             mov byte ptr [esp], 0
// 004dcd6d  8b0424               mov eax, dword ptr [esp]
// 004dcd70  50                   push eax
// 004dcd71  8b442414             mov eax, dword ptr [esp + 0x14]
// 004dcd75  51                   push ecx
// 004dcd76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004dcd7a  52                   push edx
// 004dcd7b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004dcd7f  50                   push eax
// 004dcd80  51                   push ecx
// 004dcd81  52                   push edx
// 004dcd82  e849241a00           call 0x67f1d0
// 004dcd87  83c41c               add esp, 0x1c
// 004dcd8a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
