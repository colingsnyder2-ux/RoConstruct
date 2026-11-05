// from server: 100% by auto
// roc 2010-06 005416b0  unit: RBX::AggregatingSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005416b0
//
// 005416b0  51                   push ecx
// 005416b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005416b5  c6042400             mov byte ptr [esp], 0
// 005416b9  8b0424               mov eax, dword ptr [esp]
// 005416bc  50                   push eax
// 005416bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 005416c1  52                   push edx
// 005416c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 005416c6  83c108               add ecx, 8
// 005416c9  51                   push ecx
// 005416ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005416ce  50                   push eax
// 005416cf  51                   push ecx
// 005416d0  52                   push edx
// 005416d1  e8bae9ffff           call 0x540090
// 005416d6  83c41c               add esp, 0x1c
// 005416d9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
