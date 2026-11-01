// from server: 100% by auto
// roc 2009-12 005cd2d0  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd2d0
//
// 005cd2d0  56                   push esi
// 005cd2d1  8bf1                 mov esi, ecx
// 005cd2d3  833e00               cmp dword ptr [esi], 0
// 005cd2d6  57                   push edi
// 005cd2d7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 005cd2dd  7502                 jne 0x5cd2e1
// 005cd2df  ffd7                 call edi
// 005cd2e1  8b4604               mov eax, dword ptr [esi + 4]
// 005cd2e4  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd2e8  7411                 je 0x5cd2fb
// 005cd2ea  8b4008               mov eax, dword ptr [eax + 8]
// 005cd2ed  894604               mov dword ptr [esi + 4], eax
// 005cd2f0  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd2f4  745b                 je 0x5cd351
// 005cd2f6  ffd7                 call edi
// 005cd2f8  5f                   pop edi
// 005cd2f9  5e                   pop esi
// 005cd2fa  c3                   ret 
// 005cd2fb  8b08                 mov ecx, dword ptr [eax]
// 005cd2fd  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cd301  751e                 jne 0x5cd321
// 005cd303  8b4108               mov eax, dword ptr [ecx + 8]
// 005cd306  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd30a  750f                 jne 0x5cd31b
// 005cd30c  8d642400             lea esp, [esp]
// 005cd310  8bc8                 mov ecx, eax
// 005cd312  8b4108               mov eax, dword ptr [ecx + 8]
// 005cd315  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd319  74f5                 je 0x5cd310
// 005cd31b  5f                   pop edi
// 005cd31c  894e04               mov dword ptr [esi + 4], ecx
// 005cd31f  5e                   pop esi
// 005cd320  c3                   ret 
// 005cd321  8b4004               mov eax, dword ptr [eax + 4]
// 005cd324  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd328  751b                 jne 0x5cd345
// 005cd32a  8d9b00000000         lea ebx, [ebx]
// 005cd330  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cd333  3b08                 cmp ecx, dword ptr [eax]
// 005cd335  750e                 jne 0x5cd345
// 005cd337  894604               mov dword ptr [esi + 4], eax
// 005cd33a  8bd0                 mov edx, eax
// 005cd33c  8b4204               mov eax, dword ptr [edx + 4]
// 005cd33f  80782100             cmp byte ptr [eax + 0x21], 0
// 005cd343  74eb                 je 0x5cd330
// 005cd345  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cd348  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cd34c  75a8                 jne 0x5cd2f6
// 005cd34e  894604               mov dword ptr [esi + 4], eax
// 005cd351  5f                   pop edi
// 005cd352  5e                   pop esi
// 005cd353  c3                   ret 
// standard library map_int<double> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HNU?$less@H@std@@V?$allocator@U?$pair@$$CBHN@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<double>
typedef double E;
#include <map>
template class std::map<int, E>;
