// from server: 100% by auto
// roc 2009-12 004a2b30  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2b30
//
// 004a2b30  51                   push ecx
// 004a2b31  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2b35  56                   push esi
// 004a2b36  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2b3a  57                   push edi
// 004a2b3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2b3f  c644240800           mov byte ptr [esp + 8], 0
// 004a2b44  8b442408             mov eax, dword ptr [esp + 8]
// 004a2b48  50                   push eax
// 004a2b49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2b4d  52                   push edx
// 004a2b4e  83c108               add ecx, 8
// 004a2b51  51                   push ecx
// 004a2b52  50                   push eax
// 004a2b53  56                   push esi
// 004a2b54  57                   push edi
// 004a2b55  e826d5ffff           call 0x4a0080
// 004a2b5a  8d0476               lea eax, [esi + esi*2]
// 004a2b5d  83c418               add esp, 0x18
// 004a2b60  c1e004               shl eax, 4
// 004a2b63  03c7                 add eax, edi
// 004a2b65  5f                   pop edi
// 004a2b66  5e                   pop esi
// 004a2b67  59                   pop ecx
// 004a2b68  c20c00               ret 0xc
// standard library vector<pod48> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
