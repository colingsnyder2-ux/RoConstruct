// from server: 100% by auto
// roc 2008-06 004077a0  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004077a0
//
// 004077a0  56                   push esi
// 004077a1  8b742408             mov esi, dword ptr [esp + 8]
// 004077a5  57                   push edi
// 004077a6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004077aa  3bf7                 cmp esi, edi
// 004077ac  7411                 je 0x4077bf
// 004077ae  8bff                 mov edi, edi
// 004077b0  8bce                 mov ecx, esi
// 004077b2  ff1568248000         call dword ptr [0x802468]
// 004077b8  83c61c               add esi, 0x1c
// 004077bb  3bf7                 cmp esi, edi
// 004077bd  75f1                 jne 0x4077b0
// 004077bf  5f                   pop edi
// 004077c0  5e                   pop esi
// 004077c1  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
