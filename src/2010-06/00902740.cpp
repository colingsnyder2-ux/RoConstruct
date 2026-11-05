// from server: 100% by auto
// roc 2010-06 00902740  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902740
//
// 00902740  51                   push ecx
// 00902741  8b542410             mov edx, dword ptr [esp + 0x10]
// 00902745  c6042400             mov byte ptr [esp], 0
// 00902749  8b0424               mov eax, dword ptr [esp]
// 0090274c  50                   push eax
// 0090274d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00902751  52                   push edx
// 00902752  8b542410             mov edx, dword ptr [esp + 0x10]
// 00902756  83c108               add ecx, 8
// 00902759  51                   push ecx
// 0090275a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0090275e  50                   push eax
// 0090275f  51                   push ecx
// 00902760  52                   push edx
// 00902761  e89afbffff           call 0x902300
// 00902766  83c41c               add esp, 0x1c
// 00902769  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
