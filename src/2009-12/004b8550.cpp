// from server: 100% by auto
// roc 2009-12 004b8550  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b8550
//
// 004b8550  51                   push ecx
// 004b8551  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b8555  c6042400             mov byte ptr [esp], 0
// 004b8559  8b0424               mov eax, dword ptr [esp]
// 004b855c  50                   push eax
// 004b855d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b8561  52                   push edx
// 004b8562  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b8566  83c108               add ecx, 8
// 004b8569  51                   push ecx
// 004b856a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b856e  50                   push eax
// 004b856f  51                   push ecx
// 004b8570  52                   push edx
// 004b8571  e83afbffff           call 0x4b80b0
// 004b8576  83c41c               add esp, 0x1c
// 004b8579  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
