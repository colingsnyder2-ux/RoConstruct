// from server: 100% by auto
// roc 2009-06 004244b0  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004244b0
//
// 004244b0  51                   push ecx
// 004244b1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004244b5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004244b9  c6042400             mov byte ptr [esp], 0
// 004244bd  8b0424               mov eax, dword ptr [esp]
// 004244c0  50                   push eax
// 004244c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004244c5  51                   push ecx
// 004244c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004244ca  52                   push edx
// 004244cb  8b542414             mov edx, dword ptr [esp + 0x14]
// 004244cf  50                   push eax
// 004244d0  51                   push ecx
// 004244d1  52                   push edx
// 004244d2  e849ffffff           call 0x424420
// 004244d7  83c41c               add esp, 0x1c
// 004244da  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
