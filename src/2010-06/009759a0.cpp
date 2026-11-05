// from server: 100% by auto
// roc 2010-06 009759a0  unit: RBX::RightAngleRampBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009759a0
//
// 009759a0  51                   push ecx
// 009759a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 009759a5  c6042400             mov byte ptr [esp], 0
// 009759a9  8b0424               mov eax, dword ptr [esp]
// 009759ac  50                   push eax
// 009759ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 009759b1  52                   push edx
// 009759b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 009759b6  83c108               add ecx, 8
// 009759b9  51                   push ecx
// 009759ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009759be  50                   push eax
// 009759bf  51                   push ecx
// 009759c0  52                   push edx
// 009759c1  e84ad0fdff           call 0x952a10
// 009759c6  83c41c               add esp, 0x1c
// 009759c9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
