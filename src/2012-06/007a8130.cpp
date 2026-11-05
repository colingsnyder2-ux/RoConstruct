// from server: 100% by auto
// roc 2012-06 007a8130  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a8130
//
// 007a8130  51                   push ecx
// 007a8131  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a8135  8b542410             mov edx, dword ptr [esp + 0x10]
// 007a8139  c6042400             mov byte ptr [esp], 0
// 007a813d  8b0424               mov eax, dword ptr [esp]
// 007a8140  50                   push eax
// 007a8141  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a8145  51                   push ecx
// 007a8146  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a814a  52                   push edx
// 007a814b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a814f  50                   push eax
// 007a8150  51                   push ecx
// 007a8151  52                   push edx
// 007a8152  e869f8ffff           call 0x7a79c0
// 007a8157  83c41c               add esp, 0x1c
// 007a815a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
