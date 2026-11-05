// from server: 100% by auto
// roc 2009-12 00513860  unit: RBX::Network::Players  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00513860
//
// 00513860  56                   push esi
// 00513861  8bf1                 mov esi, ecx
// 00513863  833e00               cmp dword ptr [esi], 0
// 00513866  57                   push edi
// 00513867  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0051386d  7502                 jne 0x513871
// 0051386f  ffd7                 call edi
// 00513871  8b4604               mov eax, dword ptr [esi + 4]
// 00513874  80783100             cmp byte ptr [eax + 0x31], 0
// 00513878  7411                 je 0x51388b
// 0051387a  8b4008               mov eax, dword ptr [eax + 8]
// 0051387d  894604               mov dword ptr [esi + 4], eax
// 00513880  80783100             cmp byte ptr [eax + 0x31], 0
// 00513884  745b                 je 0x5138e1
// 00513886  ffd7                 call edi
// 00513888  5f                   pop edi
// 00513889  5e                   pop esi
// 0051388a  c3                   ret 
// 0051388b  8b08                 mov ecx, dword ptr [eax]
// 0051388d  80793100             cmp byte ptr [ecx + 0x31], 0
// 00513891  751e                 jne 0x5138b1
// 00513893  8b4108               mov eax, dword ptr [ecx + 8]
// 00513896  80783100             cmp byte ptr [eax + 0x31], 0
// 0051389a  750f                 jne 0x5138ab
// 0051389c  8d642400             lea esp, [esp]
// 005138a0  8bc8                 mov ecx, eax
// 005138a2  8b4108               mov eax, dword ptr [ecx + 8]
// 005138a5  80783100             cmp byte ptr [eax + 0x31], 0
// 005138a9  74f5                 je 0x5138a0
// 005138ab  5f                   pop edi
// 005138ac  894e04               mov dword ptr [esi + 4], ecx
// 005138af  5e                   pop esi
// 005138b0  c3                   ret 
// 005138b1  8b4004               mov eax, dword ptr [eax + 4]
// 005138b4  80783100             cmp byte ptr [eax + 0x31], 0
// 005138b8  751b                 jne 0x5138d5
// 005138ba  8d9b00000000         lea ebx, [ebx]
// 005138c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005138c3  3b08                 cmp ecx, dword ptr [eax]
// 005138c5  750e                 jne 0x5138d5
// 005138c7  894604               mov dword ptr [esi + 4], eax
// 005138ca  8bd0                 mov edx, eax
// 005138cc  8b4204               mov eax, dword ptr [edx + 4]
// 005138cf  80783100             cmp byte ptr [eax + 0x31], 0
// 005138d3  74eb                 je 0x5138c0
// 005138d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005138d8  80793100             cmp byte ptr [ecx + 0x31], 0
// 005138dc  75a8                 jne 0x513886
// 005138de  894604               mov dword ptr [esi + 4], eax
// 005138e1  5f                   pop edi
// 005138e2  5e                   pop esi
// 005138e3  c3                   ret 
// standard library map_int<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
