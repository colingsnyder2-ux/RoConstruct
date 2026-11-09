// from server: 100% by auto
// roc 2009-12 005cd1d0  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd1d0
//
// 005cd1d0  56                   push esi
// 005cd1d1  8bf1                 mov esi, ecx
// 005cd1d3  833e00               cmp dword ptr [esi], 0
// 005cd1d6  57                   push edi
// 005cd1d7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 005cd1dd  7502                 jne 0x5cd1e1
// 005cd1df  ffd7                 call edi
// 005cd1e1  8b4604               mov eax, dword ptr [esi + 4]
// 005cd1e4  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd1e8  7411                 je 0x5cd1fb
// 005cd1ea  8b4008               mov eax, dword ptr [eax + 8]
// 005cd1ed  894604               mov dword ptr [esi + 4], eax
// 005cd1f0  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd1f4  745b                 je 0x5cd251
// 005cd1f6  ffd7                 call edi
// 005cd1f8  5f                   pop edi
// 005cd1f9  5e                   pop esi
// 005cd1fa  c3                   ret 
// 005cd1fb  8b08                 mov ecx, dword ptr [eax]
// 005cd1fd  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cd201  751e                 jne 0x5cd221
// 005cd203  8b4108               mov eax, dword ptr [ecx + 8]
// 005cd206  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd20a  750f                 jne 0x5cd21b
// 005cd20c  8d642400             lea esp, [esp]
// 005cd210  8bc8                 mov ecx, eax
// 005cd212  8b4108               mov eax, dword ptr [ecx + 8]
// 005cd215  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd219  74f5                 je 0x5cd210
// 005cd21b  5f                   pop edi
// 005cd21c  894e04               mov dword ptr [esi + 4], ecx
// 005cd21f  5e                   pop esi
// 005cd220  c3                   ret 
// 005cd221  8b4004               mov eax, dword ptr [eax + 4]
// 005cd224  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd228  751b                 jne 0x5cd245
// 005cd22a  8d9b00000000         lea ebx, [ebx]
// 005cd230  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cd233  3b08                 cmp ecx, dword ptr [eax]
// 005cd235  750e                 jne 0x5cd245
// 005cd237  894604               mov dword ptr [esi + 4], eax
// 005cd23a  8bd0                 mov edx, eax
// 005cd23c  8b4204               mov eax, dword ptr [edx + 4]
// 005cd23f  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd243  74eb                 je 0x5cd230
// 005cd245  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cd248  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cd24c  75a8                 jne 0x5cd1f6
// 005cd24e  894604               mov dword ptr [esi + 4], eax
// 005cd251  5f                   pop edi
// 005cd252  5e                   pop esi
// 005cd253  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
