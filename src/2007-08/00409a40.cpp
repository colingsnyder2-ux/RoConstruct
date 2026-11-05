// from server: 100% by auto
// roc 2007-08 00409a40  unit: VCApp::?$CComObject  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409a40
//
// 00409a40  56                   push esi
// 00409a41  8b742408             mov esi, dword ptr [esp + 8]
// 00409a45  57                   push edi
// 00409a46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00409a4a  3bf7                 cmp esi, edi
// 00409a4c  7411                 je 0x409a5f
// 00409a4e  8bff                 mov edi, edi
// 00409a50  8bce                 mov ecx, esi
// 00409a52  ff15ace67700         call dword ptr [0x77e6ac]
// 00409a58  83c61c               add esi, 0x1c
// 00409a5b  3bf7                 cmp esi, edi
// 00409a5d  75f1                 jne 0x409a50
// 00409a5f  5f                   pop edi
// 00409a60  5e                   pop esi
// 00409a61  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
