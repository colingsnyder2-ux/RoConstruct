// from server: 100% by auto
// roc 2009-12 0072c0b0  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072c0b0
//
// 0072c0b0  51                   push ecx
// 0072c0b1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0072c0b5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072c0b9  c6042400             mov byte ptr [esp], 0
// 0072c0bd  8b0424               mov eax, dword ptr [esp]
// 0072c0c0  50                   push eax
// 0072c0c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072c0c5  51                   push ecx
// 0072c0c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0072c0ca  52                   push edx
// 0072c0cb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0072c0cf  50                   push eax
// 0072c0d0  51                   push ecx
// 0072c0d1  52                   push edx
// 0072c0d2  e819fdffff           call 0x72bdf0
// 0072c0d7  83c41c               add esp, 0x1c
// 0072c0da  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
