// from server: 100% by auto
// roc 2008-06 00620e10  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620e10
//
// 00620e10  51                   push ecx
// 00620e11  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00620e15  8b542410             mov edx, dword ptr [esp + 0x10]
// 00620e19  c6042400             mov byte ptr [esp], 0
// 00620e1d  8b0424               mov eax, dword ptr [esp]
// 00620e20  50                   push eax
// 00620e21  8b442414             mov eax, dword ptr [esp + 0x14]
// 00620e25  51                   push ecx
// 00620e26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00620e2a  52                   push edx
// 00620e2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00620e2f  50                   push eax
// 00620e30  51                   push ecx
// 00620e31  52                   push edx
// 00620e32  e8e9fdffff           call 0x620c20
// 00620e37  83c41c               add esp, 0x1c
// 00620e3a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
