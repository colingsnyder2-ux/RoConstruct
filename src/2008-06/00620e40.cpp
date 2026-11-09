// from server: 100% by auto
// roc 2008-06 00620e40  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620e40
//
// 00620e40  51                   push ecx
// 00620e41  8b542410             mov edx, dword ptr [esp + 0x10]
// 00620e45  56                   push esi
// 00620e46  8b742410             mov esi, dword ptr [esp + 0x10]
// 00620e4a  57                   push edi
// 00620e4b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00620e4f  c644240800           mov byte ptr [esp + 8], 0
// 00620e54  8b442408             mov eax, dword ptr [esp + 8]
// 00620e58  50                   push eax
// 00620e59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00620e5d  52                   push edx
// 00620e5e  83c108               add ecx, 8
// 00620e61  51                   push ecx
// 00620e62  50                   push eax
// 00620e63  56                   push esi
// 00620e64  57                   push edi
// 00620e65  e856ffffff           call 0x620dc0
// 00620e6a  8d0c76               lea ecx, [esi + esi*2]
// 00620e6d  83c418               add esp, 0x18
// 00620e70  8d04cf               lea eax, [edi + ecx*8]
// 00620e73  5f                   pop edi
// 00620e74  5e                   pop esi
// 00620e75  59                   pop ecx
// 00620e76  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
