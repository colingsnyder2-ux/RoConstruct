// from server: 100% by auto
// roc 2008-06 00560a40  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560a40
//
// 00560a40  51                   push ecx
// 00560a41  8b542410             mov edx, dword ptr [esp + 0x10]
// 00560a45  c6042400             mov byte ptr [esp], 0
// 00560a49  8b0424               mov eax, dword ptr [esp]
// 00560a4c  50                   push eax
// 00560a4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00560a51  52                   push edx
// 00560a52  8b542410             mov edx, dword ptr [esp + 0x10]
// 00560a56  83c108               add ecx, 8
// 00560a59  51                   push ecx
// 00560a5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00560a5e  50                   push eax
// 00560a5f  51                   push ecx
// 00560a60  52                   push edx
// 00560a61  e8bae2ffff           call 0x55ed20
// 00560a66  83c41c               add esp, 0x1c
// 00560a69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
