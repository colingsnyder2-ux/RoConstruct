// from server: 100% by auto
// roc 2009-12 00425030  unit: MainLogManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425030
//
// 00425030  51                   push ecx
// 00425031  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425035  c6042400             mov byte ptr [esp], 0
// 00425039  8b0424               mov eax, dword ptr [esp]
// 0042503c  50                   push eax
// 0042503d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00425041  52                   push edx
// 00425042  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425046  83c108               add ecx, 8
// 00425049  51                   push ecx
// 0042504a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042504e  50                   push eax
// 0042504f  51                   push ecx
// 00425050  52                   push edx
// 00425051  e8faf4ffff           call 0x424550
// 00425056  83c41c               add esp, 0x1c
// 00425059  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
