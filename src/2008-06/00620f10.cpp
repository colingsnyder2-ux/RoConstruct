// from server: 100% by auto
// roc 2008-06 00620f10  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620f10
//
// 00620f10  51                   push ecx
// 00620f11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00620f15  c6042400             mov byte ptr [esp], 0
// 00620f19  8b0424               mov eax, dword ptr [esp]
// 00620f1c  50                   push eax
// 00620f1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00620f21  52                   push edx
// 00620f22  8b542410             mov edx, dword ptr [esp + 0x10]
// 00620f26  83c108               add ecx, 8
// 00620f29  51                   push ecx
// 00620f2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00620f2e  50                   push eax
// 00620f2f  51                   push ecx
// 00620f30  52                   push edx
// 00620f31  e84afdffff           call 0x620c80
// 00620f36  83c41c               add esp, 0x1c
// 00620f39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
