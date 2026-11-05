// from server: 100% by auto
// roc 2008-06 004460e0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004460e0
//
// 004460e0  51                   push ecx
// 004460e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004460e5  c6042400             mov byte ptr [esp], 0
// 004460e9  8b0424               mov eax, dword ptr [esp]
// 004460ec  50                   push eax
// 004460ed  8b442414             mov eax, dword ptr [esp + 0x14]
// 004460f1  52                   push edx
// 004460f2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004460f6  83c108               add ecx, 8
// 004460f9  51                   push ecx
// 004460fa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004460fe  50                   push eax
// 004460ff  51                   push ecx
// 00446100  52                   push edx
// 00446101  e82a151700           call 0x5b7630
// 00446106  83c41c               add esp, 0x1c
// 00446109  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
