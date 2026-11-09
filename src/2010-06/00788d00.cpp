// from server: 100% by auto
// roc 2010-06 00788d00  unit: RBX::HUMAN::GettingUp  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788d00
//
// 00788d00  51                   push ecx
// 00788d01  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788d05  c6042400             mov byte ptr [esp], 0
// 00788d09  8b0424               mov eax, dword ptr [esp]
// 00788d0c  50                   push eax
// 00788d0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788d11  52                   push edx
// 00788d12  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788d16  83c108               add ecx, 8
// 00788d19  51                   push ecx
// 00788d1a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00788d1e  50                   push eax
// 00788d1f  51                   push ecx
// 00788d20  52                   push edx
// 00788d21  e84af4ffff           call 0x788170
// 00788d26  83c41c               add esp, 0x1c
// 00788d29  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
