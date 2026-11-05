// from server: 100% by auto
// roc 2010-06 00445a60  unit: VCRenderSettingsItem::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00445a60
//
// 00445a60  51                   push ecx
// 00445a61  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00445a65  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00445a69  c6042400             mov byte ptr [esp], 0
// 00445a6d  8b0424               mov eax, dword ptr [esp]
// 00445a70  50                   push eax
// 00445a71  8b442414             mov eax, dword ptr [esp + 0x14]
// 00445a75  51                   push ecx
// 00445a76  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00445a7a  52                   push edx
// 00445a7b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00445a7f  50                   push eax
// 00445a80  51                   push ecx
// 00445a81  52                   push edx
// 00445a82  e839fcffff           call 0x4456c0
// 00445a87  83c41c               add esp, 0x1c
// 00445a8a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
