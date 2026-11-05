// from server: 100% by auto
// roc 2009-06 006d3000  unit: RBX::Block  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d3000
//
// 006d3000  56                   push esi
// 006d3001  8bf1                 mov esi, ecx
// 006d3003  833e00               cmp dword ptr [esi], 0
// 006d3006  57                   push edi
// 006d3007  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006d300d  7502                 jne 0x6d3011
// 006d300f  ffd7                 call edi
// 006d3011  8b4604               mov eax, dword ptr [esi + 4]
// 006d3014  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d3018  7411                 je 0x6d302b
// 006d301a  8b4008               mov eax, dword ptr [eax + 8]
// 006d301d  894604               mov dword ptr [esi + 4], eax
// 006d3020  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d3024  745b                 je 0x6d3081
// 006d3026  ffd7                 call edi
// 006d3028  5f                   pop edi
// 006d3029  5e                   pop esi
// 006d302a  c3                   ret 
// 006d302b  8b08                 mov ecx, dword ptr [eax]
// 006d302d  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d3031  751e                 jne 0x6d3051
// 006d3033  8b4108               mov eax, dword ptr [ecx + 8]
// 006d3036  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d303a  750f                 jne 0x6d304b
// 006d303c  8d642400             lea esp, [esp]
// 006d3040  8bc8                 mov ecx, eax
// 006d3042  8b4108               mov eax, dword ptr [ecx + 8]
// 006d3045  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d3049  74f5                 je 0x6d3040
// 006d304b  5f                   pop edi
// 006d304c  894e04               mov dword ptr [esi + 4], ecx
// 006d304f  5e                   pop esi
// 006d3050  c3                   ret 
// 006d3051  8b4004               mov eax, dword ptr [eax + 4]
// 006d3054  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d3058  751b                 jne 0x6d3075
// 006d305a  8d9b00000000         lea ebx, [ebx]
// 006d3060  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d3063  3b08                 cmp ecx, dword ptr [eax]
// 006d3065  750e                 jne 0x6d3075
// 006d3067  894604               mov dword ptr [esi + 4], eax
// 006d306a  8bd0                 mov edx, eax
// 006d306c  8b4204               mov eax, dword ptr [edx + 4]
// 006d306f  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d3073  74eb                 je 0x6d3060
// 006d3075  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d3078  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d307c  75a8                 jne 0x6d3026
// 006d307e  894604               mov dword ptr [esi + 4], eax
// 006d3081  5f                   pop edi
// 006d3082  5e                   pop esi
// 006d3083  c3                   ret 
// standard library map_int<pod12> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
