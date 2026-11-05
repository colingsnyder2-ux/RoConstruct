// from server: 100% by auto
// roc 2008-06 004293a0  unit: ThreadLogManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004293a0
//
// 004293a0  51                   push ecx
// 004293a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004293a5  c6042400             mov byte ptr [esp], 0
// 004293a9  8b0424               mov eax, dword ptr [esp]
// 004293ac  50                   push eax
// 004293ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 004293b1  52                   push edx
// 004293b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004293b6  83c108               add ecx, 8
// 004293b9  51                   push ecx
// 004293ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004293be  50                   push eax
// 004293bf  51                   push ecx
// 004293c0  52                   push edx
// 004293c1  e85af6ffff           call 0x428a20
// 004293c6  83c41c               add esp, 0x1c
// 004293c9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
