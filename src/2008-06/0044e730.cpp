// from server: 100% by auto
// roc 2008-06 0044e730  unit: CRobloxControlColorSelector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e730
//
// 0044e730  51                   push ecx
// 0044e731  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044e735  c6042400             mov byte ptr [esp], 0
// 0044e739  8b0424               mov eax, dword ptr [esp]
// 0044e73c  50                   push eax
// 0044e73d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044e741  52                   push edx
// 0044e742  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044e746  83c108               add ecx, 8
// 0044e749  51                   push ecx
// 0044e74a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044e74e  50                   push eax
// 0044e74f  51                   push ecx
// 0044e750  52                   push edx
// 0044e751  e8aafdffff           call 0x44e500
// 0044e756  83c41c               add esp, 0x1c
// 0044e759  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
