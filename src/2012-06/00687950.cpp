// from server: 100% by auto
// roc 2012-06 00687950  unit: RBX::VCamera::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00687950
//
// 00687950  51                   push ecx
// 00687951  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00687955  8b542410             mov edx, dword ptr [esp + 0x10]
// 00687959  c6042400             mov byte ptr [esp], 0
// 0068795d  8b0424               mov eax, dword ptr [esp]
// 00687960  50                   push eax
// 00687961  8b442414             mov eax, dword ptr [esp + 0x14]
// 00687965  51                   push ecx
// 00687966  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068796a  52                   push edx
// 0068796b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068796f  50                   push eax
// 00687970  51                   push ecx
// 00687971  52                   push edx
// 00687972  e8e9f3ffff           call 0x686d60
// 00687977  83c41c               add esp, 0x1c
// 0068797a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
