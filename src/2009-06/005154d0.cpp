// from server: 100% by auto
// roc 2009-06 005154d0  unit: seg_00510000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005154d0
//
// 005154d0  56                   push esi
// 005154d1  8bf1                 mov esi, ecx
// 005154d3  833e00               cmp dword ptr [esi], 0
// 005154d6  57                   push edi
// 005154d7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 005154dd  7502                 jne 0x5154e1
// 005154df  ffd7                 call edi
// 005154e1  8b4604               mov eax, dword ptr [esi + 4]
// 005154e4  80782500             cmp byte ptr [eax + 0x25], 0
// 005154e8  7411                 je 0x5154fb
// 005154ea  8b4008               mov eax, dword ptr [eax + 8]
// 005154ed  894604               mov dword ptr [esi + 4], eax
// 005154f0  80782500             cmp byte ptr [eax + 0x25], 0
// 005154f4  745b                 je 0x515551
// 005154f6  ffd7                 call edi
// 005154f8  5f                   pop edi
// 005154f9  5e                   pop esi
// 005154fa  c3                   ret 
// 005154fb  8b08                 mov ecx, dword ptr [eax]
// 005154fd  80792500             cmp byte ptr [ecx + 0x25], 0
// 00515501  751e                 jne 0x515521
// 00515503  8b4108               mov eax, dword ptr [ecx + 8]
// 00515506  80782500             cmp byte ptr [eax + 0x25], 0
// 0051550a  750f                 jne 0x51551b
// 0051550c  8d642400             lea esp, [esp]
// 00515510  8bc8                 mov ecx, eax
// 00515512  8b4108               mov eax, dword ptr [ecx + 8]
// 00515515  80782500             cmp byte ptr [eax + 0x25], 0
// 00515519  74f5                 je 0x515510
// 0051551b  5f                   pop edi
// 0051551c  894e04               mov dword ptr [esi + 4], ecx
// 0051551f  5e                   pop esi
// 00515520  c3                   ret 
// 00515521  8b4004               mov eax, dword ptr [eax + 4]
// 00515524  80782500             cmp byte ptr [eax + 0x25], 0
// 00515528  751b                 jne 0x515545
// 0051552a  8d9b00000000         lea ebx, [ebx]
// 00515530  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515533  3b08                 cmp ecx, dword ptr [eax]
// 00515535  750e                 jne 0x515545
// 00515537  894604               mov dword ptr [esi + 4], eax
// 0051553a  8bd0                 mov edx, eax
// 0051553c  8b4204               mov eax, dword ptr [edx + 4]
// 0051553f  80782500             cmp byte ptr [eax + 0x25], 0
// 00515543  74eb                 je 0x515530
// 00515545  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515548  80792500             cmp byte ptr [ecx + 0x25], 0
// 0051554c  75a8                 jne 0x5154f6
// 0051554e  894604               mov dword ptr [esi + 4], eax
// 00515551  5f                   pop edi
// 00515552  5e                   pop esi
// 00515553  c3                   ret 
// standard library map_int<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
