// from server: 100% by auto
// roc 2009-06 0048c8b0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c8b0
//
// 0048c8b0  51                   push ecx
// 0048c8b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048c8b5  56                   push esi
// 0048c8b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048c8ba  57                   push edi
// 0048c8bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0048c8bf  c644240800           mov byte ptr [esp + 8], 0
// 0048c8c4  8b442408             mov eax, dword ptr [esp + 8]
// 0048c8c8  50                   push eax
// 0048c8c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048c8cd  52                   push edx
// 0048c8ce  83c108               add ecx, 8
// 0048c8d1  51                   push ecx
// 0048c8d2  50                   push eax
// 0048c8d3  56                   push esi
// 0048c8d4  57                   push edi
// 0048c8d5  e836fdffff           call 0x48c610
// 0048c8da  8bc6                 mov eax, esi
// 0048c8dc  83c418               add esp, 0x18
// 0048c8df  c1e005               shl eax, 5
// 0048c8e2  03c7                 add eax, edi
// 0048c8e4  5f                   pop edi
// 0048c8e5  5e                   pop esi
// 0048c8e6  59                   pop ecx
// 0048c8e7  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
