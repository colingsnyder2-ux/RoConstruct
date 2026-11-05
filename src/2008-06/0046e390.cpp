// from server: 100% by auto
// roc 2008-06 0046e390  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e390
//
// 0046e390  51                   push ecx
// 0046e391  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046e395  c6042400             mov byte ptr [esp], 0
// 0046e399  8b0424               mov eax, dword ptr [esp]
// 0046e39c  50                   push eax
// 0046e39d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046e3a1  52                   push edx
// 0046e3a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046e3a6  83c108               add ecx, 8
// 0046e3a9  51                   push ecx
// 0046e3aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046e3ae  50                   push eax
// 0046e3af  51                   push ecx
// 0046e3b0  52                   push edx
// 0046e3b1  e8eafcffff           call 0x46e0a0
// 0046e3b6  83c41c               add esp, 0x1c
// 0046e3b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
