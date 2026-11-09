// from server: 100% by auto
// roc 2008-06 0059bc40  unit: RBX::PartInstance  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059bc40
//
// 0059bc40  51                   push ecx
// 0059bc41  8b542410             mov edx, dword ptr [esp + 0x10]
// 0059bc45  c6042400             mov byte ptr [esp], 0
// 0059bc49  8b0424               mov eax, dword ptr [esp]
// 0059bc4c  50                   push eax
// 0059bc4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0059bc51  52                   push edx
// 0059bc52  8b542410             mov edx, dword ptr [esp + 0x10]
// 0059bc56  83c108               add ecx, 8
// 0059bc59  51                   push ecx
// 0059bc5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0059bc5e  50                   push eax
// 0059bc5f  51                   push ecx
// 0059bc60  52                   push edx
// 0059bc61  e83aedffff           call 0x59a9a0
// 0059bc66  83c41c               add esp, 0x1c
// 0059bc69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
