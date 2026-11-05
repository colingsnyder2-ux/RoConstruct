// from server: 100% by auto
// roc 2008-06 00444290  unit: RBX::MergeBinder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00444290
//
// 00444290  51                   push ecx
// 00444291  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444295  c6042400             mov byte ptr [esp], 0
// 00444299  8b0424               mov eax, dword ptr [esp]
// 0044429c  50                   push eax
// 0044429d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004442a1  52                   push edx
// 004442a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004442a6  83c108               add ecx, 8
// 004442a9  51                   push ecx
// 004442aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004442ae  50                   push eax
// 004442af  51                   push ecx
// 004442b0  52                   push edx
// 004442b1  e84afdffff           call 0x444000
// 004442b6  83c41c               add esp, 0x1c
// 004442b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
