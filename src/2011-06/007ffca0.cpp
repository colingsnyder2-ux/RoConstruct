// from server: 100% by auto
// roc 2011-06 007ffca0  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::delete_data  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007ffca0
//
// 007ffca0  51                   push ecx
// 007ffca1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ffca5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ffca9  c6042400             mov byte ptr [esp], 0
// 007ffcad  8b0424               mov eax, dword ptr [esp]
// 007ffcb0  50                   push eax
// 007ffcb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ffcb5  51                   push ecx
// 007ffcb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ffcba  52                   push edx
// 007ffcbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007ffcbf  50                   push eax
// 007ffcc0  51                   push ecx
// 007ffcc1  52                   push edx
// 007ffcc2  e859fbffff           call 0x7ff820
// 007ffcc7  83c41c               add esp, 0x1c
// 007ffcca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
