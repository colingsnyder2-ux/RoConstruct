// from server: 100% by auto
// roc 2010-06 006abe80  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006abe80
//
// 006abe80  51                   push ecx
// 006abe81  8b542410             mov edx, dword ptr [esp + 0x10]
// 006abe85  c6042400             mov byte ptr [esp], 0
// 006abe89  8b0424               mov eax, dword ptr [esp]
// 006abe8c  50                   push eax
// 006abe8d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006abe91  52                   push edx
// 006abe92  8b542410             mov edx, dword ptr [esp + 0x10]
// 006abe96  83c108               add ecx, 8
// 006abe99  51                   push ecx
// 006abe9a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006abe9e  50                   push eax
// 006abe9f  51                   push ecx
// 006abea0  52                   push edx
// 006abea1  e8caf3ffff           call 0x6ab270
// 006abea6  83c41c               add esp, 0x1c
// 006abea9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
