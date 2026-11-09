// from server: 100% by auto
// roc 2010-06 007501b0  unit: RBX::Humanoid  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007501b0
//
// 007501b0  51                   push ecx
// 007501b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007501b5  c6042400             mov byte ptr [esp], 0
// 007501b9  8b0424               mov eax, dword ptr [esp]
// 007501bc  50                   push eax
// 007501bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 007501c1  52                   push edx
// 007501c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007501c6  83c108               add ecx, 8
// 007501c9  51                   push ecx
// 007501ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007501ce  50                   push eax
// 007501cf  51                   push ecx
// 007501d0  52                   push edx
// 007501d1  e81afaffff           call 0x74fbf0
// 007501d6  83c41c               add esp, 0x1c
// 007501d9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
