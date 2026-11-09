// from server: 100% by auto
// roc 2012-06 0056ddd0  unit: RBX::Network::IdSerializer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056ddd0
//
// 0056ddd0  51                   push ecx
// 0056ddd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056ddd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056ddd9  c6042400             mov byte ptr [esp], 0
// 0056dddd  8b0424               mov eax, dword ptr [esp]
// 0056dde0  50                   push eax
// 0056dde1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056dde5  51                   push ecx
// 0056dde6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056ddea  52                   push edx
// 0056ddeb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056ddef  50                   push eax
// 0056ddf0  51                   push ecx
// 0056ddf1  52                   push edx
// 0056ddf2  e849e3ffff           call 0x56c140
// 0056ddf7  83c41c               add esp, 0x1c
// 0056ddfa  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
