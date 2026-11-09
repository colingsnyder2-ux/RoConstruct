// from server: 100% by auto
// roc 2009-06 006c2030  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2030
//
// 006c2030  51                   push ecx
// 006c2031  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c2035  56                   push esi
// 006c2036  8b742410             mov esi, dword ptr [esp + 0x10]
// 006c203a  57                   push edi
// 006c203b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006c203f  c644240800           mov byte ptr [esp + 8], 0
// 006c2044  8b442408             mov eax, dword ptr [esp + 8]
// 006c2048  50                   push eax
// 006c2049  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006c204d  52                   push edx
// 006c204e  83c108               add ecx, 8
// 006c2051  51                   push ecx
// 006c2052  50                   push eax
// 006c2053  56                   push esi
// 006c2054  57                   push edi
// 006c2055  e856ffffff           call 0x6c1fb0
// 006c205a  8d0c76               lea ecx, [esi + esi*2]
// 006c205d  83c418               add esp, 0x18
// 006c2060  8d04cf               lea eax, [edi + ecx*8]
// 006c2063  5f                   pop edi
// 006c2064  5e                   pop esi
// 006c2065  59                   pop ecx
// 006c2066  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
