// from server: 100% by auto
// roc 2012-06 006a9900  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a9900
//
// 006a9900  51                   push ecx
// 006a9901  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a9905  8b542410             mov edx, dword ptr [esp + 0x10]
// 006a9909  c6042400             mov byte ptr [esp], 0
// 006a990d  8b0424               mov eax, dword ptr [esp]
// 006a9910  50                   push eax
// 006a9911  8b442414             mov eax, dword ptr [esp + 0x14]
// 006a9915  51                   push ecx
// 006a9916  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006a991a  52                   push edx
// 006a991b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006a991f  50                   push eax
// 006a9920  51                   push ecx
// 006a9921  52                   push edx
// 006a9922  e859eeffff           call 0x6a8780
// 006a9927  83c41c               add esp, 0x1c
// 006a992a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
