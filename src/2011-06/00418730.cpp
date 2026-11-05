// from server: 100% by auto
// roc 2011-06 00418730  unit: RBX::Reflection::VValue::$$CBV?$vector::$$A6AXV?$shared_ptr::V?$function::V?$shared_ptr::?$holder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00418730
//
// 00418730  51                   push ecx
// 00418731  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00418735  8b542410             mov edx, dword ptr [esp + 0x10]
// 00418739  c6042400             mov byte ptr [esp], 0
// 0041873d  8b0424               mov eax, dword ptr [esp]
// 00418740  50                   push eax
// 00418741  8b442414             mov eax, dword ptr [esp + 0x14]
// 00418745  51                   push ecx
// 00418746  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041874a  52                   push edx
// 0041874b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041874f  50                   push eax
// 00418750  51                   push ecx
// 00418751  52                   push edx
// 00418752  e8e9f9ffff           call 0x418140
// 00418757  83c41c               add esp, 0x1c
// 0041875a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
