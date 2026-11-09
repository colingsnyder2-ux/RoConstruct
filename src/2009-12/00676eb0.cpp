// from server: 100% by auto
// roc 2009-12 00676eb0  unit: RBX::GlobalSettings  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00676eb0
//
// 00676eb0  56                   push esi
// 00676eb1  8bf1                 mov esi, ecx
// 00676eb3  833e00               cmp dword ptr [esi], 0
// 00676eb6  57                   push edi
// 00676eb7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00676ebd  7502                 jne 0x676ec1
// 00676ebf  ffd7                 call edi
// 00676ec1  8b4604               mov eax, dword ptr [esi + 4]
// 00676ec4  80781900             cmp byte ptr [eax + 0x19], 0
// 00676ec8  7411                 je 0x676edb
// 00676eca  8b4008               mov eax, dword ptr [eax + 8]
// 00676ecd  894604               mov dword ptr [esi + 4], eax
// 00676ed0  80781900             cmp byte ptr [eax + 0x19], 0
// 00676ed4  745b                 je 0x676f31
// 00676ed6  ffd7                 call edi
// 00676ed8  5f                   pop edi
// 00676ed9  5e                   pop esi
// 00676eda  c3                   ret 
// 00676edb  8b08                 mov ecx, dword ptr [eax]
// 00676edd  80791900             cmp byte ptr [ecx + 0x19], 0
// 00676ee1  751e                 jne 0x676f01
// 00676ee3  8b4108               mov eax, dword ptr [ecx + 8]
// 00676ee6  80781900             cmp byte ptr [eax + 0x19], 0
// 00676eea  750f                 jne 0x676efb
// 00676eec  8d642400             lea esp, [esp]
// 00676ef0  8bc8                 mov ecx, eax
// 00676ef2  8b4108               mov eax, dword ptr [ecx + 8]
// 00676ef5  80781900             cmp byte ptr [eax + 0x19], 0
// 00676ef9  74f5                 je 0x676ef0
// 00676efb  5f                   pop edi
// 00676efc  894e04               mov dword ptr [esi + 4], ecx
// 00676eff  5e                   pop esi
// 00676f00  c3                   ret 
// 00676f01  8b4004               mov eax, dword ptr [eax + 4]
// 00676f04  80781900             cmp byte ptr [eax + 0x19], 0
// 00676f08  751b                 jne 0x676f25
// 00676f0a  8d9b00000000         lea ebx, [ebx]
// 00676f10  8b4e04               mov ecx, dword ptr [esi + 4]
// 00676f13  3b08                 cmp ecx, dword ptr [eax]
// 00676f15  750e                 jne 0x676f25
// 00676f17  894604               mov dword ptr [esi + 4], eax
// 00676f1a  8bd0                 mov edx, eax
// 00676f1c  8b4204               mov eax, dword ptr [edx + 4]
// 00676f1f  80781900             cmp byte ptr [eax + 0x19], 0
// 00676f23  74eb                 je 0x676f10
// 00676f25  8b4e04               mov ecx, dword ptr [esi + 4]
// 00676f28  80791900             cmp byte ptr [ecx + 0x19], 0
// 00676f2c  75a8                 jne 0x676ed6
// 00676f2e  894604               mov dword ptr [esi + 4], eax
// 00676f31  5f                   pop edi
// 00676f32  5e                   pop esi
// 00676f33  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
