// from server: 100% by auto
// roc 2012-06 006aaaa0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006aaaa0
//
// 006aaaa0  51                   push ecx
// 006aaaa1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006aaaa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006aaaa9  c6042400             mov byte ptr [esp], 0
// 006aaaad  8b0424               mov eax, dword ptr [esp]
// 006aaab0  50                   push eax
// 006aaab1  8b442414             mov eax, dword ptr [esp + 0x14]
// 006aaab5  51                   push ecx
// 006aaab6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006aaaba  52                   push edx
// 006aaabb  8b542414             mov edx, dword ptr [esp + 0x14]
// 006aaabf  50                   push eax
// 006aaac0  51                   push ecx
// 006aaac1  52                   push edx
// 006aaac2  e839e4ffff           call 0x6a8f00
// 006aaac7  83c41c               add esp, 0x1c
// 006aaaca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
