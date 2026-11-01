// from server: 100% by auto
// roc 2009-12 005b0a10  unit: seg_005b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0a10
//
// 005b0a10  51                   push ecx
// 005b0a11  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b0a15  c6042400             mov byte ptr [esp], 0
// 005b0a19  8b0424               mov eax, dword ptr [esp]
// 005b0a1c  50                   push eax
// 005b0a1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b0a21  52                   push edx
// 005b0a22  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b0a26  83c108               add ecx, 8
// 005b0a29  51                   push ecx
// 005b0a2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005b0a2e  50                   push eax
// 005b0a2f  51                   push ecx
// 005b0a30  52                   push edx
// 005b0a31  e85acfffff           call 0x5ad990
// 005b0a36  83c41c               add esp, 0x1c
// 005b0a39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
