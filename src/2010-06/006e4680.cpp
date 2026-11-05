// from server: 100% by auto
// roc 2010-06 006e4680  unit: RBX::VLuaDragger::?$FactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e4680
//
// 006e4680  51                   push ecx
// 006e4681  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e4685  c6042400             mov byte ptr [esp], 0
// 006e4689  8b0424               mov eax, dword ptr [esp]
// 006e468c  50                   push eax
// 006e468d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006e4691  52                   push edx
// 006e4692  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e4696  83c108               add ecx, 8
// 006e4699  51                   push ecx
// 006e469a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006e469e  50                   push eax
// 006e469f  51                   push ecx
// 006e46a0  52                   push edx
// 006e46a1  e8aaf8ffff           call 0x6e3f50
// 006e46a6  83c41c               add esp, 0x1c
// 006e46a9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
