// from server: 100% by auto
// roc 2009-06 006233b0  unit: ArchiveBinder  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006233b0
//
// 006233b0  56                   push esi
// 006233b1  8bf1                 mov esi, ecx
// 006233b3  833e00               cmp dword ptr [esi], 0
// 006233b6  57                   push edi
// 006233b7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006233bd  7502                 jne 0x6233c1
// 006233bf  ffd7                 call edi
// 006233c1  8b4604               mov eax, dword ptr [esi + 4]
// 006233c4  80783100             cmp byte ptr [eax + 0x31], 0
// 006233c8  7411                 je 0x6233db
// 006233ca  8b4008               mov eax, dword ptr [eax + 8]
// 006233cd  894604               mov dword ptr [esi + 4], eax
// 006233d0  80783100             cmp byte ptr [eax + 0x31], 0
// 006233d4  745b                 je 0x623431
// 006233d6  ffd7                 call edi
// 006233d8  5f                   pop edi
// 006233d9  5e                   pop esi
// 006233da  c3                   ret 
// 006233db  8b08                 mov ecx, dword ptr [eax]
// 006233dd  80793100             cmp byte ptr [ecx + 0x31], 0
// 006233e1  751e                 jne 0x623401
// 006233e3  8b4108               mov eax, dword ptr [ecx + 8]
// 006233e6  80783100             cmp byte ptr [eax + 0x31], 0
// 006233ea  750f                 jne 0x6233fb
// 006233ec  8d642400             lea esp, [esp]
// 006233f0  8bc8                 mov ecx, eax
// 006233f2  8b4108               mov eax, dword ptr [ecx + 8]
// 006233f5  80783100             cmp byte ptr [eax + 0x31], 0
// 006233f9  74f5                 je 0x6233f0
// 006233fb  5f                   pop edi
// 006233fc  894e04               mov dword ptr [esi + 4], ecx
// 006233ff  5e                   pop esi
// 00623400  c3                   ret 
// 00623401  8b4004               mov eax, dword ptr [eax + 4]
// 00623404  80783100             cmp byte ptr [eax + 0x31], 0
// 00623408  751b                 jne 0x623425
// 0062340a  8d9b00000000         lea ebx, [ebx]
// 00623410  8b4e04               mov ecx, dword ptr [esi + 4]
// 00623413  3b08                 cmp ecx, dword ptr [eax]
// 00623415  750e                 jne 0x623425
// 00623417  894604               mov dword ptr [esi + 4], eax
// 0062341a  8bd0                 mov edx, eax
// 0062341c  8b4204               mov eax, dword ptr [edx + 4]
// 0062341f  80783100             cmp byte ptr [eax + 0x31], 0
// 00623423  74eb                 je 0x623410
// 00623425  8b4e04               mov ecx, dword ptr [esi + 4]
// 00623428  80793100             cmp byte ptr [ecx + 0x31], 0
// 0062342c  75a8                 jne 0x6233d6
// 0062342e  894604               mov dword ptr [esi + 4], eax
// 00623431  5f                   pop edi
// 00623432  5e                   pop esi
// 00623433  c3                   ret 
// standard library map_int<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
