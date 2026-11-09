// from server: 100% by auto
// roc 2010-06 00764600  unit: RBX::GuiLayerCollector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00764600
//
// 00764600  51                   push ecx
// 00764601  8b542410             mov edx, dword ptr [esp + 0x10]
// 00764605  c6042400             mov byte ptr [esp], 0
// 00764609  8b0424               mov eax, dword ptr [esp]
// 0076460c  50                   push eax
// 0076460d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00764611  52                   push edx
// 00764612  8b542410             mov edx, dword ptr [esp + 0x10]
// 00764616  83c108               add ecx, 8
// 00764619  51                   push ecx
// 0076461a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0076461e  50                   push eax
// 0076461f  51                   push ecx
// 00764620  52                   push edx
// 00764621  e84afdffff           call 0x764370
// 00764626  83c41c               add esp, 0x1c
// 00764629  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
