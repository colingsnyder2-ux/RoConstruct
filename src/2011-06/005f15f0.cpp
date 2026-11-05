// from server: 100% by auto
// roc 2011-06 005f15f0  unit: $$A6A_NXZ$0A::?$CallbackDescImpl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005f15f0
//
// 005f15f0  51                   push ecx
// 005f15f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f15f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f15f9  c6042400             mov byte ptr [esp], 0
// 005f15fd  8b0424               mov eax, dword ptr [esp]
// 005f1600  50                   push eax
// 005f1601  8b442414             mov eax, dword ptr [esp + 0x14]
// 005f1605  51                   push ecx
// 005f1606  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005f160a  52                   push edx
// 005f160b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005f160f  50                   push eax
// 005f1610  51                   push ecx
// 005f1611  52                   push edx
// 005f1612  e8f9dfffff           call 0x5ef610
// 005f1617  83c41c               add esp, 0x1c
// 005f161a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
