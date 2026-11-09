// from server: 100% by auto
// roc 2010-06 008d2e20  unit: Ogre::VisualEngine  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2e20
//
// 008d2e20  51                   push ecx
// 008d2e21  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d2e25  56                   push esi
// 008d2e26  8b742410             mov esi, dword ptr [esp + 0x10]
// 008d2e2a  57                   push edi
// 008d2e2b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008d2e2f  c644240800           mov byte ptr [esp + 8], 0
// 008d2e34  8b442408             mov eax, dword ptr [esp + 8]
// 008d2e38  50                   push eax
// 008d2e39  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d2e3d  52                   push edx
// 008d2e3e  83c108               add ecx, 8
// 008d2e41  51                   push ecx
// 008d2e42  50                   push eax
// 008d2e43  56                   push esi
// 008d2e44  57                   push edi
// 008d2e45  e8d6fdffff           call 0x8d2c20
// 008d2e4a  8bc6                 mov eax, esi
// 008d2e4c  83c418               add esp, 0x18
// 008d2e4f  c1e004               shl eax, 4
// 008d2e52  03c7                 add eax, edi
// 008d2e54  5f                   pop edi
// 008d2e55  5e                   pop esi
// 008d2e56  59                   pop ecx
// 008d2e57  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
