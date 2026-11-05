// from server: 100% by auto
// roc 2009-12 006b3b10  unit: RBX::DropperTool  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b3b10
//
// 006b3b10  56                   push esi
// 006b3b11  8bf1                 mov esi, ecx
// 006b3b13  833e00               cmp dword ptr [esi], 0
// 006b3b16  57                   push edi
// 006b3b17  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 006b3b1d  7502                 jne 0x6b3b21
// 006b3b1f  ffd7                 call edi
// 006b3b21  8b4604               mov eax, dword ptr [esi + 4]
// 006b3b24  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b28  7411                 je 0x6b3b3b
// 006b3b2a  8b4008               mov eax, dword ptr [eax + 8]
// 006b3b2d  894604               mov dword ptr [esi + 4], eax
// 006b3b30  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b34  745b                 je 0x6b3b91
// 006b3b36  ffd7                 call edi
// 006b3b38  5f                   pop edi
// 006b3b39  5e                   pop esi
// 006b3b3a  c3                   ret 
// 006b3b3b  8b08                 mov ecx, dword ptr [eax]
// 006b3b3d  80793500             cmp byte ptr [ecx + 0x35], 0
// 006b3b41  751e                 jne 0x6b3b61
// 006b3b43  8b4108               mov eax, dword ptr [ecx + 8]
// 006b3b46  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b4a  750f                 jne 0x6b3b5b
// 006b3b4c  8d642400             lea esp, [esp]
// 006b3b50  8bc8                 mov ecx, eax
// 006b3b52  8b4108               mov eax, dword ptr [ecx + 8]
// 006b3b55  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b59  74f5                 je 0x6b3b50
// 006b3b5b  5f                   pop edi
// 006b3b5c  894e04               mov dword ptr [esi + 4], ecx
// 006b3b5f  5e                   pop esi
// 006b3b60  c3                   ret 
// 006b3b61  8b4004               mov eax, dword ptr [eax + 4]
// 006b3b64  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b68  751b                 jne 0x6b3b85
// 006b3b6a  8d9b00000000         lea ebx, [ebx]
// 006b3b70  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b3b73  3b08                 cmp ecx, dword ptr [eax]
// 006b3b75  750e                 jne 0x6b3b85
// 006b3b77  894604               mov dword ptr [esi + 4], eax
// 006b3b7a  8bd0                 mov edx, eax
// 006b3b7c  8b4204               mov eax, dword ptr [edx + 4]
// 006b3b7f  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b83  74eb                 je 0x6b3b70
// 006b3b85  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b3b88  80793500             cmp byte ptr [ecx + 0x35], 0
// 006b3b8c  75a8                 jne 0x6b3b36
// 006b3b8e  894604               mov dword ptr [esi + 4], eax
// 006b3b91  5f                   pop edi
// 006b3b92  5e                   pop esi
// 006b3b93  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
