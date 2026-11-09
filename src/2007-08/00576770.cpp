// from server: 100% by auto
// roc 2007-08 00576770  unit: RBX::PartInstance  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00576770
//
// 00576770  51                   push ecx
// 00576771  8b542410             mov edx, dword ptr [esp + 0x10]
// 00576775  c6042400             mov byte ptr [esp], 0
// 00576779  8b0424               mov eax, dword ptr [esp]
// 0057677c  50                   push eax
// 0057677d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00576781  52                   push edx
// 00576782  8b542410             mov edx, dword ptr [esp + 0x10]
// 00576786  51                   push ecx
// 00576787  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057678b  50                   push eax
// 0057678c  51                   push ecx
// 0057678d  52                   push edx
// 0057678e  e88decffff           call 0x575420
// 00576793  83c41c               add esp, 0x1c
// 00576796  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
