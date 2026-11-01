// from server: 100% by auto
// roc 2009-12 00798a70  unit: lua_exception  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798a70
//
// 00798a70  51                   push ecx
// 00798a71  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798a75  56                   push esi
// 00798a76  8b742410             mov esi, dword ptr [esp + 0x10]
// 00798a7a  57                   push edi
// 00798a7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00798a7f  c644240800           mov byte ptr [esp + 8], 0
// 00798a84  8b442408             mov eax, dword ptr [esp + 8]
// 00798a88  50                   push eax
// 00798a89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00798a8d  52                   push edx
// 00798a8e  83c108               add ecx, 8
// 00798a91  51                   push ecx
// 00798a92  50                   push eax
// 00798a93  56                   push esi
// 00798a94  57                   push edi
// 00798a95  e8b6feffff           call 0x798950
// 00798a9a  8d0c76               lea ecx, [esi + esi*2]
// 00798a9d  83c418               add esp, 0x18
// 00798aa0  8d04cf               lea eax, [edi + ecx*8]
// 00798aa3  5f                   pop edi
// 00798aa4  5e                   pop esi
// 00798aa5  59                   pop ecx
// 00798aa6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
