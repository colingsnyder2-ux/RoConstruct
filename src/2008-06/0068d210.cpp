// from server: 100% by auto
// roc 2008-06 0068d210  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d210
//
// 0068d210  56                   push esi
// 0068d211  8bf1                 mov esi, ecx
// 0068d213  833e00               cmp dword ptr [esi], 0
// 0068d216  57                   push edi
// 0068d217  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068d21d  7502                 jne 0x68d221
// 0068d21f  ffd7                 call edi
// 0068d221  8b4604               mov eax, dword ptr [esi + 4]
// 0068d224  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d228  7405                 je 0x68d22f
// 0068d22a  ffd7                 call edi
// 0068d22c  5f                   pop edi
// 0068d22d  5e                   pop esi
// 0068d22e  c3                   ret 
// 0068d22f  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d232  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d236  7518                 jne 0x68d250
// 0068d238  8b01                 mov eax, dword ptr [ecx]
// 0068d23a  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d23e  750a                 jne 0x68d24a
// 0068d240  8bc8                 mov ecx, eax
// 0068d242  8b01                 mov eax, dword ptr [ecx]
// 0068d244  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d248  74f6                 je 0x68d240
// 0068d24a  5f                   pop edi
// 0068d24b  894e04               mov dword ptr [esi + 4], ecx
// 0068d24e  5e                   pop esi
// 0068d24f  c3                   ret 
// 0068d250  8b4004               mov eax, dword ptr [eax + 4]
// 0068d253  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d257  751d                 jne 0x68d276
// 0068d259  8da42400000000       lea esp, [esp]
// 0068d260  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d263  3b4808               cmp ecx, dword ptr [eax + 8]
// 0068d266  750e                 jne 0x68d276
// 0068d268  894604               mov dword ptr [esi + 4], eax
// 0068d26b  8bd0                 mov edx, eax
// 0068d26d  8b4204               mov eax, dword ptr [edx + 4]
// 0068d270  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d274  74ea                 je 0x68d260
// 0068d276  5f                   pop edi
// 0068d277  894604               mov dword ptr [esi + 4], eax
// 0068d27a  5e                   pop esi
// 0068d27b  c3                   ret 
// standard library map_int<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
