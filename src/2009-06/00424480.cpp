// from server: 100% by auto
// roc 2009-06 00424480  unit: MainLogManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424480
//
// 00424480  51                   push ecx
// 00424481  8b542410             mov edx, dword ptr [esp + 0x10]
// 00424485  c6042400             mov byte ptr [esp], 0
// 00424489  8b0424               mov eax, dword ptr [esp]
// 0042448c  50                   push eax
// 0042448d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00424491  52                   push edx
// 00424492  8b542410             mov edx, dword ptr [esp + 0x10]
// 00424496  83c108               add ecx, 8
// 00424499  51                   push ecx
// 0042449a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042449e  50                   push eax
// 0042449f  51                   push ecx
// 004244a0  52                   push edx
// 004244a1  e8faf6ffff           call 0x423ba0
// 004244a6  83c41c               add esp, 0x1c
// 004244a9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
