// from server: 100% by auto
// roc 2012-06 00863fe0  unit: VWiniInetRequest_source::?$stream_buffer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00863fe0
//
// 00863fe0  51                   push ecx
// 00863fe1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00863fe5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00863fe9  c6042400             mov byte ptr [esp], 0
// 00863fed  8b0424               mov eax, dword ptr [esp]
// 00863ff0  50                   push eax
// 00863ff1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00863ff5  51                   push ecx
// 00863ff6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00863ffa  52                   push edx
// 00863ffb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00863fff  50                   push eax
// 00864000  51                   push ecx
// 00864001  52                   push edx
// 00864002  e809f9ffff           call 0x863910
// 00864007  83c41c               add esp, 0x1c
// 0086400a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
