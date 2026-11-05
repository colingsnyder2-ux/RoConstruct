// from server: 100% by auto
// roc 2007-08 0044c460  unit: CRobloxControlColorSelector  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c460
//
// 0044c460  51                   push ecx
// 0044c461  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c465  c6042400             mov byte ptr [esp], 0
// 0044c469  8b0424               mov eax, dword ptr [esp]
// 0044c46c  50                   push eax
// 0044c46d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044c471  52                   push edx
// 0044c472  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c476  51                   push ecx
// 0044c477  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044c47b  50                   push eax
// 0044c47c  51                   push ecx
// 0044c47d  52                   push edx
// 0044c47e  e88dfdffff           call 0x44c210
// 0044c483  83c41c               add esp, 0x1c
// 0044c486  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
