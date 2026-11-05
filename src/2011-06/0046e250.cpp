// from server: 100% by auto
// roc 2011-06 0046e250  unit: CRobloxControlMaterialSelector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046e250
//
// 0046e250  51                   push ecx
// 0046e251  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046e255  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046e259  c6042400             mov byte ptr [esp], 0
// 0046e25d  8b0424               mov eax, dword ptr [esp]
// 0046e260  50                   push eax
// 0046e261  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046e265  51                   push ecx
// 0046e266  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046e26a  52                   push edx
// 0046e26b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046e26f  50                   push eax
// 0046e270  51                   push ecx
// 0046e271  52                   push edx
// 0046e272  e889f8ffff           call 0x46db00
// 0046e277  83c41c               add esp, 0x1c
// 0046e27a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
