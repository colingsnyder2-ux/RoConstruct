// from server: 100% by auto
// roc 2010-06 008f66d0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f66d0
//
// 008f66d0  51                   push ecx
// 008f66d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f66d5  56                   push esi
// 008f66d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 008f66da  57                   push edi
// 008f66db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f66df  c644240800           mov byte ptr [esp + 8], 0
// 008f66e4  8b442408             mov eax, dword ptr [esp + 8]
// 008f66e8  50                   push eax
// 008f66e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f66ed  52                   push edx
// 008f66ee  83c108               add ecx, 8
// 008f66f1  51                   push ecx
// 008f66f2  50                   push eax
// 008f66f3  56                   push esi
// 008f66f4  57                   push edi
// 008f66f5  e866c1ffff           call 0x8f2860
// 008f66fa  8d0cf6               lea ecx, [esi + esi*8]
// 008f66fd  83c418               add esp, 0x18
// 008f6700  8d048f               lea eax, [edi + ecx*4]
// 008f6703  5f                   pop edi
// 008f6704  5e                   pop esi
// 008f6705  59                   pop ecx
// 008f6706  c20c00               ret 0xc
// standard library vector<pod36> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
