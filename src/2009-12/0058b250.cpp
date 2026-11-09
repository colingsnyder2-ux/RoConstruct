// from server: 100% by auto
// roc 2009-12 0058b250  unit: RBX::BeveledBlockBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b250
//
// 0058b250  51                   push ecx
// 0058b251  8b542410             mov edx, dword ptr [esp + 0x10]
// 0058b255  c6042400             mov byte ptr [esp], 0
// 0058b259  8b0424               mov eax, dword ptr [esp]
// 0058b25c  50                   push eax
// 0058b25d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058b261  52                   push edx
// 0058b262  8b542410             mov edx, dword ptr [esp + 0x10]
// 0058b266  83c108               add ecx, 8
// 0058b269  51                   push ecx
// 0058b26a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058b26e  50                   push eax
// 0058b26f  51                   push ecx
// 0058b270  52                   push edx
// 0058b271  e89afdffff           call 0x58b010
// 0058b276  83c41c               add esp, 0x1c
// 0058b279  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
