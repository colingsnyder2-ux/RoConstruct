// from server: 100% by auto
// roc 2010-06 006ab3f0  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ab3f0
//
// 006ab3f0  51                   push ecx
// 006ab3f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ab3f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ab3f9  c6042400             mov byte ptr [esp], 0
// 006ab3fd  8b0424               mov eax, dword ptr [esp]
// 006ab400  50                   push eax
// 006ab401  8b442414             mov eax, dword ptr [esp + 0x14]
// 006ab405  51                   push ecx
// 006ab406  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006ab40a  52                   push edx
// 006ab40b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ab40f  50                   push eax
// 006ab410  51                   push ecx
// 006ab411  52                   push edx
// 006ab412  e829faffff           call 0x6aae40
// 006ab417  83c41c               add esp, 0x1c
// 006ab41a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
