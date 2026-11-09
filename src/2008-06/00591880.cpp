// from server: 100% by auto
// roc 2008-06 00591880  unit: RBX::RootInstance  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00591880
//
// 00591880  56                   push esi
// 00591881  8bf1                 mov esi, ecx
// 00591883  833e00               cmp dword ptr [esi], 0
// 00591886  57                   push edi
// 00591887  8b3d90288000         mov edi, dword ptr [0x802890]
// 0059188d  7502                 jne 0x591891
// 0059188f  ffd7                 call edi
// 00591891  8b4604               mov eax, dword ptr [esi + 4]
// 00591894  80783100             cmp byte ptr [eax + 0x31], 0
// 00591898  7405                 je 0x59189f
// 0059189a  ffd7                 call edi
// 0059189c  5f                   pop edi
// 0059189d  5e                   pop esi
// 0059189e  c3                   ret 
// 0059189f  8b4808               mov ecx, dword ptr [eax + 8]
// 005918a2  80793100             cmp byte ptr [ecx + 0x31], 0
// 005918a6  7518                 jne 0x5918c0
// 005918a8  8b01                 mov eax, dword ptr [ecx]
// 005918aa  80783100             cmp byte ptr [eax + 0x31], 0
// 005918ae  750a                 jne 0x5918ba
// 005918b0  8bc8                 mov ecx, eax
// 005918b2  8b01                 mov eax, dword ptr [ecx]
// 005918b4  80783100             cmp byte ptr [eax + 0x31], 0
// 005918b8  74f6                 je 0x5918b0
// 005918ba  5f                   pop edi
// 005918bb  894e04               mov dword ptr [esi + 4], ecx
// 005918be  5e                   pop esi
// 005918bf  c3                   ret 
// 005918c0  8b4004               mov eax, dword ptr [eax + 4]
// 005918c3  80783100             cmp byte ptr [eax + 0x31], 0
// 005918c7  751d                 jne 0x5918e6
// 005918c9  8da42400000000       lea esp, [esp]
// 005918d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005918d3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005918d6  750e                 jne 0x5918e6
// 005918d8  894604               mov dword ptr [esi + 4], eax
// 005918db  8bd0                 mov edx, eax
// 005918dd  8b4204               mov eax, dword ptr [edx + 4]
// 005918e0  80783100             cmp byte ptr [eax + 0x31], 0
// 005918e4  74ea                 je 0x5918d0
// 005918e6  5f                   pop edi
// 005918e7  894604               mov dword ptr [esi + 4], eax
// 005918ea  5e                   pop esi
// 005918eb  c3                   ret 
// standard library set<pod36> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
