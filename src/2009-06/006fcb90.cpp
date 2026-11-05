// from server: 100% by auto
// roc 2009-06 006fcb90  unit: Ogre::VRbxFont::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fcb90
//
// 006fcb90  56                   push esi
// 006fcb91  8bf1                 mov esi, ecx
// 006fcb93  833e00               cmp dword ptr [esi], 0
// 006fcb96  57                   push edi
// 006fcb97  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006fcb9d  7502                 jne 0x6fcba1
// 006fcb9f  ffd7                 call edi
// 006fcba1  8b4604               mov eax, dword ptr [esi + 4]
// 006fcba4  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcba8  7411                 je 0x6fcbbb
// 006fcbaa  8b4008               mov eax, dword ptr [eax + 8]
// 006fcbad  894604               mov dword ptr [esi + 4], eax
// 006fcbb0  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcbb4  745b                 je 0x6fcc11
// 006fcbb6  ffd7                 call edi
// 006fcbb8  5f                   pop edi
// 006fcbb9  5e                   pop esi
// 006fcbba  c3                   ret 
// 006fcbbb  8b08                 mov ecx, dword ptr [eax]
// 006fcbbd  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fcbc1  751e                 jne 0x6fcbe1
// 006fcbc3  8b4108               mov eax, dword ptr [ecx + 8]
// 006fcbc6  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcbca  750f                 jne 0x6fcbdb
// 006fcbcc  8d642400             lea esp, [esp]
// 006fcbd0  8bc8                 mov ecx, eax
// 006fcbd2  8b4108               mov eax, dword ptr [ecx + 8]
// 006fcbd5  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcbd9  74f5                 je 0x6fcbd0
// 006fcbdb  5f                   pop edi
// 006fcbdc  894e04               mov dword ptr [esi + 4], ecx
// 006fcbdf  5e                   pop esi
// 006fcbe0  c3                   ret 
// 006fcbe1  8b4004               mov eax, dword ptr [eax + 4]
// 006fcbe4  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcbe8  751b                 jne 0x6fcc05
// 006fcbea  8d9b00000000         lea ebx, [ebx]
// 006fcbf0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fcbf3  3b08                 cmp ecx, dword ptr [eax]
// 006fcbf5  750e                 jne 0x6fcc05
// 006fcbf7  894604               mov dword ptr [esi + 4], eax
// 006fcbfa  8bd0                 mov edx, eax
// 006fcbfc  8b4204               mov eax, dword ptr [edx + 4]
// 006fcbff  80783500             cmp byte ptr [eax + 0x35], 0
// 006fcc03  74eb                 je 0x6fcbf0
// 006fcc05  8b4e04               mov ecx, dword ptr [esi + 4]
// 006fcc08  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fcc0c  75a8                 jne 0x6fcbb6
// 006fcc0e  894604               mov dword ptr [esi + 4], eax
// 006fcc11  5f                   pop edi
// 006fcc12  5e                   pop esi
// 006fcc13  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
