// from server: 100% by auto
// roc 2010-06 008f6790  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6790
//
// 008f6790  51                   push ecx
// 008f6791  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6795  56                   push esi
// 008f6796  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f679a  57                   push edi
// 008f679b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f679f  c644240800           mov byte ptr [esp + 8], 0
// 008f67a4  8b442408             mov eax, dword ptr [esp + 8]
// 008f67a8  50                   push eax
// 008f67a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f67ad  52                   push edx
// 008f67ae  83c108               add ecx, 8
// 008f67b1  51                   push ecx
// 008f67b2  50                   push eax
// 008f67b3  56                   push esi
// 008f67b4  57                   push edi
// 008f67b5  e8e6d5ffff           call 0x8f3da0
// 008f67ba  8d0476               lea eax, [esi + esi*2]
// 008f67bd  83c418               add esp, 0x18
// 008f67c0  c1e004               shl eax, 4
// 008f67c3  03c7                 add eax, edi
// 008f67c5  5f                   pop edi
// 008f67c6  5e                   pop esi
// 008f67c7  59                   pop ecx
// 008f67c8  c20c00               ret 0xc
// standard library vector<pod48> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
