// from server: 100% by auto
// roc 2009-12 0048cb30  unit: G3D::Shader  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048cb30
//
// 0048cb30  51                   push ecx
// 0048cb31  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048cb35  56                   push esi
// 0048cb36  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048cb3a  57                   push edi
// 0048cb3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048cb3f  c644240800           mov byte ptr [esp + 8], 0
// 0048cb44  8b442408             mov eax, dword ptr [esp + 8]
// 0048cb48  50                   push eax
// 0048cb49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cb4d  52                   push edx
// 0048cb4e  83c108               add ecx, 8
// 0048cb51  51                   push ecx
// 0048cb52  50                   push eax
// 0048cb53  56                   push esi
// 0048cb54  57                   push edi
// 0048cb55  e816feffff           call 0x48c970
// 0048cb5a  8d0c76               lea ecx, [esi + esi*2]
// 0048cb5d  83c418               add esp, 0x18
// 0048cb60  8d04cf               lea eax, [edi + ecx*8]
// 0048cb63  5f                   pop edi
// 0048cb64  5e                   pop esi
// 0048cb65  59                   pop ecx
// 0048cb66  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
