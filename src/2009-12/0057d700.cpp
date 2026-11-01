// from server: 100% by auto
// roc 2009-12 0057d700  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d700
//
// 0057d700  51                   push ecx
// 0057d701  8b542410             mov edx, dword ptr [esp + 0x10]
// 0057d705  c6042400             mov byte ptr [esp], 0
// 0057d709  8b0424               mov eax, dword ptr [esp]
// 0057d70c  50                   push eax
// 0057d70d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057d711  52                   push edx
// 0057d712  8b542410             mov edx, dword ptr [esp + 0x10]
// 0057d716  83c108               add ecx, 8
// 0057d719  51                   push ecx
// 0057d71a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057d71e  50                   push eax
// 0057d71f  51                   push ecx
// 0057d720  52                   push edx
// 0057d721  e8fad5f2ff           call 0x4aad20
// 0057d726  83c41c               add esp, 0x1c
// 0057d729  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
