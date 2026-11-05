// from server: 100% by auto
// roc 2010-06 00793470  unit: RBX::CircleRadialNormal  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00793470
//
// 00793470  51                   push ecx
// 00793471  8b542410             mov edx, dword ptr [esp + 0x10]
// 00793475  c6042400             mov byte ptr [esp], 0
// 00793479  8b0424               mov eax, dword ptr [esp]
// 0079347c  50                   push eax
// 0079347d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00793481  52                   push edx
// 00793482  8b542410             mov edx, dword ptr [esp + 0x10]
// 00793486  83c108               add ecx, 8
// 00793489  51                   push ecx
// 0079348a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079348e  50                   push eax
// 0079348f  51                   push ecx
// 00793490  52                   push edx
// 00793491  e86afbffff           call 0x793000
// 00793496  83c41c               add esp, 0x1c
// 00793499  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
