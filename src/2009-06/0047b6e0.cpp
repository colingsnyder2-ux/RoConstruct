// from server: 100% by auto
// roc 2009-06 0047b6e0  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b6e0
//
// 0047b6e0  51                   push ecx
// 0047b6e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047b6e5  56                   push esi
// 0047b6e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0047b6ea  57                   push edi
// 0047b6eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0047b6ef  c644240800           mov byte ptr [esp + 8], 0
// 0047b6f4  8b442408             mov eax, dword ptr [esp + 8]
// 0047b6f8  50                   push eax
// 0047b6f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047b6fd  52                   push edx
// 0047b6fe  83c108               add ecx, 8
// 0047b701  51                   push ecx
// 0047b702  50                   push eax
// 0047b703  56                   push esi
// 0047b704  57                   push edi
// 0047b705  e846ffffff           call 0x47b650
// 0047b70a  8d0c76               lea ecx, [esi + esi*2]
// 0047b70d  83c418               add esp, 0x18
// 0047b710  8d048f               lea eax, [edi + ecx*4]
// 0047b713  5f                   pop edi
// 0047b714  5e                   pop esi
// 0047b715  59                   pop ecx
// 0047b716  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
