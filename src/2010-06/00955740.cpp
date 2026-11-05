// from server: 100% by auto
// roc 2010-06 00955740  unit: seg_00950000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955740
//
// 00955740  51                   push ecx
// 00955741  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00955745  8b542410             mov edx, dword ptr [esp + 0x10]
// 00955749  c6042400             mov byte ptr [esp], 0
// 0095574d  8b0424               mov eax, dword ptr [esp]
// 00955750  50                   push eax
// 00955751  8b442414             mov eax, dword ptr [esp + 0x14]
// 00955755  51                   push ecx
// 00955756  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0095575a  52                   push edx
// 0095575b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0095575f  50                   push eax
// 00955760  51                   push ecx
// 00955761  52                   push edx
// 00955762  e849d2ffff           call 0x9529b0
// 00955767  83c41c               add esp, 0x1c
// 0095576a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
