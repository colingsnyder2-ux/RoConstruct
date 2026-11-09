// from server: 100% by auto
// roc 2012-06 004caf40  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004caf40
//
// 004caf40  56                   push esi
// 004caf41  8b742408             mov esi, dword ptr [esp + 8]
// 004caf45  57                   push edi
// 004caf46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004caf4a  3bf7                 cmp esi, edi
// 004caf4c  7411                 je 0x4caf5f
// 004caf4e  8bff                 mov edi, edi
// 004caf50  8bce                 mov ecx, esi
// 004caf52  ff153c26b200         call dword ptr [0xb2263c]
// 004caf58  83c61c               add esi, 0x1c
// 004caf5b  3bf7                 cmp esi, edi
// 004caf5d  75f1                 jne 0x4caf50
// 004caf5f  5f                   pop edi
// 004caf60  5e                   pop esi
// 004caf61  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
