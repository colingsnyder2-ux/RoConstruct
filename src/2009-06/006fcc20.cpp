// from server: 100% by auto
// roc 2009-06 006fcc20  unit: Ogre::VRbxFont::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fcc20
//
// 006fcc20  56                   push esi
// 006fcc21  8bf1                 mov esi, ecx
// 006fcc23  833e00               cmp dword ptr [esi], 0
// 006fcc26  57                   push edi
// 006fcc27  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006fcc2d  7502                 jne 0x6fcc31
// 006fcc2f  ffd7                 call edi
// 006fcc31  8b4604               mov eax, dword ptr [esi + 4]
// 006fcc34  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc38  7405                 je 0x6fcc3f
// 006fcc3a  ffd7                 call edi
// 006fcc3c  5f                   pop edi
// 006fcc3d  5e                   pop esi
// 006fcc3e  c3                   ret 
// 006fcc3f  8b4808               mov ecx, dword ptr [eax + 8]
// 006fcc42  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fcc46  7518                 jne 0x6fcc60
// 006fcc48  8b01                 mov eax, dword ptr [ecx]
// 006fcc4a  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc4e  750a                 jne 0x6fcc5a
// 006fcc50  8bc8                 mov ecx, eax
// 006fcc52  8b01                 mov eax, dword ptr [ecx]
// 006fcc54  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc58  74f6                 je 0x6fcc50
// 006fcc5a  5f                   pop edi
// 006fcc5b  894e04               mov dword ptr [esi + 4], ecx
// 006fcc5e  5e                   pop esi
// 006fcc5f  c3                   ret 
// 006fcc60  8b4004               mov eax, dword ptr [eax + 4]
// 006fcc63  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc67  751d                 jne 0x6fcc86
// 006fcc69  8da42400000000       lea esp, [esp]
// 006fcc70  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fcc73  3b4808               cmp ecx, dword ptr [eax + 8]
// 006fcc76  750e                 jne 0x6fcc86
// 006fcc78  894604               mov dword ptr [esi + 4], eax
// 006fcc7b  8bd0                 mov edx, eax
// 006fcc7d  8b4204               mov eax, dword ptr [edx + 4]
// 006fcc80  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc84  74ea                 je 0x6fcc70
// 006fcc86  5f                   pop edi
// 006fcc87  894604               mov dword ptr [esi + 4], eax
// 006fcc8a  5e                   pop esi
// 006fcc8b  c3                   ret 
// standard library set<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
