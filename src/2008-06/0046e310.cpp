// from server: 100% by auto
// roc 2008-06 0046e310  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e310
//
// 0046e310  51                   push ecx
// 0046e311  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046e315  56                   push esi
// 0046e316  8b742410             mov esi, dword ptr [esp + 0x10]
// 0046e31a  57                   push edi
// 0046e31b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046e31f  c644240800           mov byte ptr [esp + 8], 0
// 0046e324  8b442408             mov eax, dword ptr [esp + 8]
// 0046e328  50                   push eax
// 0046e329  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046e32d  52                   push edx
// 0046e32e  83c108               add ecx, 8
// 0046e331  51                   push ecx
// 0046e332  50                   push eax
// 0046e333  56                   push esi
// 0046e334  57                   push edi
// 0046e335  e846feffff           call 0x46e180
// 0046e33a  8bc6                 mov eax, esi
// 0046e33c  83c418               add esp, 0x18
// 0046e33f  c1e006               shl eax, 6
// 0046e342  03c7                 add eax, edi
// 0046e344  5f                   pop edi
// 0046e345  5e                   pop esi
// 0046e346  59                   pop ecx
// 0046e347  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
