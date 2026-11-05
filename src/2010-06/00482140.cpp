// from server: 100% by auto
// roc 2010-06 00482140  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482140
//
// 00482140  51                   push ecx
// 00482141  8b542410             mov edx, dword ptr [esp + 0x10]
// 00482145  56                   push esi
// 00482146  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048214a  57                   push edi
// 0048214b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048214f  c644240800           mov byte ptr [esp + 8], 0
// 00482154  8b442408             mov eax, dword ptr [esp + 8]
// 00482158  50                   push eax
// 00482159  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048215d  52                   push edx
// 0048215e  83c108               add ecx, 8
// 00482161  51                   push ecx
// 00482162  50                   push eax
// 00482163  56                   push esi
// 00482164  57                   push edi
// 00482165  e846feffff           call 0x481fb0
// 0048216a  8bc6                 mov eax, esi
// 0048216c  83c418               add esp, 0x18
// 0048216f  c1e006               shl eax, 6
// 00482172  03c7                 add eax, edi
// 00482174  5f                   pop edi
// 00482175  5e                   pop esi
// 00482176  59                   pop ecx
// 00482177  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
