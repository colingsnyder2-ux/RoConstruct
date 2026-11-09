// from server: 100% by auto
// roc 2007-08 00443950  unit: RBX::MergeBinder  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00443950
//
// 00443950  51                   push ecx
// 00443951  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443955  c6042400             mov byte ptr [esp], 0
// 00443959  8b0424               mov eax, dword ptr [esp]
// 0044395c  50                   push eax
// 0044395d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00443961  52                   push edx
// 00443962  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443966  51                   push ecx
// 00443967  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044396b  50                   push eax
// 0044396c  51                   push ecx
// 0044396d  52                   push edx
// 0044396e  e83dfdffff           call 0x4436b0
// 00443973  83c41c               add esp, 0x1c
// 00443976  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
