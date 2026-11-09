// from server: 100% by auto
// roc 2009-12 0048caf0  unit: G3D::Shader  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048caf0
//
// 0048caf0  51                   push ecx
// 0048caf1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048caf5  56                   push esi
// 0048caf6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048cafa  57                   push edi
// 0048cafb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048caff  c644240800           mov byte ptr [esp + 8], 0
// 0048cb04  8b442408             mov eax, dword ptr [esp + 8]
// 0048cb08  50                   push eax
// 0048cb09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cb0d  52                   push edx
// 0048cb0e  83c108               add ecx, 8
// 0048cb11  51                   push ecx
// 0048cb12  50                   push eax
// 0048cb13  56                   push esi
// 0048cb14  57                   push edi
// 0048cb15  e816feffff           call 0x48c930
// 0048cb1a  8bc6                 mov eax, esi
// 0048cb1c  83c418               add esp, 0x18
// 0048cb1f  c1e004               shl eax, 4
// 0048cb22  03c7                 add eax, edi
// 0048cb24  5f                   pop edi
// 0048cb25  5e                   pop esi
// 0048cb26  59                   pop ecx
// 0048cb27  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
