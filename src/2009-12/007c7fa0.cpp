// from server: 100% by auto
// roc 2009-12 007c7fa0  unit: RBX::ScoreHud  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7fa0
//
// 007c7fa0  51                   push ecx
// 007c7fa1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007c7fa5  c6042400             mov byte ptr [esp], 0
// 007c7fa9  8b0424               mov eax, dword ptr [esp]
// 007c7fac  50                   push eax
// 007c7fad  8b442414             mov eax, dword ptr [esp + 0x14]
// 007c7fb1  52                   push edx
// 007c7fb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007c7fb6  83c108               add ecx, 8
// 007c7fb9  51                   push ecx
// 007c7fba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007c7fbe  50                   push eax
// 007c7fbf  51                   push ecx
// 007c7fc0  52                   push edx
// 007c7fc1  e84af1ffff           call 0x7c7110
// 007c7fc6  83c41c               add esp, 0x1c
// 007c7fc9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
