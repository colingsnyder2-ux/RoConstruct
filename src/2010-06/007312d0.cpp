// from server: 100% by auto
// roc 2010-06 007312d0  unit: lua_exception  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007312d0
//
// 007312d0  51                   push ecx
// 007312d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007312d5  56                   push esi
// 007312d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007312da  57                   push edi
// 007312db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007312df  c644240800           mov byte ptr [esp + 8], 0
// 007312e4  8b442408             mov eax, dword ptr [esp + 8]
// 007312e8  50                   push eax
// 007312e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007312ed  52                   push edx
// 007312ee  83c108               add ecx, 8
// 007312f1  51                   push ecx
// 007312f2  50                   push eax
// 007312f3  56                   push esi
// 007312f4  57                   push edi
// 007312f5  e8b6feffff           call 0x7311b0
// 007312fa  8d0c76               lea ecx, [esi + esi*2]
// 007312fd  83c418               add esp, 0x18
// 00731300  8d04cf               lea eax, [edi + ecx*8]
// 00731303  5f                   pop edi
// 00731304  5e                   pop esi
// 00731305  59                   pop ecx
// 00731306  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
