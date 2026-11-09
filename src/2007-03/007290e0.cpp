// from server: 100% by auto
// roc 2007-03 007290e0  unit: seg_00720000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007290e0
//
// 007290e0  56                   push esi
// 007290e1  8bf1                 mov esi, ecx
// 007290e3  833e00               cmp dword ptr [esi], 0
// 007290e6  57                   push edi
// 007290e7  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 007290ed  7502                 jne 0x7290f1
// 007290ef  ffd7                 call edi
// 007290f1  8b4604               mov eax, dword ptr [esi + 4]
// 007290f4  80782500             cmp byte ptr [eax + 0x25], 0
// 007290f8  7411                 je 0x72910b
// 007290fa  8b4008               mov eax, dword ptr [eax + 8]
// 007290fd  894604               mov dword ptr [esi + 4], eax
// 00729100  80782500             cmp byte ptr [eax + 0x25], 0
// 00729104  745b                 je 0x729161
// 00729106  ffd7                 call edi
// 00729108  5f                   pop edi
// 00729109  5e                   pop esi
// 0072910a  c3                   ret 
// 0072910b  8b08                 mov ecx, dword ptr [eax]
// 0072910d  80792500             cmp byte ptr [ecx + 0x25], 0
// 00729111  751e                 jne 0x729131
// 00729113  8b4108               mov eax, dword ptr [ecx + 8]
// 00729116  80782500             cmp byte ptr [eax + 0x25], 0
// 0072911a  750f                 jne 0x72912b
// 0072911c  8d642400             lea esp, [esp]
// 00729120  8bc8                 mov ecx, eax
// 00729122  8b4108               mov eax, dword ptr [ecx + 8]
// 00729125  80782500             cmp byte ptr [eax + 0x25], 0
// 00729129  74f5                 je 0x729120
// 0072912b  5f                   pop edi
// 0072912c  894e04               mov dword ptr [esi + 4], ecx
// 0072912f  5e                   pop esi
// 00729130  c3                   ret 
// 00729131  8b4004               mov eax, dword ptr [eax + 4]
// 00729134  80782500             cmp byte ptr [eax + 0x25], 0
// 00729138  751b                 jne 0x729155
// 0072913a  8d9b00000000         lea ebx, [ebx]
// 00729140  8b4e04               mov ecx, dword ptr [esi + 4]
// 00729143  3b08                 cmp ecx, dword ptr [eax]
// 00729145  750e                 jne 0x729155
// 00729147  894604               mov dword ptr [esi + 4], eax
// 0072914a  8bd0                 mov edx, eax
// 0072914c  8b4204               mov eax, dword ptr [edx + 4]
// 0072914f  80782500             cmp byte ptr [eax + 0x25], 0
// 00729153  74eb                 je 0x729140
// 00729155  8b4e04               mov ecx, dword ptr [esi + 4]
// 00729158  80792500             cmp byte ptr [ecx + 0x25], 0
// 0072915c  75a8                 jne 0x729106
// 0072915e  894604               mov dword ptr [esi + 4], eax
// 00729161  5f                   pop edi
// 00729162  5e                   pop esi
// 00729163  c3                   ret 
// standard library map_int<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
