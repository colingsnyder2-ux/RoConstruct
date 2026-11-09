// from server: 100% by auto
// roc 2008-06 00648120  unit: RBX::Block  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648120
//
// 00648120  56                   push esi
// 00648121  8bf1                 mov esi, ecx
// 00648123  833e00               cmp dword ptr [esi], 0
// 00648126  57                   push edi
// 00648127  8b3d90288000         mov edi, dword ptr [0x802890]
// 0064812d  7502                 jne 0x648131
// 0064812f  ffd7                 call edi
// 00648131  8b4604               mov eax, dword ptr [esi + 4]
// 00648134  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648138  7405                 je 0x64813f
// 0064813a  ffd7                 call edi
// 0064813c  5f                   pop edi
// 0064813d  5e                   pop esi
// 0064813e  c3                   ret 
// 0064813f  8b4808               mov ecx, dword ptr [eax + 8]
// 00648142  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00648146  7518                 jne 0x648160
// 00648148  8b01                 mov eax, dword ptr [ecx]
// 0064814a  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0064814e  750a                 jne 0x64815a
// 00648150  8bc8                 mov ecx, eax
// 00648152  8b01                 mov eax, dword ptr [ecx]
// 00648154  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648158  74f6                 je 0x648150
// 0064815a  5f                   pop edi
// 0064815b  894e04               mov dword ptr [esi + 4], ecx
// 0064815e  5e                   pop esi
// 0064815f  c3                   ret 
// 00648160  8b4004               mov eax, dword ptr [eax + 4]
// 00648163  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648167  751d                 jne 0x648186
// 00648169  8da42400000000       lea esp, [esp]
// 00648170  8b4e04               mov ecx, dword ptr [esi + 4]
// 00648173  3b4808               cmp ecx, dword ptr [eax + 8]
// 00648176  750e                 jne 0x648186
// 00648178  894604               mov dword ptr [esi + 4], eax
// 0064817b  8bd0                 mov edx, eax
// 0064817d  8b4204               mov eax, dword ptr [edx + 4]
// 00648180  80781d00             cmp byte ptr [eax + 0x1d], 0
// 00648184  74ea                 je 0x648170
// 00648186  5f                   pop edi
// 00648187  894604               mov dword ptr [esi + 4], eax
// 0064818a  5e                   pop esi
// 0064818b  c3                   ret 
// standard library set<pod16> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
