// from server: 100% by auto
// roc 2010-06 004ed650  unit: RBX::Network::Replicator::NewInstanceItem  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed650
//
// 004ed650  51                   push ecx
// 004ed651  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ed655  c6042400             mov byte ptr [esp], 0
// 004ed659  8b0424               mov eax, dword ptr [esp]
// 004ed65c  50                   push eax
// 004ed65d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ed661  52                   push edx
// 004ed662  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ed666  83c108               add ecx, 8
// 004ed669  51                   push ecx
// 004ed66a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ed66e  50                   push eax
// 004ed66f  51                   push ecx
// 004ed670  52                   push edx
// 004ed671  e8fa60fcff           call 0x4b3770
// 004ed676  83c41c               add esp, 0x1c
// 004ed679  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
