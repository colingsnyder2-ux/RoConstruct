// from server: 100% by auto
// roc 2011-06 00689ba0  unit: RBX::Network::P8Player::?$GetSetImpl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00689ba0
//
// 00689ba0  51                   push ecx
// 00689ba1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00689ba5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00689ba9  c6042400             mov byte ptr [esp], 0
// 00689bad  8b0424               mov eax, dword ptr [esp]
// 00689bb0  50                   push eax
// 00689bb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00689bb5  51                   push ecx
// 00689bb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00689bba  52                   push edx
// 00689bbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00689bbf  50                   push eax
// 00689bc0  51                   push ecx
// 00689bc1  52                   push edx
// 00689bc2  e839ca2c00           call 0x956600
// 00689bc7  83c41c               add esp, 0x1c
// 00689bca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
