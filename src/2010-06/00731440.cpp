// from server: 100% by auto
// roc 2010-06 00731440  unit: lua_exception  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731440
//
// 00731440  51                   push ecx
// 00731441  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731445  c6042400             mov byte ptr [esp], 0
// 00731449  8b0424               mov eax, dword ptr [esp]
// 0073144c  50                   push eax
// 0073144d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00731451  52                   push edx
// 00731452  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731456  83c108               add ecx, 8
// 00731459  51                   push ecx
// 0073145a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0073145e  50                   push eax
// 0073145f  51                   push ecx
// 00731460  52                   push edx
// 00731461  e81afaffff           call 0x730e80
// 00731466  83c41c               add esp, 0x1c
// 00731469  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
