// from server: 100% by auto
// roc 2007-08 00410220  unit: CopyVerb  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00410220
//
// 00410220  51                   push ecx
// 00410221  8b542410             mov edx, dword ptr [esp + 0x10]
// 00410225  c6042400             mov byte ptr [esp], 0
// 00410229  8b0424               mov eax, dword ptr [esp]
// 0041022c  50                   push eax
// 0041022d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00410231  52                   push edx
// 00410232  8b542410             mov edx, dword ptr [esp + 0x10]
// 00410236  51                   push ecx
// 00410237  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041023b  50                   push eax
// 0041023c  51                   push ecx
// 0041023d  52                   push edx
// 0041023e  e8ddf6ffff           call 0x40f920
// 00410243  83c41c               add esp, 0x1c
// 00410246  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
