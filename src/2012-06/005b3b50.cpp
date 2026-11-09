// from server: 100% by auto
// roc 2012-06 005b3b50  unit: RBX::Network::ErrorCompPhysicsSender2  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b3b50
//
// 005b3b50  51                   push ecx
// 005b3b51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3b55  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b3b59  c6042400             mov byte ptr [esp], 0
// 005b3b5d  8b0424               mov eax, dword ptr [esp]
// 005b3b60  50                   push eax
// 005b3b61  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b3b65  51                   push ecx
// 005b3b66  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005b3b6a  52                   push edx
// 005b3b6b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b3b6f  50                   push eax
// 005b3b70  51                   push ecx
// 005b3b71  52                   push edx
// 005b3b72  e889f8ffff           call 0x5b3400
// 005b3b77  83c41c               add esp, 0x1c
// 005b3b7a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
