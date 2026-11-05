// from server: 100% by auto
// roc 2010-06 007098f0  unit: RBX::Joint  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007098f0
//
// 007098f0  51                   push ecx
// 007098f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007098f5  c6042400             mov byte ptr [esp], 0
// 007098f9  8b0424               mov eax, dword ptr [esp]
// 007098fc  50                   push eax
// 007098fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00709901  52                   push edx
// 00709902  8b542410             mov edx, dword ptr [esp + 0x10]
// 00709906  83c108               add ecx, 8
// 00709909  51                   push ecx
// 0070990a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070990e  50                   push eax
// 0070990f  51                   push ecx
// 00709910  52                   push edx
// 00709911  e83abfd3ff           call 0x445850
// 00709916  83c41c               add esp, 0x1c
// 00709919  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
