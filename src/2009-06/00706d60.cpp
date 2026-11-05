// from server: 100% by auto
// roc 2009-06 00706d60  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00706d60
//
// 00706d60  51                   push ecx
// 00706d61  8b542410             mov edx, dword ptr [esp + 0x10]
// 00706d65  c6042400             mov byte ptr [esp], 0
// 00706d69  8b0424               mov eax, dword ptr [esp]
// 00706d6c  50                   push eax
// 00706d6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00706d71  52                   push edx
// 00706d72  8b542410             mov edx, dword ptr [esp + 0x10]
// 00706d76  83c108               add ecx, 8
// 00706d79  51                   push ecx
// 00706d7a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00706d7e  50                   push eax
// 00706d7f  51                   push ecx
// 00706d80  52                   push edx
// 00706d81  e8aaf3ffff           call 0x706130
// 00706d86  83c41c               add esp, 0x1c
// 00706d89  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
