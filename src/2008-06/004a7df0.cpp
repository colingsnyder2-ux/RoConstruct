// from server: 100% by auto
// roc 2008-06 004a7df0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7df0
//
// 004a7df0  51                   push ecx
// 004a7df1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a7df5  c6042400             mov byte ptr [esp], 0
// 004a7df9  8b0424               mov eax, dword ptr [esp]
// 004a7dfc  50                   push eax
// 004a7dfd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a7e01  52                   push edx
// 004a7e02  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a7e06  83c108               add ecx, 8
// 004a7e09  51                   push ecx
// 004a7e0a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a7e0e  50                   push eax
// 004a7e0f  51                   push ecx
// 004a7e10  52                   push edx
// 004a7e11  e80af7ffff           call 0x4a7520
// 004a7e16  83c41c               add esp, 0x1c
// 004a7e19  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
