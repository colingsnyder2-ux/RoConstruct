// from server: 100% by auto
// roc 2009-12 0072c930  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072c930
//
// 0072c930  51                   push ecx
// 0072c931  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072c935  c6042400             mov byte ptr [esp], 0
// 0072c939  8b0424               mov eax, dword ptr [esp]
// 0072c93c  50                   push eax
// 0072c93d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072c941  52                   push edx
// 0072c942  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072c946  83c108               add ecx, 8
// 0072c949  51                   push ecx
// 0072c94a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0072c94e  50                   push eax
// 0072c94f  51                   push ecx
// 0072c950  52                   push edx
// 0072c951  e89af8ffff           call 0x72c1f0
// 0072c956  83c41c               add esp, 0x1c
// 0072c959  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
