// from server: 100% by auto
// roc 2009-12 00535660  unit: RBX::Network::IdSerializer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00535660
//
// 00535660  51                   push ecx
// 00535661  8b542410             mov edx, dword ptr [esp + 0x10]
// 00535665  c6042400             mov byte ptr [esp], 0
// 00535669  8b0424               mov eax, dword ptr [esp]
// 0053566c  50                   push eax
// 0053566d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535671  52                   push edx
// 00535672  8b542410             mov edx, dword ptr [esp + 0x10]
// 00535676  83c108               add ecx, 8
// 00535679  51                   push ecx
// 0053567a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053567e  50                   push eax
// 0053567f  51                   push ecx
// 00535680  52                   push edx
// 00535681  e87af2ffff           call 0x534900
// 00535686  83c41c               add esp, 0x1c
// 00535689  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
