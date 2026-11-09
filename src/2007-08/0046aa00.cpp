// from server: 100% by auto
// roc 2007-08 0046aa00  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046aa00
//
// 0046aa00  51                   push ecx
// 0046aa01  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046aa05  56                   push esi
// 0046aa06  8b742410             mov esi, dword ptr [esp + 0x10]
// 0046aa0a  57                   push edi
// 0046aa0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0046aa0f  c644240800           mov byte ptr [esp + 8], 0
// 0046aa14  8b442408             mov eax, dword ptr [esp + 8]
// 0046aa18  50                   push eax
// 0046aa19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046aa1d  52                   push edx
// 0046aa1e  51                   push ecx
// 0046aa1f  50                   push eax
// 0046aa20  56                   push esi
// 0046aa21  57                   push edi
// 0046aa22  e839feffff           call 0x46a860
// 0046aa27  8bc6                 mov eax, esi
// 0046aa29  83c418               add esp, 0x18
// 0046aa2c  c1e006               shl eax, 6
// 0046aa2f  03c7                 add eax, edi
// 0046aa31  5f                   pop edi
// 0046aa32  5e                   pop esi
// 0046aa33  59                   pop ecx
// 0046aa34  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
