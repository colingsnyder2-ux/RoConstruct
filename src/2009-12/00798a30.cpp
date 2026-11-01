// from server: 100% by auto
// roc 2009-12 00798a30  unit: lua_exception  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798a30
//
// 00798a30  51                   push ecx
// 00798a31  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798a35  56                   push esi
// 00798a36  8b742410             mov esi, dword ptr [esp + 0x10]
// 00798a3a  57                   push edi
// 00798a3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00798a3f  c644240800           mov byte ptr [esp + 8], 0
// 00798a44  8b442408             mov eax, dword ptr [esp + 8]
// 00798a48  50                   push eax
// 00798a49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00798a4d  52                   push edx
// 00798a4e  83c108               add ecx, 8
// 00798a51  51                   push ecx
// 00798a52  50                   push eax
// 00798a53  56                   push esi
// 00798a54  57                   push edi
// 00798a55  e8a6feffff           call 0x798900
// 00798a5a  8d0c76               lea ecx, [esi + esi*2]
// 00798a5d  83c418               add esp, 0x18
// 00798a60  8d04cf               lea eax, [edi + ecx*8]
// 00798a63  5f                   pop edi
// 00798a64  5e                   pop esi
// 00798a65  59                   pop ecx
// 00798a66  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
