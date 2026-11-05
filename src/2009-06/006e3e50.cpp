// from server: 100% by auto
// roc 2009-06 006e3e50  unit: RBX::ScoreHud  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3e50
//
// 006e3e50  51                   push ecx
// 006e3e51  8b542410             mov edx, dword ptr [esp + 0x10]
// 006e3e55  56                   push esi
// 006e3e56  8b742410             mov esi, dword ptr [esp + 0x10]
// 006e3e5a  57                   push edi
// 006e3e5b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006e3e5f  c644240800           mov byte ptr [esp + 8], 0
// 006e3e64  8b442408             mov eax, dword ptr [esp + 8]
// 006e3e68  50                   push eax
// 006e3e69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e3e6d  52                   push edx
// 006e3e6e  83c108               add ecx, 8
// 006e3e71  51                   push ecx
// 006e3e72  50                   push eax
// 006e3e73  56                   push esi
// 006e3e74  57                   push edi
// 006e3e75  e806f0ffff           call 0x6e2e80
// 006e3e7a  8d0c76               lea ecx, [esi + esi*2]
// 006e3e7d  83c418               add esp, 0x18
// 006e3e80  8d04cf               lea eax, [edi + ecx*8]
// 006e3e83  5f                   pop edi
// 006e3e84  5e                   pop esi
// 006e3e85  59                   pop ecx
// 006e3e86  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
