// from server: 100% by auto
// roc 2011-06 0068a760  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0068a760
//
// 0068a760  51                   push ecx
// 0068a761  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068a765  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068a769  c6042400             mov byte ptr [esp], 0
// 0068a76d  8b0424               mov eax, dword ptr [esp]
// 0068a770  50                   push eax
// 0068a771  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068a775  51                   push ecx
// 0068a776  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068a77a  52                   push edx
// 0068a77b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068a77f  50                   push eax
// 0068a780  51                   push ecx
// 0068a781  52                   push edx
// 0068a782  e839f9ffff           call 0x68a0c0
// 0068a787  83c41c               add esp, 0x1c
// 0068a78a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
