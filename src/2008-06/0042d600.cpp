// from server: 100% by auto
// roc 2008-06 0042d600  unit: boost::any::H::?$holder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042d600
//
// 0042d600  51                   push ecx
// 0042d601  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042d605  c6042400             mov byte ptr [esp], 0
// 0042d609  8b0424               mov eax, dword ptr [esp]
// 0042d60c  50                   push eax
// 0042d60d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042d611  52                   push edx
// 0042d612  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042d616  83c108               add ecx, 8
// 0042d619  51                   push ecx
// 0042d61a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042d61e  50                   push eax
// 0042d61f  51                   push ecx
// 0042d620  52                   push edx
// 0042d621  e8aa001300           call 0x55d6d0
// 0042d626  83c41c               add esp, 0x1c
// 0042d629  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
