// from server: 100% by auto
// roc 2009-06 0043ed40  unit: RBX::MergeBinder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ed40
//
// 0043ed40  51                   push ecx
// 0043ed41  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043ed45  c6042400             mov byte ptr [esp], 0
// 0043ed49  8b0424               mov eax, dword ptr [esp]
// 0043ed4c  50                   push eax
// 0043ed4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043ed51  52                   push edx
// 0043ed52  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043ed56  83c108               add ecx, 8
// 0043ed59  51                   push ecx
// 0043ed5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043ed5e  50                   push eax
// 0043ed5f  51                   push ecx
// 0043ed60  52                   push edx
// 0043ed61  e8aafeffff           call 0x43ec10
// 0043ed66  83c41c               add esp, 0x1c
// 0043ed69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
