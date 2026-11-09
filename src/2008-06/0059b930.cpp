// from server: 100% by auto
// roc 2008-06 0059b930  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059b930
//
// 0059b930  51                   push ecx
// 0059b931  8b542410             mov edx, dword ptr [esp + 0x10]
// 0059b935  56                   push esi
// 0059b936  8b742410             mov esi, dword ptr [esp + 0x10]
// 0059b93a  57                   push edi
// 0059b93b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0059b93f  c644240800           mov byte ptr [esp + 8], 0
// 0059b944  8b442408             mov eax, dword ptr [esp + 8]
// 0059b948  50                   push eax
// 0059b949  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0059b94d  52                   push edx
// 0059b94e  83c108               add ecx, 8
// 0059b951  51                   push ecx
// 0059b952  50                   push eax
// 0059b953  56                   push esi
// 0059b954  57                   push edi
// 0059b955  e836fbffff           call 0x59b490
// 0059b95a  83c418               add esp, 0x18
// 0059b95d  8d04f7               lea eax, [edi + esi*8]
// 0059b960  5f                   pop edi
// 0059b961  5e                   pop esi
// 0059b962  59                   pop ecx
// 0059b963  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
