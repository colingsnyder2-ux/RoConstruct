// from server: 100% by auto
// roc 2010-06 00425460  unit: MainLogManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425460
//
// 00425460  51                   push ecx
// 00425461  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425465  c6042400             mov byte ptr [esp], 0
// 00425469  8b0424               mov eax, dword ptr [esp]
// 0042546c  50                   push eax
// 0042546d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00425471  52                   push edx
// 00425472  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425476  83c108               add ecx, 8
// 00425479  51                   push ecx
// 0042547a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042547e  50                   push eax
// 0042547f  51                   push ecx
// 00425480  52                   push edx
// 00425481  e80af4ffff           call 0x424890
// 00425486  83c41c               add esp, 0x1c
// 00425489  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
