// from server: 100% by auto
// roc 2009-12 0047be20  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047be20
//
// 0047be20  51                   push ecx
// 0047be21  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047be25  c6042400             mov byte ptr [esp], 0
// 0047be29  8b0424               mov eax, dword ptr [esp]
// 0047be2c  50                   push eax
// 0047be2d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0047be31  52                   push edx
// 0047be32  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047be36  83c108               add ecx, 8
// 0047be39  51                   push ecx
// 0047be3a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047be3e  50                   push eax
// 0047be3f  51                   push ecx
// 0047be40  52                   push edx
// 0047be41  e8eafcffff           call 0x47bb30
// 0047be46  83c41c               add esp, 0x1c
// 0047be49  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
