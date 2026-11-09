// from server: 100% by auto
// roc 2011-06 004f8e50  unit: RBX::Network::Replicator::SendDataJob  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f8e50
//
// 004f8e50  51                   push ecx
// 004f8e51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004f8e55  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f8e59  c6042400             mov byte ptr [esp], 0
// 004f8e5d  8b0424               mov eax, dword ptr [esp]
// 004f8e60  50                   push eax
// 004f8e61  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f8e65  51                   push ecx
// 004f8e66  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f8e6a  52                   push edx
// 004f8e6b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004f8e6f  50                   push eax
// 004f8e70  51                   push ecx
// 004f8e71  52                   push edx
// 004f8e72  e839d0ffff           call 0x4f5eb0
// 004f8e77  83c41c               add esp, 0x1c
// 004f8e7a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
