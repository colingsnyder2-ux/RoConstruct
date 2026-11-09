// from server: 100% by auto
// roc 2007-08 00445230  unit: VCRenderSettings::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445230
//
// 00445230  51                   push ecx
// 00445231  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00445235  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00445239  c6042400             mov byte ptr [esp], 0
// 0044523d  8b0424               mov eax, dword ptr [esp]
// 00445240  50                   push eax
// 00445241  8b442414             mov eax, dword ptr [esp + 0x14]
// 00445245  51                   push ecx
// 00445246  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044524a  52                   push edx
// 0044524b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044524f  50                   push eax
// 00445250  51                   push ecx
// 00445251  52                   push edx
// 00445252  e869fdffff           call 0x444fc0
// 00445257  83c41c               add esp, 0x1c
// 0044525a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
