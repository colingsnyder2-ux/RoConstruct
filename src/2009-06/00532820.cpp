// from server: 100% by auto
// roc 2009-06 00532820  unit: RBX::BeveledBlockBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532820
//
// 00532820  51                   push ecx
// 00532821  8b542410             mov edx, dword ptr [esp + 0x10]
// 00532825  c6042400             mov byte ptr [esp], 0
// 00532829  8b0424               mov eax, dword ptr [esp]
// 0053282c  50                   push eax
// 0053282d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00532831  52                   push edx
// 00532832  8b542410             mov edx, dword ptr [esp + 0x10]
// 00532836  83c108               add ecx, 8
// 00532839  51                   push ecx
// 0053283a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053283e  50                   push eax
// 0053283f  51                   push ecx
// 00532840  52                   push edx
// 00532841  e8eafdffff           call 0x532630
// 00532846  83c41c               add esp, 0x1c
// 00532849  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
