// from server: 100% by auto
// roc 2009-06 0043ed00  unit: RBX::MergeBinder  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043ed00
//
// 0043ed00  51                   push ecx
// 0043ed01  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043ed05  56                   push esi
// 0043ed06  8b742410             mov esi, dword ptr [esp + 0x10]
// 0043ed0a  57                   push edi
// 0043ed0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0043ed0f  c644240800           mov byte ptr [esp + 8], 0
// 0043ed14  8b442408             mov eax, dword ptr [esp + 8]
// 0043ed18  50                   push eax
// 0043ed19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043ed1d  52                   push edx
// 0043ed1e  83c108               add ecx, 8
// 0043ed21  51                   push ecx
// 0043ed22  50                   push eax
// 0043ed23  56                   push esi
// 0043ed24  57                   push edi
// 0043ed25  e836ffffff           call 0x43ec60
// 0043ed2a  8bc6                 mov eax, esi
// 0043ed2c  83c418               add esp, 0x18
// 0043ed2f  c1e004               shl eax, 4
// 0043ed32  03c7                 add eax, edi
// 0043ed34  5f                   pop edi
// 0043ed35  5e                   pop esi
// 0043ed36  59                   pop ecx
// 0043ed37  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
