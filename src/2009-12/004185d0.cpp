// from server: 100% by auto
// roc 2009-12 004185d0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004185d0
//
// 004185d0  56                   push esi
// 004185d1  8b742408             mov esi, dword ptr [esp + 8]
// 004185d5  57                   push edi
// 004185d6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004185da  3bf7                 cmp esi, edi
// 004185dc  7411                 je 0x4185ef
// 004185de  8bff                 mov edi, edi
// 004185e0  8bce                 mov ecx, esi
// 004185e2  ff15e4b69800         call dword ptr [0x98b6e4]
// 004185e8  83c61c               add esi, 0x1c
// 004185eb  3bf7                 cmp esi, edi
// 004185ed  75f1                 jne 0x4185e0
// 004185ef  5f                   pop edi
// 004185f0  5e                   pop esi
// 004185f1  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
