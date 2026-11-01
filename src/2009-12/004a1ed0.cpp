// from server: 100% by auto
// roc 2009-12 004a1ed0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1ed0
//
// 004a1ed0  51                   push ecx
// 004a1ed1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a1ed5  56                   push esi
// 004a1ed6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a1eda  57                   push edi
// 004a1edb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a1edf  c644240800           mov byte ptr [esp + 8], 0
// 004a1ee4  8b442408             mov eax, dword ptr [esp + 8]
// 004a1ee8  50                   push eax
// 004a1ee9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a1eed  52                   push edx
// 004a1eee  83c108               add ecx, 8
// 004a1ef1  51                   push ecx
// 004a1ef2  50                   push eax
// 004a1ef3  56                   push esi
// 004a1ef4  57                   push edi
// 004a1ef5  e826ffffff           call 0x4a1e20
// 004a1efa  8bc6                 mov eax, esi
// 004a1efc  83c418               add esp, 0x18
// 004a1eff  c1e005               shl eax, 5
// 004a1f02  03c7                 add eax, edi
// 004a1f04  5f                   pop edi
// 004a1f05  5e                   pop esi
// 004a1f06  59                   pop ecx
// 004a1f07  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
