// from server: 100% by auto
// roc 2010-06 004821c0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004821c0
//
// 004821c0  51                   push ecx
// 004821c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004821c5  c6042400             mov byte ptr [esp], 0
// 004821c9  8b0424               mov eax, dword ptr [esp]
// 004821cc  50                   push eax
// 004821cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004821d1  52                   push edx
// 004821d2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004821d6  83c108               add ecx, 8
// 004821d9  51                   push ecx
// 004821da  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004821de  50                   push eax
// 004821df  51                   push ecx
// 004821e0  52                   push edx
// 004821e1  e8eafcffff           call 0x481ed0
// 004821e6  83c41c               add esp, 0x1c
// 004821e9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
