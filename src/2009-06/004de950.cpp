// from server: 100% by auto
// roc 2009-06 004de950  unit: RBX::Network::IdSerializer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de950
//
// 004de950  51                   push ecx
// 004de951  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004de955  8b542410             mov edx, dword ptr [esp + 0x10]
// 004de959  c6042400             mov byte ptr [esp], 0
// 004de95d  8b0424               mov eax, dword ptr [esp]
// 004de960  50                   push eax
// 004de961  8b442414             mov eax, dword ptr [esp + 0x14]
// 004de965  51                   push ecx
// 004de966  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004de96a  52                   push edx
// 004de96b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004de96f  50                   push eax
// 004de970  51                   push ecx
// 004de971  52                   push edx
// 004de972  e8a9f9ffff           call 0x4de320
// 004de977  83c41c               add esp, 0x1c
// 004de97a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
