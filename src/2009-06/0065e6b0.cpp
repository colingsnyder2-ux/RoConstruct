// from server: 100% by auto
// roc 2009-06 0065e6b0  unit: G3D::VColor3::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065e6b0
//
// 0065e6b0  51                   push ecx
// 0065e6b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065e6b5  56                   push esi
// 0065e6b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065e6ba  57                   push edi
// 0065e6bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065e6bf  c644240800           mov byte ptr [esp + 8], 0
// 0065e6c4  8b442408             mov eax, dword ptr [esp + 8]
// 0065e6c8  50                   push eax
// 0065e6c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065e6cd  52                   push edx
// 0065e6ce  83c108               add ecx, 8
// 0065e6d1  51                   push ecx
// 0065e6d2  50                   push eax
// 0065e6d3  56                   push esi
// 0065e6d4  57                   push edi
// 0065e6d5  e8b6f2ffff           call 0x65d990
// 0065e6da  83c418               add esp, 0x18
// 0065e6dd  8d04f7               lea eax, [edi + esi*8]
// 0065e6e0  5f                   pop edi
// 0065e6e1  5e                   pop esi
// 0065e6e2  59                   pop ecx
// 0065e6e3  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
