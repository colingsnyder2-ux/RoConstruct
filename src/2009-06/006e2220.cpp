// from server: 100% by auto
// roc 2009-06 006e2220  unit: RBX::ScoreHud  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2220
//
// 006e2220  56                   push esi
// 006e2221  8bf1                 mov esi, ecx
// 006e2223  833e00               cmp dword ptr [esi], 0
// 006e2226  57                   push edi
// 006e2227  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006e222d  7502                 jne 0x6e2231
// 006e222f  ffd7                 call edi
// 006e2231  8b4604               mov eax, dword ptr [esi + 4]
// 006e2234  80784900             cmp byte ptr [eax + 0x49], 0
// 006e2238  7411                 je 0x6e224b
// 006e223a  8b4008               mov eax, dword ptr [eax + 8]
// 006e223d  894604               mov dword ptr [esi + 4], eax
// 006e2240  80784900             cmp byte ptr [eax + 0x49], 0
// 006e2244  745b                 je 0x6e22a1
// 006e2246  ffd7                 call edi
// 006e2248  5f                   pop edi
// 006e2249  5e                   pop esi
// 006e224a  c3                   ret 
// 006e224b  8b08                 mov ecx, dword ptr [eax]
// 006e224d  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e2251  751e                 jne 0x6e2271
// 006e2253  8b4108               mov eax, dword ptr [ecx + 8]
// 006e2256  80784900             cmp byte ptr [eax + 0x49], 0
// 006e225a  750f                 jne 0x6e226b
// 006e225c  8d642400             lea esp, [esp]
// 006e2260  8bc8                 mov ecx, eax
// 006e2262  8b4108               mov eax, dword ptr [ecx + 8]
// 006e2265  80784900             cmp byte ptr [eax + 0x49], 0
// 006e2269  74f5                 je 0x6e2260
// 006e226b  5f                   pop edi
// 006e226c  894e04               mov dword ptr [esi + 4], ecx
// 006e226f  5e                   pop esi
// 006e2270  c3                   ret 
// 006e2271  8b4004               mov eax, dword ptr [eax + 4]
// 006e2274  80784900             cmp byte ptr [eax + 0x49], 0
// 006e2278  751b                 jne 0x6e2295
// 006e227a  8d9b00000000         lea ebx, [ebx]
// 006e2280  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2283  3b08                 cmp ecx, dword ptr [eax]
// 006e2285  750e                 jne 0x6e2295
// 006e2287  894604               mov dword ptr [esi + 4], eax
// 006e228a  8bd0                 mov edx, eax
// 006e228c  8b4204               mov eax, dword ptr [edx + 4]
// 006e228f  80784900             cmp byte ptr [eax + 0x49], 0
// 006e2293  74eb                 je 0x6e2280
// 006e2295  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2298  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e229c  75a8                 jne 0x6e2246
// 006e229e  894604               mov dword ptr [esi + 4], eax
// 006e22a1  5f                   pop edi
// 006e22a2  5e                   pop esi
// 006e22a3  c3                   ret 
// standard library map_str<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
