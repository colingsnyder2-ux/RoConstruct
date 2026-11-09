// from server: 100% by auto
// roc 2008-06 00444250  unit: RBX::MergeBinder  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00444250
//
// 00444250  51                   push ecx
// 00444251  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444255  56                   push esi
// 00444256  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044425a  57                   push edi
// 0044425b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044425f  c644240800           mov byte ptr [esp + 8], 0
// 00444264  8b442408             mov eax, dword ptr [esp + 8]
// 00444268  50                   push eax
// 00444269  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044426d  52                   push edx
// 0044426e  83c108               add ecx, 8
// 00444271  51                   push ecx
// 00444272  50                   push eax
// 00444273  56                   push esi
// 00444274  57                   push edi
// 00444275  e8d6fdffff           call 0x444050
// 0044427a  8bc6                 mov eax, esi
// 0044427c  83c418               add esp, 0x18
// 0044427f  c1e004               shl eax, 4
// 00444282  03c7                 add eax, edi
// 00444284  5f                   pop edi
// 00444285  5e                   pop esi
// 00444286  59                   pop ecx
// 00444287  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
