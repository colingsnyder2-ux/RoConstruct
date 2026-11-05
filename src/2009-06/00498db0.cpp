// from server: 100% by auto
// roc 2009-06 00498db0  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498db0
//
// 00498db0  51                   push ecx
// 00498db1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00498db5  c6042400             mov byte ptr [esp], 0
// 00498db9  8b0424               mov eax, dword ptr [esp]
// 00498dbc  50                   push eax
// 00498dbd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00498dc1  52                   push edx
// 00498dc2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00498dc6  83c108               add ecx, 8
// 00498dc9  51                   push ecx
// 00498dca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00498dce  50                   push eax
// 00498dcf  51                   push ecx
// 00498dd0  52                   push edx
// 00498dd1  e89afbffff           call 0x498970
// 00498dd6  83c41c               add esp, 0x1c
// 00498dd9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
