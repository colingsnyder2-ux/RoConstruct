// from server: 100% by auto
// roc 2010-06 00975a90  unit: RBX::RightAngleRampBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975a90
//
// 00975a90  51                   push ecx
// 00975a91  8b542410             mov edx, dword ptr [esp + 0x10]
// 00975a95  c6042400             mov byte ptr [esp], 0
// 00975a99  8b0424               mov eax, dword ptr [esp]
// 00975a9c  50                   push eax
// 00975a9d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00975aa1  52                   push edx
// 00975aa2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00975aa6  83c108               add ecx, 8
// 00975aa9  51                   push ecx
// 00975aaa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00975aae  50                   push eax
// 00975aaf  51                   push ecx
// 00975ab0  52                   push edx
// 00975ab1  e8fafdffff           call 0x9758b0
// 00975ab6  83c41c               add esp, 0x1c
// 00975ab9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
