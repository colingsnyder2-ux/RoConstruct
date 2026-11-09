// from server: 100% by auto
// roc 2007-08 0046aa60  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046aa60
//
// 0046aa60  51                   push ecx
// 0046aa61  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046aa65  c6042400             mov byte ptr [esp], 0
// 0046aa69  8b0424               mov eax, dword ptr [esp]
// 0046aa6c  50                   push eax
// 0046aa6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046aa71  52                   push edx
// 0046aa72  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046aa76  51                   push ecx
// 0046aa77  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046aa7b  50                   push eax
// 0046aa7c  51                   push ecx
// 0046aa7d  52                   push edx
// 0046aa7e  e8edfcffff           call 0x46a770
// 0046aa83  83c41c               add esp, 0x1c
// 0046aa86  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
