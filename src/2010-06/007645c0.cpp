// from server: 100% by auto
// roc 2010-06 007645c0  unit: RBX::GuiLayerCollector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007645c0
//
// 007645c0  51                   push ecx
// 007645c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007645c5  56                   push esi
// 007645c6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007645ca  57                   push edi
// 007645cb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007645cf  c644240800           mov byte ptr [esp + 8], 0
// 007645d4  8b442408             mov eax, dword ptr [esp + 8]
// 007645d8  50                   push eax
// 007645d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007645dd  52                   push edx
// 007645de  83c108               add ecx, 8
// 007645e1  51                   push ecx
// 007645e2  50                   push eax
// 007645e3  56                   push esi
// 007645e4  57                   push edi
// 007645e5  e8f6fcffff           call 0x7642e0
// 007645ea  8d0c76               lea ecx, [esi + esi*2]
// 007645ed  83c418               add esp, 0x18
// 007645f0  8d04cf               lea eax, [edi + ecx*8]
// 007645f3  5f                   pop edi
// 007645f4  5e                   pop esi
// 007645f5  59                   pop ecx
// 007645f6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
