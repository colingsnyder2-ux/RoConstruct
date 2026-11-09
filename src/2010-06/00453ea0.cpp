// from server: 100% by auto
// roc 2010-06 00453ea0  unit: CRobloxControlColorSelector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00453ea0
//
// 00453ea0  51                   push ecx
// 00453ea1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00453ea5  c6042400             mov byte ptr [esp], 0
// 00453ea9  8b0424               mov eax, dword ptr [esp]
// 00453eac  50                   push eax
// 00453ead  8b442414             mov eax, dword ptr [esp + 0x14]
// 00453eb1  52                   push edx
// 00453eb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00453eb6  83c108               add ecx, 8
// 00453eb9  51                   push ecx
// 00453eba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00453ebe  50                   push eax
// 00453ebf  51                   push ecx
// 00453ec0  52                   push edx
// 00453ec1  e80afeffff           call 0x453cd0
// 00453ec6  83c41c               add esp, 0x1c
// 00453ec9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
