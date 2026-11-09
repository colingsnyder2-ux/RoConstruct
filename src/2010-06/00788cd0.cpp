// from server: 100% by auto
// roc 2010-06 00788cd0  unit: RBX::HUMAN::GettingUp  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788cd0
//
// 00788cd0  51                   push ecx
// 00788cd1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788cd5  c6042400             mov byte ptr [esp], 0
// 00788cd9  8b0424               mov eax, dword ptr [esp]
// 00788cdc  50                   push eax
// 00788cdd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788ce1  52                   push edx
// 00788ce2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788ce6  83c108               add ecx, 8
// 00788ce9  51                   push ecx
// 00788cea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00788cee  50                   push eax
// 00788cef  51                   push ecx
// 00788cf0  52                   push edx
// 00788cf1  e8caf3ffff           call 0x7880c0
// 00788cf6  83c41c               add esp, 0x1c
// 00788cf9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
