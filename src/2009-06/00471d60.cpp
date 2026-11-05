// from server: 100% by auto
// roc 2009-06 00471d60  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00471d60
//
// 00471d60  51                   push ecx
// 00471d61  8b542410             mov edx, dword ptr [esp + 0x10]
// 00471d65  c6042400             mov byte ptr [esp], 0
// 00471d69  8b0424               mov eax, dword ptr [esp]
// 00471d6c  50                   push eax
// 00471d6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00471d71  52                   push edx
// 00471d72  8b542410             mov edx, dword ptr [esp + 0x10]
// 00471d76  83c108               add ecx, 8
// 00471d79  51                   push ecx
// 00471d7a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00471d7e  50                   push eax
// 00471d7f  51                   push ecx
// 00471d80  52                   push edx
// 00471d81  e8eafcffff           call 0x471a70
// 00471d86  83c41c               add esp, 0x1c
// 00471d89  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
