// from server: 100% by auto
// roc 2009-06 006d64e0  unit: RBX::Mechanism  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d64e0
//
// 006d64e0  51                   push ecx
// 006d64e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d64e5  c6042400             mov byte ptr [esp], 0
// 006d64e9  8b0424               mov eax, dword ptr [esp]
// 006d64ec  50                   push eax
// 006d64ed  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d64f1  52                   push edx
// 006d64f2  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d64f6  83c108               add ecx, 8
// 006d64f9  51                   push ecx
// 006d64fa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006d64fe  50                   push eax
// 006d64ff  51                   push ecx
// 006d6500  52                   push edx
// 006d6501  e80afbffff           call 0x6d6010
// 006d6506  83c41c               add esp, 0x1c
// 006d6509  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
