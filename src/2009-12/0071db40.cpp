// from server: 100% by auto
// roc 2009-12 0071db40  unit: RBX::VInstance::?$NonFactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0071db40
//
// 0071db40  51                   push ecx
// 0071db41  8b542410             mov edx, dword ptr [esp + 0x10]
// 0071db45  c6042400             mov byte ptr [esp], 0
// 0071db49  8b0424               mov eax, dword ptr [esp]
// 0071db4c  50                   push eax
// 0071db4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0071db51  52                   push edx
// 0071db52  8b542410             mov edx, dword ptr [esp + 0x10]
// 0071db56  83c108               add ecx, 8
// 0071db59  51                   push ecx
// 0071db5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0071db5e  50                   push eax
// 0071db5f  51                   push ecx
// 0071db60  52                   push edx
// 0071db61  e82a69d2ff           call 0x444490
// 0071db66  83c41c               add esp, 0x1c
// 0071db69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
