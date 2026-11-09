// from server: 100% by auto
// roc 2007-08 004aca60  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aca60
//
// 004aca60  51                   push ecx
// 004aca61  8b542410             mov edx, dword ptr [esp + 0x10]
// 004aca65  c6042400             mov byte ptr [esp], 0
// 004aca69  8b0424               mov eax, dword ptr [esp]
// 004aca6c  50                   push eax
// 004aca6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004aca71  52                   push edx
// 004aca72  8b542410             mov edx, dword ptr [esp + 0x10]
// 004aca76  51                   push ecx
// 004aca77  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aca7b  50                   push eax
// 004aca7c  51                   push ecx
// 004aca7d  52                   push edx
// 004aca7e  e8bdbaffff           call 0x4a8540
// 004aca83  83c41c               add esp, 0x1c
// 004aca86  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
