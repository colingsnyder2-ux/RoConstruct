// from server: 100% by auto
// roc 2009-12 00427300  unit: boost::any::H::?$holder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427300
//
// 00427300  51                   push ecx
// 00427301  8b542410             mov edx, dword ptr [esp + 0x10]
// 00427305  c6042400             mov byte ptr [esp], 0
// 00427309  8b0424               mov eax, dword ptr [esp]
// 0042730c  50                   push eax
// 0042730d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00427311  52                   push edx
// 00427312  8b542410             mov edx, dword ptr [esp + 0x10]
// 00427316  83c108               add ecx, 8
// 00427319  51                   push ecx
// 0042731a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042731e  50                   push eax
// 0042731f  51                   push ecx
// 00427320  52                   push edx
// 00427321  e89afaffff           call 0x426dc0
// 00427326  83c41c               add esp, 0x1c
// 00427329  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
