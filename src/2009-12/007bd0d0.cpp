// from server: 100% by auto
// roc 2009-12 007bd0d0  unit: RBX::GuiLayerCollector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bd0d0
//
// 007bd0d0  51                   push ecx
// 007bd0d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bd0d5  56                   push esi
// 007bd0d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007bd0da  57                   push edi
// 007bd0db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007bd0df  c644240800           mov byte ptr [esp + 8], 0
// 007bd0e4  8b442408             mov eax, dword ptr [esp + 8]
// 007bd0e8  50                   push eax
// 007bd0e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bd0ed  52                   push edx
// 007bd0ee  83c108               add ecx, 8
// 007bd0f1  51                   push ecx
// 007bd0f2  50                   push eax
// 007bd0f3  56                   push esi
// 007bd0f4  57                   push edi
// 007bd0f5  e8f6fcffff           call 0x7bcdf0
// 007bd0fa  8d0c76               lea ecx, [esi + esi*2]
// 007bd0fd  83c418               add esp, 0x18
// 007bd100  8d04cf               lea eax, [edi + ecx*8]
// 007bd103  5f                   pop edi
// 007bd104  5e                   pop esi
// 007bd105  59                   pop ecx
// 007bd106  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
