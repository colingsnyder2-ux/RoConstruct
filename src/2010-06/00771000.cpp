// from server: 100% by auto
// roc 2010-06 00771000  unit: RBX::ScoreHud  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00771000
//
// 00771000  51                   push ecx
// 00771001  8b542410             mov edx, dword ptr [esp + 0x10]
// 00771005  56                   push esi
// 00771006  8b742410             mov esi, dword ptr [esp + 0x10]
// 0077100a  57                   push edi
// 0077100b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0077100f  c644240800           mov byte ptr [esp + 8], 0
// 00771014  8b442408             mov eax, dword ptr [esp + 8]
// 00771018  50                   push eax
// 00771019  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0077101d  52                   push edx
// 0077101e  83c108               add ecx, 8
// 00771021  51                   push ecx
// 00771022  50                   push eax
// 00771023  56                   push esi
// 00771024  57                   push edi
// 00771025  e8f6f0ffff           call 0x770120
// 0077102a  8d0c76               lea ecx, [esi + esi*2]
// 0077102d  83c418               add esp, 0x18
// 00771030  8d04cf               lea eax, [edi + ecx*8]
// 00771033  5f                   pop edi
// 00771034  5e                   pop esi
// 00771035  59                   pop ecx
// 00771036  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
