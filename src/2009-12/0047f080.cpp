// from server: 100% by auto
// roc 2009-12 0047f080  unit: Ogre::VRbxFont::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f080
//
// 0047f080  56                   push esi
// 0047f081  8bf1                 mov esi, ecx
// 0047f083  833e00               cmp dword ptr [esi], 0
// 0047f086  57                   push edi
// 0047f087  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0047f08d  7502                 jne 0x47f091
// 0047f08f  ffd7                 call edi
// 0047f091  8b4604               mov eax, dword ptr [esi + 4]
// 0047f094  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f098  7405                 je 0x47f09f
// 0047f09a  ffd7                 call edi
// 0047f09c  5f                   pop edi
// 0047f09d  5e                   pop esi
// 0047f09e  c3                   ret 
// 0047f09f  8b4808               mov ecx, dword ptr [eax + 8]
// 0047f0a2  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047f0a6  7518                 jne 0x47f0c0
// 0047f0a8  8b01                 mov eax, dword ptr [ecx]
// 0047f0aa  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f0ae  750a                 jne 0x47f0ba
// 0047f0b0  8bc8                 mov ecx, eax
// 0047f0b2  8b01                 mov eax, dword ptr [ecx]
// 0047f0b4  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f0b8  74f6                 je 0x47f0b0
// 0047f0ba  5f                   pop edi
// 0047f0bb  894e04               mov dword ptr [esi + 4], ecx
// 0047f0be  5e                   pop esi
// 0047f0bf  c3                   ret 
// 0047f0c0  8b4004               mov eax, dword ptr [eax + 4]
// 0047f0c3  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f0c7  751d                 jne 0x47f0e6
// 0047f0c9  8da42400000000       lea esp, [esp]
// 0047f0d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047f0d3  3b4808               cmp ecx, dword ptr [eax + 8]
// 0047f0d6  750e                 jne 0x47f0e6
// 0047f0d8  894604               mov dword ptr [esi + 4], eax
// 0047f0db  8bd0                 mov edx, eax
// 0047f0dd  8b4204               mov eax, dword ptr [edx + 4]
// 0047f0e0  80783900             cmp byte ptr [eax + 0x39], 0
// 0047f0e4  74ea                 je 0x47f0d0
// 0047f0e6  5f                   pop edi
// 0047f0e7  894604               mov dword ptr [esi + 4], eax
// 0047f0ea  5e                   pop esi
// 0047f0eb  c3                   ret 
// standard library map_int<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
