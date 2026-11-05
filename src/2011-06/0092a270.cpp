// from server: 100% by auto
// roc 2011-06 0092a270  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092a270
//
// 0092a270  56                   push esi
// 0092a271  8b742408             mov esi, dword ptr [esp + 8]
// 0092a275  57                   push edi
// 0092a276  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0092a27a  3bf7                 cmp esi, edi
// 0092a27c  7411                 je 0x92a28f
// 0092a27e  8bff                 mov edi, edi
// 0092a280  8bce                 mov ecx, esi
// 0092a282  ff15d004a400         call dword ptr [0xa404d0]
// 0092a288  83c61c               add esi, 0x1c
// 0092a28b  3bf7                 cmp esi, edi
// 0092a28d  75f1                 jne 0x92a280
// 0092a28f  5f                   pop edi
// 0092a290  5e                   pop esi
// 0092a291  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
