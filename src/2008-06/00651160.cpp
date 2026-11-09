// from server: 100% by auto
// roc 2008-06 00651160  unit: RBX::ScoreHud  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651160
//
// 00651160  56                   push esi
// 00651161  8bf1                 mov esi, ecx
// 00651163  833e00               cmp dword ptr [esi], 0
// 00651166  57                   push edi
// 00651167  8b3d90288000         mov edi, dword ptr [0x802890]
// 0065116d  7502                 jne 0x651171
// 0065116f  ffd7                 call edi
// 00651171  8b4604               mov eax, dword ptr [esi + 4]
// 00651174  80783100             cmp byte ptr [eax + 0x31], 0
// 00651178  7411                 je 0x65118b
// 0065117a  8b4008               mov eax, dword ptr [eax + 8]
// 0065117d  894604               mov dword ptr [esi + 4], eax
// 00651180  80783100             cmp byte ptr [eax + 0x31], 0
// 00651184  745b                 je 0x6511e1
// 00651186  ffd7                 call edi
// 00651188  5f                   pop edi
// 00651189  5e                   pop esi
// 0065118a  c3                   ret 
// 0065118b  8b08                 mov ecx, dword ptr [eax]
// 0065118d  80793100             cmp byte ptr [ecx + 0x31], 0
// 00651191  751e                 jne 0x6511b1
// 00651193  8b4108               mov eax, dword ptr [ecx + 8]
// 00651196  80783100             cmp byte ptr [eax + 0x31], 0
// 0065119a  750f                 jne 0x6511ab
// 0065119c  8d642400             lea esp, [esp]
// 006511a0  8bc8                 mov ecx, eax
// 006511a2  8b4108               mov eax, dword ptr [ecx + 8]
// 006511a5  80783100             cmp byte ptr [eax + 0x31], 0
// 006511a9  74f5                 je 0x6511a0
// 006511ab  5f                   pop edi
// 006511ac  894e04               mov dword ptr [esi + 4], ecx
// 006511af  5e                   pop esi
// 006511b0  c3                   ret 
// 006511b1  8b4004               mov eax, dword ptr [eax + 4]
// 006511b4  80783100             cmp byte ptr [eax + 0x31], 0
// 006511b8  751b                 jne 0x6511d5
// 006511ba  8d9b00000000         lea ebx, [ebx]
// 006511c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006511c3  3b08                 cmp ecx, dword ptr [eax]
// 006511c5  750e                 jne 0x6511d5
// 006511c7  894604               mov dword ptr [esi + 4], eax
// 006511ca  8bd0                 mov edx, eax
// 006511cc  8b4204               mov eax, dword ptr [edx + 4]
// 006511cf  80783100             cmp byte ptr [eax + 0x31], 0
// 006511d3  74eb                 je 0x6511c0
// 006511d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006511d8  80793100             cmp byte ptr [ecx + 0x31], 0
// 006511dc  75a8                 jne 0x651186
// 006511de  894604               mov dword ptr [esi + 4], eax
// 006511e1  5f                   pop edi
// 006511e2  5e                   pop esi
// 006511e3  c3                   ret 
// standard library map_int<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
