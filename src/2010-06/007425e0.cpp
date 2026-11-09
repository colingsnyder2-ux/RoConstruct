// from server: 100% by auto
// roc 2010-06 007425e0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007425e0
//
// 007425e0  51                   push ecx
// 007425e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007425e5  56                   push esi
// 007425e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007425ea  57                   push edi
// 007425eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007425ef  c644240800           mov byte ptr [esp + 8], 0
// 007425f4  8b442408             mov eax, dword ptr [esp + 8]
// 007425f8  50                   push eax
// 007425f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007425fd  52                   push edx
// 007425fe  83c108               add ecx, 8
// 00742601  51                   push ecx
// 00742602  50                   push eax
// 00742603  56                   push esi
// 00742604  57                   push edi
// 00742605  e876f8ffff           call 0x741e80
// 0074260a  8d0cb6               lea ecx, [esi + esi*4]
// 0074260d  83c418               add esp, 0x18
// 00742610  8d04cf               lea eax, [edi + ecx*8]
// 00742613  5f                   pop edi
// 00742614  5e                   pop esi
// 00742615  59                   pop ecx
// 00742616  c20c00               ret 0xc
// standard library vector<pod40> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
