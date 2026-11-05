// from server: 100% by auto
// roc 2007-08 005393d0  unit: RBX::VScriptContext::?$FactoryProduct  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005393d0
//
// 005393d0  51                   push ecx
// 005393d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005393d5  c6042400             mov byte ptr [esp], 0
// 005393d9  8b0424               mov eax, dword ptr [esp]
// 005393dc  50                   push eax
// 005393dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 005393e1  52                   push edx
// 005393e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 005393e6  51                   push ecx
// 005393e7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005393eb  50                   push eax
// 005393ec  51                   push ecx
// 005393ed  52                   push edx
// 005393ee  e80d47edff           call 0x40db00
// 005393f3  83c41c               add esp, 0x1c
// 005393f6  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
