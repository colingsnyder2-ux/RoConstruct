// from server: 100% by auto
// roc 2007-08 005c4f70  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c4f70
//
// 005c4f70  51                   push ecx
// 005c4f71  8b542410             mov edx, dword ptr [esp + 0x10]
// 005c4f75  56                   push esi
// 005c4f76  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c4f7a  57                   push edi
// 005c4f7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c4f7f  c644240800           mov byte ptr [esp + 8], 0
// 005c4f84  8b442408             mov eax, dword ptr [esp + 8]
// 005c4f88  50                   push eax
// 005c4f89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c4f8d  52                   push edx
// 005c4f8e  51                   push ecx
// 005c4f8f  50                   push eax
// 005c4f90  56                   push esi
// 005c4f91  57                   push edi
// 005c4f92  e839ffffff           call 0x5c4ed0
// 005c4f97  8bc6                 mov eax, esi
// 005c4f99  83c418               add esp, 0x18
// 005c4f9c  c1e004               shl eax, 4
// 005c4f9f  03c7                 add eax, edi
// 005c4fa1  5f                   pop edi
// 005c4fa2  5e                   pop esi
// 005c4fa3  59                   pop ecx
// 005c4fa4  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
