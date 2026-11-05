// from server: 100% by auto
// roc 2010-06 0053b0c0  unit: RBX::G3DTexture  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053b0c0
//
// 0053b0c0  56                   push esi
// 0053b0c1  8bf1                 mov esi, ecx
// 0053b0c3  833e00               cmp dword ptr [esi], 0
// 0053b0c6  57                   push edi
// 0053b0c7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0053b0cd  7502                 jne 0x53b0d1
// 0053b0cf  ffd7                 call edi
// 0053b0d1  8b4604               mov eax, dword ptr [esi + 4]
// 0053b0d4  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b0d8  7411                 je 0x53b0eb
// 0053b0da  8b4008               mov eax, dword ptr [eax + 8]
// 0053b0dd  894604               mov dword ptr [esi + 4], eax
// 0053b0e0  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b0e4  745b                 je 0x53b141
// 0053b0e6  ffd7                 call edi
// 0053b0e8  5f                   pop edi
// 0053b0e9  5e                   pop esi
// 0053b0ea  c3                   ret 
// 0053b0eb  8b08                 mov ecx, dword ptr [eax]
// 0053b0ed  80792500             cmp byte ptr [ecx + 0x25], 0
// 0053b0f1  751e                 jne 0x53b111
// 0053b0f3  8b4108               mov eax, dword ptr [ecx + 8]
// 0053b0f6  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b0fa  750f                 jne 0x53b10b
// 0053b0fc  8d642400             lea esp, [esp]
// 0053b100  8bc8                 mov ecx, eax
// 0053b102  8b4108               mov eax, dword ptr [ecx + 8]
// 0053b105  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b109  74f5                 je 0x53b100
// 0053b10b  5f                   pop edi
// 0053b10c  894e04               mov dword ptr [esi + 4], ecx
// 0053b10f  5e                   pop esi
// 0053b110  c3                   ret 
// 0053b111  8b4004               mov eax, dword ptr [eax + 4]
// 0053b114  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b118  751b                 jne 0x53b135
// 0053b11a  8d9b00000000         lea ebx, [ebx]
// 0053b120  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053b123  3b08                 cmp ecx, dword ptr [eax]
// 0053b125  750e                 jne 0x53b135
// 0053b127  894604               mov dword ptr [esi + 4], eax
// 0053b12a  8bd0                 mov edx, eax
// 0053b12c  8b4204               mov eax, dword ptr [edx + 4]
// 0053b12f  80782500             cmp byte ptr [eax + 0x25], 0
// 0053b133  74eb                 je 0x53b120
// 0053b135  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053b138  80792500             cmp byte ptr [ecx + 0x25], 0
// 0053b13c  75a8                 jne 0x53b0e6
// 0053b13e  894604               mov dword ptr [esi + 4], eax
// 0053b141  5f                   pop edi
// 0053b142  5e                   pop esi
// 0053b143  c3                   ret 
// standard library map_int<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
