// from server: 100% by auto
// roc 2010-06 008f5b30  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5b30
//
// 008f5b30  51                   push ecx
// 008f5b31  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f5b35  56                   push esi
// 008f5b36  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f5b3a  57                   push edi
// 008f5b3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f5b3f  c644240800           mov byte ptr [esp + 8], 0
// 008f5b44  8b442408             mov eax, dword ptr [esp + 8]
// 008f5b48  50                   push eax
// 008f5b49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f5b4d  52                   push edx
// 008f5b4e  83c108               add ecx, 8
// 008f5b51  51                   push ecx
// 008f5b52  50                   push eax
// 008f5b53  56                   push esi
// 008f5b54  57                   push edi
// 008f5b55  e826ffffff           call 0x8f5a80
// 008f5b5a  8bc6                 mov eax, esi
// 008f5b5c  83c418               add esp, 0x18
// 008f5b5f  c1e005               shl eax, 5
// 008f5b62  03c7                 add eax, edi
// 008f5b64  5f                   pop edi
// 008f5b65  5e                   pop esi
// 008f5b66  59                   pop ecx
// 008f5b67  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
