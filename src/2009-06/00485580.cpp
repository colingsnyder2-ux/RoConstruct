// from server: 100% by auto
// roc 2009-06 00485580  unit: RBX::MeshFileKey  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485580
//
// 00485580  51                   push ecx
// 00485581  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00485585  8b542410             mov edx, dword ptr [esp + 0x10]
// 00485589  c6042400             mov byte ptr [esp], 0
// 0048558d  8b0424               mov eax, dword ptr [esp]
// 00485590  50                   push eax
// 00485591  8b442414             mov eax, dword ptr [esp + 0x14]
// 00485595  51                   push ecx
// 00485596  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048559a  52                   push edx
// 0048559b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048559f  50                   push eax
// 004855a0  51                   push ecx
// 004855a1  52                   push edx
// 004855a2  e8c9d5ffff           call 0x482b70
// 004855a7  83c41c               add esp, 0x1c
// 004855aa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
