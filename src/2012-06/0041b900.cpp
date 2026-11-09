// from server: 100% by auto
// roc 2012-06 0041b900  unit: RBX::JavaScript::VMarshalledFunction::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041b900
//
// 0041b900  51                   push ecx
// 0041b901  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041b905  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b909  c6042400             mov byte ptr [esp], 0
// 0041b90d  8b0424               mov eax, dword ptr [esp]
// 0041b910  50                   push eax
// 0041b911  8b442414             mov eax, dword ptr [esp + 0x14]
// 0041b915  51                   push ecx
// 0041b916  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041b91a  52                   push edx
// 0041b91b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041b91f  50                   push eax
// 0041b920  51                   push ecx
// 0041b921  52                   push edx
// 0041b922  e819fcffff           call 0x41b540
// 0041b927  83c41c               add esp, 0x1c
// 0041b92a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
