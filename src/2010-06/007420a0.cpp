// from server: 100% by auto
// roc 2010-06 007420a0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007420a0
//
// 007420a0  51                   push ecx
// 007420a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007420a5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007420a9  c6042400             mov byte ptr [esp], 0
// 007420ad  8b0424               mov eax, dword ptr [esp]
// 007420b0  50                   push eax
// 007420b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007420b5  51                   push ecx
// 007420b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007420ba  52                   push edx
// 007420bb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007420bf  50                   push eax
// 007420c0  51                   push ecx
// 007420c1  52                   push edx
// 007420c2  e889f8ffff           call 0x741950
// 007420c7  83c41c               add esp, 0x1c
// 007420ca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
