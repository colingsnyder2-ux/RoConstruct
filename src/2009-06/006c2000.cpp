// from server: 100% by auto
// roc 2009-06 006c2000  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2000
//
// 006c2000  51                   push ecx
// 006c2001  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c2005  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c2009  c6042400             mov byte ptr [esp], 0
// 006c200d  8b0424               mov eax, dword ptr [esp]
// 006c2010  50                   push eax
// 006c2011  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c2015  51                   push ecx
// 006c2016  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006c201a  52                   push edx
// 006c201b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c201f  50                   push eax
// 006c2020  51                   push ecx
// 006c2021  52                   push edx
// 006c2022  e8e9fdffff           call 0x6c1e10
// 006c2027  83c41c               add esp, 0x1c
// 006c202a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
