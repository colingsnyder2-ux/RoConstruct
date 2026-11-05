// from server: 100% by auto
// roc 2010-06 00742070  unit: RBX::VHttp::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00742070
//
// 00742070  51                   push ecx
// 00742071  8b542410             mov edx, dword ptr [esp + 0x10]
// 00742075  c6042400             mov byte ptr [esp], 0
// 00742079  8b0424               mov eax, dword ptr [esp]
// 0074207c  50                   push eax
// 0074207d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00742081  52                   push edx
// 00742082  8b542410             mov edx, dword ptr [esp + 0x10]
// 00742086  83c108               add ecx, 8
// 00742089  51                   push ecx
// 0074208a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0074208e  50                   push eax
// 0074208f  51                   push ecx
// 00742090  52                   push edx
// 00742091  e82af8ffff           call 0x7418c0
// 00742096  83c41c               add esp, 0x1c
// 00742099  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
