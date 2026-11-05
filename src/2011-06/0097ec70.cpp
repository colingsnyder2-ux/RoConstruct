// from server: 100% by auto
// roc 2011-06 0097ec70  unit: RBX::BeveledBlockBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097ec70
//
// 0097ec70  51                   push ecx
// 0097ec71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0097ec75  8b542410             mov edx, dword ptr [esp + 0x10]
// 0097ec79  c6042400             mov byte ptr [esp], 0
// 0097ec7d  8b0424               mov eax, dword ptr [esp]
// 0097ec80  50                   push eax
// 0097ec81  8b442414             mov eax, dword ptr [esp + 0x14]
// 0097ec85  51                   push ecx
// 0097ec86  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0097ec8a  52                   push edx
// 0097ec8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0097ec8f  50                   push eax
// 0097ec90  51                   push ecx
// 0097ec91  52                   push edx
// 0097ec92  e859e2ffff           call 0x97cef0
// 0097ec97  83c41c               add esp, 0x1c
// 0097ec9a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
