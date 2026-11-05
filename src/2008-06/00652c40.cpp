// from server: 100% by auto
// roc 2008-06 00652c40  unit: RBX::ScoreHud  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652c40
//
// 00652c40  51                   push ecx
// 00652c41  8b542410             mov edx, dword ptr [esp + 0x10]
// 00652c45  56                   push esi
// 00652c46  8b742410             mov esi, dword ptr [esp + 0x10]
// 00652c4a  57                   push edi
// 00652c4b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00652c4f  c644240800           mov byte ptr [esp + 8], 0
// 00652c54  8b442408             mov eax, dword ptr [esp + 8]
// 00652c58  50                   push eax
// 00652c59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00652c5d  52                   push edx
// 00652c5e  83c108               add ecx, 8
// 00652c61  51                   push ecx
// 00652c62  50                   push eax
// 00652c63  56                   push esi
// 00652c64  57                   push edi
// 00652c65  e866f1ffff           call 0x651dd0
// 00652c6a  8d0c76               lea ecx, [esi + esi*2]
// 00652c6d  83c418               add esp, 0x18
// 00652c70  8d04cf               lea eax, [edi + ecx*8]
// 00652c73  5f                   pop edi
// 00652c74  5e                   pop esi
// 00652c75  59                   pop ecx
// 00652c76  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
