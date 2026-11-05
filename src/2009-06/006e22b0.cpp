// from server: 100% by auto
// roc 2009-06 006e22b0  unit: RBX::ScoreHud  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e22b0
//
// 006e22b0  56                   push esi
// 006e22b1  8bf1                 mov esi, ecx
// 006e22b3  833e00               cmp dword ptr [esi], 0
// 006e22b6  57                   push edi
// 006e22b7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006e22bd  7502                 jne 0x6e22c1
// 006e22bf  ffd7                 call edi
// 006e22c1  8b4604               mov eax, dword ptr [esi + 4]
// 006e22c4  80783100             cmp byte ptr [eax + 0x31], 0
// 006e22c8  7405                 je 0x6e22cf
// 006e22ca  ffd7                 call edi
// 006e22cc  5f                   pop edi
// 006e22cd  5e                   pop esi
// 006e22ce  c3                   ret 
// 006e22cf  8b4808               mov ecx, dword ptr [eax + 8]
// 006e22d2  80793100             cmp byte ptr [ecx + 0x31], 0
// 006e22d6  7518                 jne 0x6e22f0
// 006e22d8  8b01                 mov eax, dword ptr [ecx]
// 006e22da  80783100             cmp byte ptr [eax + 0x31], 0
// 006e22de  750a                 jne 0x6e22ea
// 006e22e0  8bc8                 mov ecx, eax
// 006e22e2  8b01                 mov eax, dword ptr [ecx]
// 006e22e4  80783100             cmp byte ptr [eax + 0x31], 0
// 006e22e8  74f6                 je 0x6e22e0
// 006e22ea  5f                   pop edi
// 006e22eb  894e04               mov dword ptr [esi + 4], ecx
// 006e22ee  5e                   pop esi
// 006e22ef  c3                   ret 
// 006e22f0  8b4004               mov eax, dword ptr [eax + 4]
// 006e22f3  80783100             cmp byte ptr [eax + 0x31], 0
// 006e22f7  751d                 jne 0x6e2316
// 006e22f9  8da42400000000       lea esp, [esp]
// 006e2300  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e2303  3b4808               cmp ecx, dword ptr [eax + 8]
// 006e2306  750e                 jne 0x6e2316
// 006e2308  894604               mov dword ptr [esi + 4], eax
// 006e230b  8bd0                 mov edx, eax
// 006e230d  8b4204               mov eax, dword ptr [edx + 4]
// 006e2310  80783100             cmp byte ptr [eax + 0x31], 0
// 006e2314  74ea                 je 0x6e2300
// 006e2316  5f                   pop edi
// 006e2317  894604               mov dword ptr [esi + 4], eax
// 006e231a  5e                   pop esi
// 006e231b  c3                   ret 
// standard library set<pod36> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
