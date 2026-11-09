// from server: 100% by auto
// roc 2009-06 006c2100  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2100
//
// 006c2100  51                   push ecx
// 006c2101  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c2105  c6042400             mov byte ptr [esp], 0
// 006c2109  8b0424               mov eax, dword ptr [esp]
// 006c210c  50                   push eax
// 006c210d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c2111  52                   push edx
// 006c2112  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c2116  83c108               add ecx, 8
// 006c2119  51                   push ecx
// 006c211a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c211e  50                   push eax
// 006c211f  51                   push ecx
// 006c2120  52                   push edx
// 006c2121  e84afdffff           call 0x6c1e70
// 006c2126  83c41c               add esp, 0x1c
// 006c2129  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
