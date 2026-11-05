// from server: 100% by auto
// roc 2007-08 004a1b20  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1b20
//
// 004a1b20  51                   push ecx
// 004a1b21  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1b25  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1b29  c6042400             mov byte ptr [esp], 0
// 004a1b2d  8b0424               mov eax, dword ptr [esp]
// 004a1b30  50                   push eax
// 004a1b31  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a1b35  51                   push ecx
// 004a1b36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a1b3a  52                   push edx
// 004a1b3b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1b3f  50                   push eax
// 004a1b40  51                   push ecx
// 004a1b41  52                   push edx
// 004a1b42  e8a9f7ffff           call 0x4a12f0
// 004a1b47  83c41c               add esp, 0x1c
// 004a1b4a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
