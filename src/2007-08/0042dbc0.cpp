// from server: 100% by auto
// roc 2007-08 0042dbc0  unit: boost::any::_N::?$holder  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042dbc0
//
// 0042dbc0  51                   push ecx
// 0042dbc1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042dbc5  c6042400             mov byte ptr [esp], 0
// 0042dbc9  8b0424               mov eax, dword ptr [esp]
// 0042dbcc  50                   push eax
// 0042dbcd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042dbd1  52                   push edx
// 0042dbd2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042dbd6  51                   push ecx
// 0042dbd7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042dbdb  50                   push eax
// 0042dbdc  51                   push ecx
// 0042dbdd  52                   push edx
// 0042dbde  e8adfdffff           call 0x42d990
// 0042dbe3  83c41c               add esp, 0x1c
// 0042dbe6  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
