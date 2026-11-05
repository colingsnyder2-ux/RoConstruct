// from server: 100% by auto
// roc 2010-06 0053d470  unit: RBX::ImmediateMeshGenAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d470
//
// 0053d470  51                   push ecx
// 0053d471  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053d475  c6042400             mov byte ptr [esp], 0
// 0053d479  8b0424               mov eax, dword ptr [esp]
// 0053d47c  50                   push eax
// 0053d47d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053d481  52                   push edx
// 0053d482  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053d486  83c108               add ecx, 8
// 0053d489  51                   push ecx
// 0053d48a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053d48e  50                   push eax
// 0053d48f  51                   push ecx
// 0053d490  52                   push edx
// 0053d491  e8cafeffff           call 0x53d360
// 0053d496  83c41c               add esp, 0x1c
// 0053d499  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
