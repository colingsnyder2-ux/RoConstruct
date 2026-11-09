// from server: 100% by auto
// roc 2010-06 008c6df0  unit: Ogre::VRbxFont::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6df0
//
// 008c6df0  56                   push esi
// 008c6df1  8bf1                 mov esi, ecx
// 008c6df3  833e00               cmp dword ptr [esi], 0
// 008c6df6  57                   push edi
// 008c6df7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 008c6dfd  7502                 jne 0x8c6e01
// 008c6dff  ffd7                 call edi
// 008c6e01  8b4604               mov eax, dword ptr [esi + 4]
// 008c6e04  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6e08  7405                 je 0x8c6e0f
// 008c6e0a  ffd7                 call edi
// 008c6e0c  5f                   pop edi
// 008c6e0d  5e                   pop esi
// 008c6e0e  c3                   ret 
// 008c6e0f  8b4808               mov ecx, dword ptr [eax + 8]
// 008c6e12  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c6e16  7518                 jne 0x8c6e30
// 008c6e18  8b01                 mov eax, dword ptr [ecx]
// 008c6e1a  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6e1e  750a                 jne 0x8c6e2a
// 008c6e20  8bc8                 mov ecx, eax
// 008c6e22  8b01                 mov eax, dword ptr [ecx]
// 008c6e24  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6e28  74f6                 je 0x8c6e20
// 008c6e2a  5f                   pop edi
// 008c6e2b  894e04               mov dword ptr [esi + 4], ecx
// 008c6e2e  5e                   pop esi
// 008c6e2f  c3                   ret 
// 008c6e30  8b4004               mov eax, dword ptr [eax + 4]
// 008c6e33  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6e37  751d                 jne 0x8c6e56
// 008c6e39  8da42400000000       lea esp, [esp]
// 008c6e40  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c6e43  3b4808               cmp ecx, dword ptr [eax + 8]
// 008c6e46  750e                 jne 0x8c6e56
// 008c6e48  894604               mov dword ptr [esi + 4], eax
// 008c6e4b  8bd0                 mov edx, eax
// 008c6e4d  8b4204               mov eax, dword ptr [edx + 4]
// 008c6e50  80783900             cmp byte ptr [eax + 0x39], 0
// 008c6e54  74ea                 je 0x8c6e40
// 008c6e56  5f                   pop edi
// 008c6e57  894604               mov dword ptr [esi + 4], eax
// 008c6e5a  5e                   pop esi
// 008c6e5b  c3                   ret 
// standard library map_int<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
