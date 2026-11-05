// from server: 100% by auto
// roc 2007-08 004a5200  unit: RBX::Network::Server::ClientProxy  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a5200
//
// 004a5200  56                   push esi
// 004a5201  8bf1                 mov esi, ecx
// 004a5203  833e00               cmp dword ptr [esi], 0
// 004a5206  57                   push edi
// 004a5207  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004a520d  7502                 jne 0x4a5211
// 004a520f  ffd7                 call edi
// 004a5211  8b4604               mov eax, dword ptr [esi + 4]
// 004a5214  80782500             cmp byte ptr [eax + 0x25], 0
// 004a5218  7411                 je 0x4a522b
// 004a521a  8b4008               mov eax, dword ptr [eax + 8]
// 004a521d  894604               mov dword ptr [esi + 4], eax
// 004a5220  80782500             cmp byte ptr [eax + 0x25], 0
// 004a5224  745b                 je 0x4a5281
// 004a5226  ffd7                 call edi
// 004a5228  5f                   pop edi
// 004a5229  5e                   pop esi
// 004a522a  c3                   ret 
// 004a522b  8b08                 mov ecx, dword ptr [eax]
// 004a522d  80792500             cmp byte ptr [ecx + 0x25], 0
// 004a5231  751e                 jne 0x4a5251
// 004a5233  8b4108               mov eax, dword ptr [ecx + 8]
// 004a5236  80782500             cmp byte ptr [eax + 0x25], 0
// 004a523a  750f                 jne 0x4a524b
// 004a523c  8d642400             lea esp, [esp]
// 004a5240  8bc8                 mov ecx, eax
// 004a5242  8b4108               mov eax, dword ptr [ecx + 8]
// 004a5245  80782500             cmp byte ptr [eax + 0x25], 0
// 004a5249  74f5                 je 0x4a5240
// 004a524b  5f                   pop edi
// 004a524c  894e04               mov dword ptr [esi + 4], ecx
// 004a524f  5e                   pop esi
// 004a5250  c3                   ret 
// 004a5251  8b4004               mov eax, dword ptr [eax + 4]
// 004a5254  80782500             cmp byte ptr [eax + 0x25], 0
// 004a5258  751b                 jne 0x4a5275
// 004a525a  8d9b00000000         lea ebx, [ebx]
// 004a5260  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a5263  3b08                 cmp ecx, dword ptr [eax]
// 004a5265  750e                 jne 0x4a5275
// 004a5267  894604               mov dword ptr [esi + 4], eax
// 004a526a  8bd0                 mov edx, eax
// 004a526c  8b4204               mov eax, dword ptr [edx + 4]
// 004a526f  80782500             cmp byte ptr [eax + 0x25], 0
// 004a5273  74eb                 je 0x4a5260
// 004a5275  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a5278  80792500             cmp byte ptr [ecx + 0x25], 0
// 004a527c  75a8                 jne 0x4a5226
// 004a527e  894604               mov dword ptr [esi + 4], eax
// 004a5281  5f                   pop edi
// 004a5282  5e                   pop esi
// 004a5283  c3                   ret 
// standard library map_int<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
