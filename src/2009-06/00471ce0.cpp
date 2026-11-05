// from server: 100% by auto
// roc 2009-06 00471ce0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00471ce0
//
// 00471ce0  51                   push ecx
// 00471ce1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00471ce5  56                   push esi
// 00471ce6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00471cea  57                   push edi
// 00471ceb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00471cef  c644240800           mov byte ptr [esp + 8], 0
// 00471cf4  8b442408             mov eax, dword ptr [esp + 8]
// 00471cf8  50                   push eax
// 00471cf9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00471cfd  52                   push edx
// 00471cfe  83c108               add ecx, 8
// 00471d01  51                   push ecx
// 00471d02  50                   push eax
// 00471d03  56                   push esi
// 00471d04  57                   push edi
// 00471d05  e846feffff           call 0x471b50
// 00471d0a  8bc6                 mov eax, esi
// 00471d0c  83c418               add esp, 0x18
// 00471d0f  c1e006               shl eax, 6
// 00471d12  03c7                 add eax, edi
// 00471d14  5f                   pop edi
// 00471d15  5e                   pop esi
// 00471d16  59                   pop ecx
// 00471d17  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
