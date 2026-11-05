// from server: 100% by auto
// roc 2010-06 0096f8d0  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f8d0
//
// 0096f8d0  51                   push ecx
// 0096f8d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096f8d5  c6042400             mov byte ptr [esp], 0
// 0096f8d9  8b0424               mov eax, dword ptr [esp]
// 0096f8dc  50                   push eax
// 0096f8dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0096f8e1  52                   push edx
// 0096f8e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096f8e6  83c108               add ecx, 8
// 0096f8e9  51                   push ecx
// 0096f8ea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0096f8ee  50                   push eax
// 0096f8ef  51                   push ecx
// 0096f8f0  52                   push edx
// 0096f8f1  e85afdf6ff           call 0x8df650
// 0096f8f6  83c41c               add esp, 0x1c
// 0096f8f9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
