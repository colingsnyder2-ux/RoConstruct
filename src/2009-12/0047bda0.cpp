// from server: 100% by auto
// roc 2009-12 0047bda0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047bda0
//
// 0047bda0  51                   push ecx
// 0047bda1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047bda5  56                   push esi
// 0047bda6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0047bdaa  57                   push edi
// 0047bdab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0047bdaf  c644240800           mov byte ptr [esp + 8], 0
// 0047bdb4  8b442408             mov eax, dword ptr [esp + 8]
// 0047bdb8  50                   push eax
// 0047bdb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047bdbd  52                   push edx
// 0047bdbe  83c108               add ecx, 8
// 0047bdc1  51                   push ecx
// 0047bdc2  50                   push eax
// 0047bdc3  56                   push esi
// 0047bdc4  57                   push edi
// 0047bdc5  e846feffff           call 0x47bc10
// 0047bdca  8bc6                 mov eax, esi
// 0047bdcc  83c418               add esp, 0x18
// 0047bdcf  c1e006               shl eax, 6
// 0047bdd2  03c7                 add eax, edi
// 0047bdd4  5f                   pop edi
// 0047bdd5  5e                   pop esi
// 0047bdd6  59                   pop ecx
// 0047bdd7  c20c00               ret 0xc
// standard library vector<pod64> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
