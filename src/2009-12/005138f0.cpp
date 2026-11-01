// from server: 100% by auto
// roc 2009-12 005138f0  unit: RBX::Network::Players  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005138f0
//
// 005138f0  56                   push esi
// 005138f1  8bf1                 mov esi, ecx
// 005138f3  833e00               cmp dword ptr [esi], 0
// 005138f6  57                   push edi
// 005138f7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 005138fd  7502                 jne 0x513901
// 005138ff  ffd7                 call edi
// 00513901  8b4604               mov eax, dword ptr [esi + 4]
// 00513904  80783100             cmp byte ptr [eax + 0x31], 0
// 00513908  7405                 je 0x51390f
// 0051390a  ffd7                 call edi
// 0051390c  5f                   pop edi
// 0051390d  5e                   pop esi
// 0051390e  c3                   ret 
// 0051390f  8b4808               mov ecx, dword ptr [eax + 8]
// 00513912  80793100             cmp byte ptr [ecx + 0x31], 0
// 00513916  7518                 jne 0x513930
// 00513918  8b01                 mov eax, dword ptr [ecx]
// 0051391a  80783100             cmp byte ptr [eax + 0x31], 0
// 0051391e  750a                 jne 0x51392a
// 00513920  8bc8                 mov ecx, eax
// 00513922  8b01                 mov eax, dword ptr [ecx]
// 00513924  80783100             cmp byte ptr [eax + 0x31], 0
// 00513928  74f6                 je 0x513920
// 0051392a  5f                   pop edi
// 0051392b  894e04               mov dword ptr [esi + 4], ecx
// 0051392e  5e                   pop esi
// 0051392f  c3                   ret 
// 00513930  8b4004               mov eax, dword ptr [eax + 4]
// 00513933  80783100             cmp byte ptr [eax + 0x31], 0
// 00513937  751d                 jne 0x513956
// 00513939  8da42400000000       lea esp, [esp]
// 00513940  8b4e04               mov ecx, dword ptr [esi + 4]
// 00513943  3b4808               cmp ecx, dword ptr [eax + 8]
// 00513946  750e                 jne 0x513956
// 00513948  894604               mov dword ptr [esi + 4], eax
// 0051394b  8bd0                 mov edx, eax
// 0051394d  8b4204               mov eax, dword ptr [edx + 4]
// 00513950  80783100             cmp byte ptr [eax + 0x31], 0
// 00513954  74ea                 je 0x513940
// 00513956  5f                   pop edi
// 00513957  894604               mov dword ptr [esi + 4], eax
// 0051395a  5e                   pop esi
// 0051395b  c3                   ret 
// standard library set<pod36> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
