// from server: 100% by auto
// roc 2009-12 007bd110  unit: RBX::GuiLayerCollector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bd110
//
// 007bd110  51                   push ecx
// 007bd111  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bd115  c6042400             mov byte ptr [esp], 0
// 007bd119  8b0424               mov eax, dword ptr [esp]
// 007bd11c  50                   push eax
// 007bd11d  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bd121  52                   push edx
// 007bd122  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bd126  83c108               add ecx, 8
// 007bd129  51                   push ecx
// 007bd12a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007bd12e  50                   push eax
// 007bd12f  51                   push ecx
// 007bd130  52                   push edx
// 007bd131  e84afdffff           call 0x7bce80
// 007bd136  83c41c               add esp, 0x1c
// 007bd139  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
