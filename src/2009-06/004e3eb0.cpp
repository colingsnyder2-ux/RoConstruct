// from server: 100% by auto
// roc 2009-06 004e3eb0  unit: RBX::Network::Replicator  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e3eb0
//
// 004e3eb0  56                   push esi
// 004e3eb1  8bf1                 mov esi, ecx
// 004e3eb3  833e00               cmp dword ptr [esi], 0
// 004e3eb6  57                   push edi
// 004e3eb7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 004e3ebd  7502                 jne 0x4e3ec1
// 004e3ebf  ffd7                 call edi
// 004e3ec1  8b4604               mov eax, dword ptr [esi + 4]
// 004e3ec4  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3ec8  7411                 je 0x4e3edb
// 004e3eca  8b4008               mov eax, dword ptr [eax + 8]
// 004e3ecd  894604               mov dword ptr [esi + 4], eax
// 004e3ed0  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3ed4  745b                 je 0x4e3f31
// 004e3ed6  ffd7                 call edi
// 004e3ed8  5f                   pop edi
// 004e3ed9  5e                   pop esi
// 004e3eda  c3                   ret 
// 004e3edb  8b08                 mov ecx, dword ptr [eax]
// 004e3edd  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e3ee1  751e                 jne 0x4e3f01
// 004e3ee3  8b4108               mov eax, dword ptr [ecx + 8]
// 004e3ee6  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3eea  750f                 jne 0x4e3efb
// 004e3eec  8d642400             lea esp, [esp]
// 004e3ef0  8bc8                 mov ecx, eax
// 004e3ef2  8b4108               mov eax, dword ptr [ecx + 8]
// 004e3ef5  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3ef9  74f5                 je 0x4e3ef0
// 004e3efb  5f                   pop edi
// 004e3efc  894e04               mov dword ptr [esi + 4], ecx
// 004e3eff  5e                   pop esi
// 004e3f00  c3                   ret 
// 004e3f01  8b4004               mov eax, dword ptr [eax + 4]
// 004e3f04  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3f08  751b                 jne 0x4e3f25
// 004e3f0a  8d9b00000000         lea ebx, [ebx]
// 004e3f10  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e3f13  3b08                 cmp ecx, dword ptr [eax]
// 004e3f15  750e                 jne 0x4e3f25
// 004e3f17  894604               mov dword ptr [esi + 4], eax
// 004e3f1a  8bd0                 mov edx, eax
// 004e3f1c  8b4204               mov eax, dword ptr [edx + 4]
// 004e3f1f  80781900             cmp byte ptr [eax + 0x19], 0
// 004e3f23  74eb                 je 0x4e3f10
// 004e3f25  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e3f28  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e3f2c  75a8                 jne 0x4e3ed6
// 004e3f2e  894604               mov dword ptr [esi + 4], eax
// 004e3f31  5f                   pop edi
// 004e3f32  5e                   pop esi
// 004e3f33  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
