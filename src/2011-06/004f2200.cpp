// from server: 100% by auto
// roc 2011-06 004f2200  unit: RBX::Network::IdSerializer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f2200
//
// 004f2200  51                   push ecx
// 004f2201  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f2205  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f2209  c6042400             mov byte ptr [esp], 0
// 004f220d  8b0424               mov eax, dword ptr [esp]
// 004f2210  50                   push eax
// 004f2211  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f2215  51                   push ecx
// 004f2216  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f221a  52                   push edx
// 004f221b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f221f  50                   push eax
// 004f2220  51                   push ecx
// 004f2221  52                   push edx
// 004f2222  e8e9e3ffff           call 0x4f0610
// 004f2227  83c41c               add esp, 0x1c
// 004f222a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
