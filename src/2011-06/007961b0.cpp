// from server: 100% by auto
// roc 2011-06 007961b0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007961b0
//
// 007961b0  51                   push ecx
// 007961b1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007961b5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007961b9  c6042400             mov byte ptr [esp], 0
// 007961bd  8b0424               mov eax, dword ptr [esp]
// 007961c0  50                   push eax
// 007961c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007961c5  51                   push ecx
// 007961c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007961ca  52                   push edx
// 007961cb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007961cf  50                   push eax
// 007961d0  51                   push ecx
// 007961d1  52                   push edx
// 007961d2  e8a9f6ffff           call 0x795880
// 007961d7  83c41c               add esp, 0x1c
// 007961da  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
