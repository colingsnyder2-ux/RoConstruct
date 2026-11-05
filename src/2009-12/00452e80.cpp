// from server: 100% by auto
// roc 2009-12 00452e80  unit: CRobloxControlColorSelector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00452e80
//
// 00452e80  51                   push ecx
// 00452e81  8b542410             mov edx, dword ptr [esp + 0x10]
// 00452e85  c6042400             mov byte ptr [esp], 0
// 00452e89  8b0424               mov eax, dword ptr [esp]
// 00452e8c  50                   push eax
// 00452e8d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00452e91  52                   push edx
// 00452e92  8b542410             mov edx, dword ptr [esp + 0x10]
// 00452e96  83c108               add ecx, 8
// 00452e99  51                   push ecx
// 00452e9a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00452e9e  50                   push eax
// 00452e9f  51                   push ecx
// 00452ea0  52                   push edx
// 00452ea1  e88afeffff           call 0x452d30
// 00452ea6  83c41c               add esp, 0x1c
// 00452ea9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
