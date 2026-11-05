// from server: 100% by auto
// roc 2009-06 0065e8d0  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065e8d0
//
// 0065e8d0  51                   push ecx
// 0065e8d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065e8d5  c6042400             mov byte ptr [esp], 0
// 0065e8d9  8b0424               mov eax, dword ptr [esp]
// 0065e8dc  50                   push eax
// 0065e8dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0065e8e1  52                   push edx
// 0065e8e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065e8e6  83c108               add ecx, 8
// 0065e8e9  51                   push ecx
// 0065e8ea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065e8ee  50                   push eax
// 0065e8ef  51                   push ecx
// 0065e8f0  52                   push edx
// 0065e8f1  e8faeaffff           call 0x65d3f0
// 0065e8f6  83c41c               add esp, 0x1c
// 0065e8f9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
