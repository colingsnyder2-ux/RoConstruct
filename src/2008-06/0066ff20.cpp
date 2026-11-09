// from server: 100% by auto
// roc 2008-06 0066ff20  unit: Ogre::VRbxFont::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ff20
//
// 0066ff20  56                   push esi
// 0066ff21  8bf1                 mov esi, ecx
// 0066ff23  833e00               cmp dword ptr [esi], 0
// 0066ff26  57                   push edi
// 0066ff27  8b3d90288000         mov edi, dword ptr [0x802890]
// 0066ff2d  7502                 jne 0x66ff31
// 0066ff2f  ffd7                 call edi
// 0066ff31  8b4604               mov eax, dword ptr [esi + 4]
// 0066ff34  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff38  7411                 je 0x66ff4b
// 0066ff3a  8b4008               mov eax, dword ptr [eax + 8]
// 0066ff3d  894604               mov dword ptr [esi + 4], eax
// 0066ff40  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff44  745b                 je 0x66ffa1
// 0066ff46  ffd7                 call edi
// 0066ff48  5f                   pop edi
// 0066ff49  5e                   pop esi
// 0066ff4a  c3                   ret 
// 0066ff4b  8b08                 mov ecx, dword ptr [eax]
// 0066ff4d  80793500             cmp byte ptr [ecx + 0x35], 0
// 0066ff51  751e                 jne 0x66ff71
// 0066ff53  8b4108               mov eax, dword ptr [ecx + 8]
// 0066ff56  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff5a  750f                 jne 0x66ff6b
// 0066ff5c  8d642400             lea esp, [esp]
// 0066ff60  8bc8                 mov ecx, eax
// 0066ff62  8b4108               mov eax, dword ptr [ecx + 8]
// 0066ff65  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff69  74f5                 je 0x66ff60
// 0066ff6b  5f                   pop edi
// 0066ff6c  894e04               mov dword ptr [esi + 4], ecx
// 0066ff6f  5e                   pop esi
// 0066ff70  c3                   ret 
// 0066ff71  8b4004               mov eax, dword ptr [eax + 4]
// 0066ff74  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff78  751b                 jne 0x66ff95
// 0066ff7a  8d9b00000000         lea ebx, [ebx]
// 0066ff80  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066ff83  3b08                 cmp ecx, dword ptr [eax]
// 0066ff85  750e                 jne 0x66ff95
// 0066ff87  894604               mov dword ptr [esi + 4], eax
// 0066ff8a  8bd0                 mov edx, eax
// 0066ff8c  8b4204               mov eax, dword ptr [edx + 4]
// 0066ff8f  80783500             cmp byte ptr [eax + 0x35], 0
// 0066ff93  74eb                 je 0x66ff80
// 0066ff95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066ff98  80793500             cmp byte ptr [ecx + 0x35], 0
// 0066ff9c  75a8                 jne 0x66ff46
// 0066ff9e  894604               mov dword ptr [esi + 4], eax
// 0066ffa1  5f                   pop edi
// 0066ffa2  5e                   pop esi
// 0066ffa3  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
