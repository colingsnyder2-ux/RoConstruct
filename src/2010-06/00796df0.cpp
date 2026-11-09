// from server: 100% by auto
// roc 2010-06 00796df0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00796df0
//
// 00796df0  51                   push ecx
// 00796df1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00796df5  c6042400             mov byte ptr [esp], 0
// 00796df9  8b0424               mov eax, dword ptr [esp]
// 00796dfc  50                   push eax
// 00796dfd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00796e01  52                   push edx
// 00796e02  8b542410             mov edx, dword ptr [esp + 0x10]
// 00796e06  83c108               add ecx, 8
// 00796e09  51                   push ecx
// 00796e0a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00796e0e  50                   push eax
// 00796e0f  51                   push ecx
// 00796e10  52                   push edx
// 00796e11  e8baf4ffff           call 0x7962d0
// 00796e16  83c41c               add esp, 0x1c
// 00796e19  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
