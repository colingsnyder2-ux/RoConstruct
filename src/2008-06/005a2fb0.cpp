// from server: 100% by auto
// roc 2008-06 005a2fb0  unit: RBX::Workspace  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a2fb0
//
// 005a2fb0  51                   push ecx
// 005a2fb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a2fb5  c6042400             mov byte ptr [esp], 0
// 005a2fb9  8b0424               mov eax, dword ptr [esp]
// 005a2fbc  50                   push eax
// 005a2fbd  8b442414             mov eax, dword ptr [esp + 0x14]
// 005a2fc1  52                   push edx
// 005a2fc2  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a2fc6  83c108               add ecx, 8
// 005a2fc9  51                   push ecx
// 005a2fca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005a2fce  50                   push eax
// 005a2fcf  51                   push ecx
// 005a2fd0  52                   push edx
// 005a2fd1  e88a5be9ff           call 0x438b60
// 005a2fd6  83c41c               add esp, 0x1c
// 005a2fd9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
