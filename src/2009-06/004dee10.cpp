// from server: 100% by auto
// roc 2009-06 004dee10  unit: RBX::Network::IdSerializer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dee10
//
// 004dee10  51                   push ecx
// 004dee11  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dee15  c6042400             mov byte ptr [esp], 0
// 004dee19  8b0424               mov eax, dword ptr [esp]
// 004dee1c  50                   push eax
// 004dee1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004dee21  52                   push edx
// 004dee22  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dee26  83c108               add ecx, 8
// 004dee29  51                   push ecx
// 004dee2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004dee2e  50                   push eax
// 004dee2f  51                   push ecx
// 004dee30  52                   push edx
// 004dee31  e8caf6ffff           call 0x4de500
// 004dee36  83c41c               add esp, 0x1c
// 004dee39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
