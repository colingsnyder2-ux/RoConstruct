// from server: 100% by auto
// roc 2010-06 008d31d0  unit: Ogre::VisualEngine  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d31d0
//
// 008d31d0  51                   push ecx
// 008d31d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d31d5  c6042400             mov byte ptr [esp], 0
// 008d31d9  8b0424               mov eax, dword ptr [esp]
// 008d31dc  50                   push eax
// 008d31dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d31e1  52                   push edx
// 008d31e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d31e6  83c108               add ecx, 8
// 008d31e9  51                   push ecx
// 008d31ea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008d31ee  50                   push eax
// 008d31ef  51                   push ecx
// 008d31f0  52                   push edx
// 008d31f1  e83af6ffff           call 0x8d2830
// 008d31f6  83c41c               add esp, 0x1c
// 008d31f9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
