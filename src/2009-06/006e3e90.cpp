// from server: 100% by auto
// roc 2009-06 006e3e90  unit: RBX::ScoreHud  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3e90
//
// 006e3e90  51                   push ecx
// 006e3e91  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e3e95  c6042400             mov byte ptr [esp], 0
// 006e3e99  8b0424               mov eax, dword ptr [esp]
// 006e3e9c  50                   push eax
// 006e3e9d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006e3ea1  52                   push edx
// 006e3ea2  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e3ea6  83c108               add ecx, 8
// 006e3ea9  51                   push ecx
// 006e3eaa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006e3eae  50                   push eax
// 006e3eaf  51                   push ecx
// 006e3eb0  52                   push edx
// 006e3eb1  e85af0ffff           call 0x6e2f10
// 006e3eb6  83c41c               add esp, 0x1c
// 006e3eb9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
