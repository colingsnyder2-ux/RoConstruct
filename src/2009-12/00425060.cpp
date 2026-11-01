// from server: 100% by auto
// roc 2009-12 00425060  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425060
//
// 00425060  51                   push ecx
// 00425061  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00425065  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00425069  c6042400             mov byte ptr [esp], 0
// 0042506d  8b0424               mov eax, dword ptr [esp]
// 00425070  50                   push eax
// 00425071  8b442414             mov eax, dword ptr [esp + 0x14]
// 00425075  51                   push ecx
// 00425076  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042507a  52                   push edx
// 0042507b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0042507f  50                   push eax
// 00425080  51                   push ecx
// 00425081  52                   push edx
// 00425082  e899fcffff           call 0x424d20
// 00425087  83c41c               add esp, 0x1c
// 0042508a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
