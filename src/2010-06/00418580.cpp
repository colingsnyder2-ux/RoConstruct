// from server: 100% by auto
// roc 2010-06 00418580  unit: RBX::VTool::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00418580
//
// 00418580  56                   push esi
// 00418581  8b742408             mov esi, dword ptr [esp + 8]
// 00418585  57                   push edi
// 00418586  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0041858a  3bf7                 cmp esi, edi
// 0041858c  7411                 je 0x41859f
// 0041858e  8bff                 mov edi, edi
// 00418590  8bce                 mov ecx, esi
// 00418592  ff1500a49e00         call dword ptr [0x9ea400]
// 00418598  83c61c               add esi, 0x1c
// 0041859b  3bf7                 cmp esi, edi
// 0041859d  75f1                 jne 0x418590
// 0041859f  5f                   pop edi
// 004185a0  5e                   pop esi
// 004185a1  c20800               ret 8
// standard library vector<string> (function ?_Destroy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
