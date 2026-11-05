// from server: 100% by auto
// roc 2009-06 00532730  unit: RBX::BeveledBlockBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532730
//
// 00532730  51                   push ecx
// 00532731  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00532735  8b542410             mov edx, dword ptr [esp + 0x10]
// 00532739  c6042400             mov byte ptr [esp], 0
// 0053273d  8b0424               mov eax, dword ptr [esp]
// 00532740  50                   push eax
// 00532741  8b442414             mov eax, dword ptr [esp + 0x14]
// 00532745  51                   push ecx
// 00532746  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0053274a  52                   push edx
// 0053274b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053274f  50                   push eax
// 00532750  51                   push ecx
// 00532751  52                   push edx
// 00532752  e879feffff           call 0x5325d0
// 00532757  83c41c               add esp, 0x1c
// 0053275a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
