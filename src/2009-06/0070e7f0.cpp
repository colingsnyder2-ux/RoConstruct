// from server: 100% by auto
// roc 2009-06 0070e7f0  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070e7f0
//
// 0070e7f0  51                   push ecx
// 0070e7f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0070e7f5  c6042400             mov byte ptr [esp], 0
// 0070e7f9  8b0424               mov eax, dword ptr [esp]
// 0070e7fc  50                   push eax
// 0070e7fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0070e801  52                   push edx
// 0070e802  8b542410             mov edx, dword ptr [esp + 0x10]
// 0070e806  83c108               add ecx, 8
// 0070e809  51                   push ecx
// 0070e80a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070e80e  50                   push eax
// 0070e80f  51                   push ecx
// 0070e810  52                   push edx
// 0070e811  e8ea3fd2ff           call 0x432800
// 0070e816  83c41c               add esp, 0x1c
// 0070e819  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
