// from server: 100% by auto
// roc 2009-12 005b15f0  unit: RBX::BrickBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b15f0
//
// 005b15f0  51                   push ecx
// 005b15f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b15f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b15f9  c6042400             mov byte ptr [esp], 0
// 005b15fd  8b0424               mov eax, dword ptr [esp]
// 005b1600  50                   push eax
// 005b1601  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b1605  51                   push ecx
// 005b1606  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005b160a  52                   push edx
// 005b160b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b160f  50                   push eax
// 005b1610  51                   push ecx
// 005b1611  52                   push edx
// 005b1612  e819feffff           call 0x5b1430
// 005b1617  83c41c               add esp, 0x1c
// 005b161a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
