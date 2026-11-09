// from server: 100% by auto
// roc 2009-12 00444730  unit: VCRenderSettingsItem::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444730
//
// 00444730  51                   push ecx
// 00444731  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00444735  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00444739  c6042400             mov byte ptr [esp], 0
// 0044473d  8b0424               mov eax, dword ptr [esp]
// 00444740  50                   push eax
// 00444741  8b442414             mov eax, dword ptr [esp + 0x14]
// 00444745  51                   push ecx
// 00444746  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044474a  52                   push edx
// 0044474b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044474f  50                   push eax
// 00444750  51                   push ecx
// 00444751  52                   push edx
// 00444752  e869fbffff           call 0x4442c0
// 00444757  83c41c               add esp, 0x1c
// 0044475a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
