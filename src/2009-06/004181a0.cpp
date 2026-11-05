// from server: 100% by auto
// roc 2009-06 004181a0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004181a0
//
// 004181a0  56                   push esi
// 004181a1  8b742408             mov esi, dword ptr [esp + 8]
// 004181a5  57                   push edi
// 004181a6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004181aa  3bf7                 cmp esi, edi
// 004181ac  7411                 je 0x4181bf
// 004181ae  8bff                 mov edi, edi
// 004181b0  8bce                 mov ecx, esi
// 004181b2  ff15c4e48900         call dword ptr [0x89e4c4]
// 004181b8  83c61c               add esi, 0x1c
// 004181bb  3bf7                 cmp esi, edi
// 004181bd  75f1                 jne 0x4181b0
// 004181bf  5f                   pop edi
// 004181c0  5e                   pop esi
// 004181c1  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
