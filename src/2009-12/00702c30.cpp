// from server: 100% by auto
// roc 2009-12 00702c30  unit: RBX::Assembly  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702c30
//
// 00702c30  56                   push esi
// 00702c31  8bf1                 mov esi, ecx
// 00702c33  833e00               cmp dword ptr [esi], 0
// 00702c36  57                   push edi
// 00702c37  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00702c3d  7502                 jne 0x702c41
// 00702c3f  ffd7                 call edi
// 00702c41  8b4604               mov eax, dword ptr [esi + 4]
// 00702c44  80785100             cmp byte ptr [eax + 0x51], 0
// 00702c48  7405                 je 0x702c4f
// 00702c4a  ffd7                 call edi
// 00702c4c  5f                   pop edi
// 00702c4d  5e                   pop esi
// 00702c4e  c3                   ret 
// 00702c4f  8b4808               mov ecx, dword ptr [eax + 8]
// 00702c52  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702c56  7518                 jne 0x702c70
// 00702c58  8b01                 mov eax, dword ptr [ecx]
// 00702c5a  80785100             cmp byte ptr [eax + 0x51], 0
// 00702c5e  750a                 jne 0x702c6a
// 00702c60  8bc8                 mov ecx, eax
// 00702c62  8b01                 mov eax, dword ptr [ecx]
// 00702c64  80785100             cmp byte ptr [eax + 0x51], 0
// 00702c68  74f6                 je 0x702c60
// 00702c6a  5f                   pop edi
// 00702c6b  894e04               mov dword ptr [esi + 4], ecx
// 00702c6e  5e                   pop esi
// 00702c6f  c3                   ret 
// 00702c70  8b4004               mov eax, dword ptr [eax + 4]
// 00702c73  80785100             cmp byte ptr [eax + 0x51], 0
// 00702c77  751d                 jne 0x702c96
// 00702c79  8da42400000000       lea esp, [esp]
// 00702c80  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702c83  3b4808               cmp ecx, dword ptr [eax + 8]
// 00702c86  750e                 jne 0x702c96
// 00702c88  894604               mov dword ptr [esi + 4], eax
// 00702c8b  8bd0                 mov edx, eax
// 00702c8d  8b4204               mov eax, dword ptr [edx + 4]
// 00702c90  80785100             cmp byte ptr [eax + 0x51], 0
// 00702c94  74ea                 je 0x702c80
// 00702c96  5f                   pop edi
// 00702c97  894604               mov dword ptr [esi + 4], eax
// 00702c9a  5e                   pop esi
// 00702c9b  c3                   ret 
// standard library map_int<pod64> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
