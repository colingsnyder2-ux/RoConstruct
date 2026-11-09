// from server: 100% by auto
// roc 2010-06 00731290  unit: lua_exception  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731290
//
// 00731290  51                   push ecx
// 00731291  8b542410             mov edx, dword ptr [esp + 0x10]
// 00731295  56                   push esi
// 00731296  8b742410             mov esi, dword ptr [esp + 0x10]
// 0073129a  57                   push edi
// 0073129b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0073129f  c644240800           mov byte ptr [esp + 8], 0
// 007312a4  8b442408             mov eax, dword ptr [esp + 8]
// 007312a8  50                   push eax
// 007312a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007312ad  52                   push edx
// 007312ae  83c108               add ecx, 8
// 007312b1  51                   push ecx
// 007312b2  50                   push eax
// 007312b3  56                   push esi
// 007312b4  57                   push edi
// 007312b5  e8a6feffff           call 0x731160
// 007312ba  8d0c76               lea ecx, [esi + esi*2]
// 007312bd  83c418               add esp, 0x18
// 007312c0  8d04cf               lea eax, [edi + ecx*8]
// 007312c3  5f                   pop edi
// 007312c4  5e                   pop esi
// 007312c5  59                   pop ecx
// 007312c6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
