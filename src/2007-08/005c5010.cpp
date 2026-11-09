// from server: 100% by auto
// roc 2007-08 005c5010  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5010
//
// 005c5010  51                   push ecx
// 005c5011  8b542410             mov edx, dword ptr [esp + 0x10]
// 005c5015  c6042400             mov byte ptr [esp], 0
// 005c5019  8b0424               mov eax, dword ptr [esp]
// 005c501c  50                   push eax
// 005c501d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c5021  52                   push edx
// 005c5022  8b542410             mov edx, dword ptr [esp + 0x10]
// 005c5026  51                   push ecx
// 005c5027  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005c502b  50                   push eax
// 005c502c  51                   push ecx
// 005c502d  52                   push edx
// 005c502e  e86dfdffff           call 0x5c4da0
// 005c5033  83c41c               add esp, 0x1c
// 005c5036  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
