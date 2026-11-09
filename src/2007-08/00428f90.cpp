// from server: 100% by auto
// roc 2007-08 00428f90  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428f90
//
// 00428f90  51                   push ecx
// 00428f91  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428f95  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00428f99  c6042400             mov byte ptr [esp], 0
// 00428f9d  8b0424               mov eax, dword ptr [esp]
// 00428fa0  50                   push eax
// 00428fa1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00428fa5  51                   push ecx
// 00428fa6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00428faa  52                   push edx
// 00428fab  8b542414             mov edx, dword ptr [esp + 0x14]
// 00428faf  50                   push eax
// 00428fb0  51                   push ecx
// 00428fb1  52                   push edx
// 00428fb2  e899f8ffff           call 0x428850
// 00428fb7  83c41c               add esp, 0x1c
// 00428fba  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
