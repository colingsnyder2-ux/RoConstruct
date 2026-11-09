// from server: 100% by auto
// roc 2010-06 008d6590  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6590
//
// 008d6590  51                   push ecx
// 008d6591  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d6595  56                   push esi
// 008d6596  8b742410             mov esi, dword ptr [esp + 0x10]
// 008d659a  57                   push edi
// 008d659b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008d659f  c644240800           mov byte ptr [esp + 8], 0
// 008d65a4  8b442408             mov eax, dword ptr [esp + 8]
// 008d65a8  50                   push eax
// 008d65a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d65ad  52                   push edx
// 008d65ae  83c108               add ecx, 8
// 008d65b1  51                   push ecx
// 008d65b2  50                   push eax
// 008d65b3  56                   push esi
// 008d65b4  57                   push edi
// 008d65b5  e8b6fbffff           call 0x8d6170
// 008d65ba  8d0c76               lea ecx, [esi + esi*2]
// 008d65bd  83c418               add esp, 0x18
// 008d65c0  8d04cf               lea eax, [edi + ecx*8]
// 008d65c3  5f                   pop edi
// 008d65c4  5e                   pop esi
// 008d65c5  59                   pop ecx
// 008d65c6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
