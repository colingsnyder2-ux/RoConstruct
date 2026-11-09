// from server: 100% by auto
// roc 2011-06 007e7f80  unit: RBX::AdvRotateTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e7f80
//
// 007e7f80  51                   push ecx
// 007e7f81  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e7f85  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e7f89  c6042400             mov byte ptr [esp], 0
// 007e7f8d  8b0424               mov eax, dword ptr [esp]
// 007e7f90  50                   push eax
// 007e7f91  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e7f95  51                   push ecx
// 007e7f96  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e7f9a  52                   push edx
// 007e7f9b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e7f9f  50                   push eax
// 007e7fa0  51                   push ecx
// 007e7fa1  52                   push edx
// 007e7fa2  e8a9f8ffff           call 0x7e7850
// 007e7fa7  83c41c               add esp, 0x1c
// 007e7faa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
