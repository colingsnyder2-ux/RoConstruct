// from server: 100% by auto
// roc 2009-06 00426690  unit: boost::any::H::?$holder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00426690
//
// 00426690  51                   push ecx
// 00426691  8b542410             mov edx, dword ptr [esp + 0x10]
// 00426695  c6042400             mov byte ptr [esp], 0
// 00426699  8b0424               mov eax, dword ptr [esp]
// 0042669c  50                   push eax
// 0042669d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004266a1  52                   push edx
// 004266a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004266a6  83c108               add ecx, 8
// 004266a9  51                   push ecx
// 004266aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004266ae  50                   push eax
// 004266af  51                   push ecx
// 004266b0  52                   push edx
// 004266b1  e8aa331a00           call 0x5c9a60
// 004266b6  83c41c               add esp, 0x1c
// 004266b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
