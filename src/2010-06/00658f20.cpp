// from server: 100% by auto
// roc 2010-06 00658f20  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658f20
//
// 00658f20  51                   push ecx
// 00658f21  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00658f25  8b542410             mov edx, dword ptr [esp + 0x10]
// 00658f29  c6042400             mov byte ptr [esp], 0
// 00658f2d  8b0424               mov eax, dword ptr [esp]
// 00658f30  50                   push eax
// 00658f31  8b442414             mov eax, dword ptr [esp + 0x14]
// 00658f35  51                   push ecx
// 00658f36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00658f3a  52                   push edx
// 00658f3b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00658f3f  50                   push eax
// 00658f40  51                   push ecx
// 00658f41  52                   push edx
// 00658f42  e849f6ffff           call 0x658590
// 00658f47  83c41c               add esp, 0x1c
// 00658f4a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
