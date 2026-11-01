// from server: 100% by auto
// roc 2009-12 004a2a70  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2a70
//
// 004a2a70  51                   push ecx
// 004a2a71  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2a75  56                   push esi
// 004a2a76  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2a7a  57                   push edi
// 004a2a7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2a7f  c644240800           mov byte ptr [esp + 8], 0
// 004a2a84  8b442408             mov eax, dword ptr [esp + 8]
// 004a2a88  50                   push eax
// 004a2a89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2a8d  52                   push edx
// 004a2a8e  83c108               add ecx, 8
// 004a2a91  51                   push ecx
// 004a2a92  50                   push eax
// 004a2a93  56                   push esi
// 004a2a94  57                   push edi
// 004a2a95  e8a6c0ffff           call 0x49eb40
// 004a2a9a  8d0cf6               lea ecx, [esi + esi*8]
// 004a2a9d  83c418               add esp, 0x18
// 004a2aa0  8d048f               lea eax, [edi + ecx*4]
// 004a2aa3  5f                   pop edi
// 004a2aa4  5e                   pop esi
// 004a2aa5  59                   pop ecx
// 004a2aa6  c20c00               ret 0xc
// standard library vector<pod36> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
