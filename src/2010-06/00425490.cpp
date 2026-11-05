// from server: 100% by auto
// roc 2010-06 00425490  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425490
//
// 00425490  51                   push ecx
// 00425491  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00425495  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00425499  c6042400             mov byte ptr [esp], 0
// 0042549d  8b0424               mov eax, dword ptr [esp]
// 004254a0  50                   push eax
// 004254a1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004254a5  51                   push ecx
// 004254a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004254aa  52                   push edx
// 004254ab  8b542414             mov edx, dword ptr [esp + 0x14]
// 004254af  50                   push eax
// 004254b0  51                   push ecx
// 004254b1  52                   push edx
// 004254b2  e899fcffff           call 0x425150
// 004254b7  83c41c               add esp, 0x1c
// 004254ba  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
