// from server: 100% by auto
// roc 2008-06 0068d2c0  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d2c0
//
// 0068d2c0  56                   push esi
// 0068d2c1  8bf1                 mov esi, ecx
// 0068d2c3  833e00               cmp dword ptr [esi], 0
// 0068d2c6  57                   push edi
// 0068d2c7  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068d2cd  7502                 jne 0x68d2d1
// 0068d2cf  ffd7                 call edi
// 0068d2d1  8b4604               mov eax, dword ptr [esi + 4]
// 0068d2d4  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d2d8  7411                 je 0x68d2eb
// 0068d2da  8b4008               mov eax, dword ptr [eax + 8]
// 0068d2dd  894604               mov dword ptr [esi + 4], eax
// 0068d2e0  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d2e4  745b                 je 0x68d341
// 0068d2e6  ffd7                 call edi
// 0068d2e8  5f                   pop edi
// 0068d2e9  5e                   pop esi
// 0068d2ea  c3                   ret 
// 0068d2eb  8b08                 mov ecx, dword ptr [eax]
// 0068d2ed  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d2f1  751e                 jne 0x68d311
// 0068d2f3  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d2f6  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d2fa  750f                 jne 0x68d30b
// 0068d2fc  8d642400             lea esp, [esp]
// 0068d300  8bc8                 mov ecx, eax
// 0068d302  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d305  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d309  74f5                 je 0x68d300
// 0068d30b  5f                   pop edi
// 0068d30c  894e04               mov dword ptr [esi + 4], ecx
// 0068d30f  5e                   pop esi
// 0068d310  c3                   ret 
// 0068d311  8b4004               mov eax, dword ptr [eax + 4]
// 0068d314  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d318  751b                 jne 0x68d335
// 0068d31a  8d9b00000000         lea ebx, [ebx]
// 0068d320  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d323  3b08                 cmp ecx, dword ptr [eax]
// 0068d325  750e                 jne 0x68d335
// 0068d327  894604               mov dword ptr [esi + 4], eax
// 0068d32a  8bd0                 mov edx, eax
// 0068d32c  8b4204               mov eax, dword ptr [edx + 4]
// 0068d32f  80783900             cmp byte ptr [eax + 0x39], 0
// 0068d333  74eb                 je 0x68d320
// 0068d335  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d338  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d33c  75a8                 jne 0x68d2e6
// 0068d33e  894604               mov dword ptr [esi + 4], eax
// 0068d341  5f                   pop edi
// 0068d342  5e                   pop esi
// 0068d343  c3                   ret 
// standard library map_int<pod40> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
