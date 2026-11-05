// from server: 100% by auto
// roc 2007-08 005db130  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005db130
//
// 005db130  51                   push ecx
// 005db131  8b542410             mov edx, dword ptr [esp + 0x10]
// 005db135  c6042400             mov byte ptr [esp], 0
// 005db139  8b0424               mov eax, dword ptr [esp]
// 005db13c  50                   push eax
// 005db13d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005db141  52                   push edx
// 005db142  8b542410             mov edx, dword ptr [esp + 0x10]
// 005db146  51                   push ecx
// 005db147  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005db14b  50                   push eax
// 005db14c  51                   push ecx
// 005db14d  52                   push edx
// 005db14e  e82d96f9ff           call 0x574780
// 005db153  83c41c               add esp, 0x1c
// 005db156  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
