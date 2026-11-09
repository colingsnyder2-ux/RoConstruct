// from server: 100% by auto
// roc 2009-12 004fb670  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fb670
//
// 004fb670  51                   push ecx
// 004fb671  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fb675  c6042400             mov byte ptr [esp], 0
// 004fb679  8b0424               mov eax, dword ptr [esp]
// 004fb67c  50                   push eax
// 004fb67d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fb681  52                   push edx
// 004fb682  8b542410             mov edx, dword ptr [esp + 0x10]
// 004fb686  83c108               add ecx, 8
// 004fb689  51                   push ecx
// 004fb68a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004fb68e  50                   push eax
// 004fb68f  51                   push ecx
// 004fb690  52                   push edx
// 004fb691  e87acdffff           call 0x4f8410
// 004fb696  83c41c               add esp, 0x1c
// 004fb699  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
