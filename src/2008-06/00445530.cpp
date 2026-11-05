// from server: 100% by auto
// roc 2008-06 00445530  unit: VCRenderSettings::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445530
//
// 00445530  51                   push ecx
// 00445531  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00445535  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00445539  c6042400             mov byte ptr [esp], 0
// 0044553d  8b0424               mov eax, dword ptr [esp]
// 00445540  50                   push eax
// 00445541  8b442414             mov eax, dword ptr [esp + 0x14]
// 00445545  51                   push ecx
// 00445546  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044554a  52                   push edx
// 0044554b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044554f  50                   push eax
// 00445550  51                   push ecx
// 00445551  52                   push edx
// 00445552  e8b9fdffff           call 0x445310
// 00445557  83c41c               add esp, 0x1c
// 0044555a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
