// from server: 100% by auto
// roc 2007-08 004292a0  unit: ThreadLogManager  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004292a0
//
// 004292a0  51                   push ecx
// 004292a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004292a5  c6042400             mov byte ptr [esp], 0
// 004292a9  8b0424               mov eax, dword ptr [esp]
// 004292ac  50                   push eax
// 004292ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 004292b1  52                   push edx
// 004292b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004292b6  51                   push ecx
// 004292b7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004292bb  50                   push eax
// 004292bc  51                   push ecx
// 004292bd  52                   push edx
// 004292be  e88df6ffff           call 0x428950
// 004292c3  83c41c               add esp, 0x1c
// 004292c6  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
