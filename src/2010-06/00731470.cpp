// from server: 100% by auto
// roc 2010-06 00731470  unit: lua_exception  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731470
//
// 00731470  51                   push ecx
// 00731471  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731475  c6042400             mov byte ptr [esp], 0
// 00731479  8b0424               mov eax, dword ptr [esp]
// 0073147c  50                   push eax
// 0073147d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00731481  52                   push edx
// 00731482  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731486  83c108               add ecx, 8
// 00731489  51                   push ecx
// 0073148a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0073148e  50                   push eax
// 0073148f  51                   push ecx
// 00731490  52                   push edx
// 00731491  e89af8ffff           call 0x730d30
// 00731496  83c41c               add esp, 0x1c
// 00731499  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
