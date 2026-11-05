// from server: 100% by auto
// roc 2009-06 0043ffe0  unit: VCRenderSettingsItem::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ffe0
//
// 0043ffe0  51                   push ecx
// 0043ffe1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043ffe5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0043ffe9  c6042400             mov byte ptr [esp], 0
// 0043ffed  8b0424               mov eax, dword ptr [esp]
// 0043fff0  50                   push eax
// 0043fff1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043fff5  51                   push ecx
// 0043fff6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043fffa  52                   push edx
// 0043fffb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0043ffff  50                   push eax
// 00440000  51                   push ecx
// 00440001  52                   push edx
// 00440002  e8d9fbffff           call 0x43fbe0
// 00440007  83c41c               add esp, 0x1c
// 0044000a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
