// from server: 100% by auto
// roc 2011-06 007e7610  unit: RBX::AdvRotateTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e7610
//
// 007e7610  51                   push ecx
// 007e7611  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e7615  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e7619  c6042400             mov byte ptr [esp], 0
// 007e761d  8b0424               mov eax, dword ptr [esp]
// 007e7620  50                   push eax
// 007e7621  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e7625  51                   push ecx
// 007e7626  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e762a  52                   push edx
// 007e762b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e762f  50                   push eax
// 007e7630  51                   push ecx
// 007e7631  52                   push edx
// 007e7632  e8a9f0ffff           call 0x7e66e0
// 007e7637  83c41c               add esp, 0x1c
// 007e763a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
