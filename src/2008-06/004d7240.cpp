// from server: 100% by auto
// roc 2008-06 004d7240  unit: RBX::ViewNew::ViewRbxGfx  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d7240
//
// 004d7240  56                   push esi
// 004d7241  8bf1                 mov esi, ecx
// 004d7243  833e00               cmp dword ptr [esi], 0
// 004d7246  57                   push edi
// 004d7247  8b3d90288000         mov edi, dword ptr [0x802890]
// 004d724d  7502                 jne 0x4d7251
// 004d724f  ffd7                 call edi
// 004d7251  8b4604               mov eax, dword ptr [esi + 4]
// 004d7254  80782100             cmp byte ptr [eax + 0x21], 0
// 004d7258  7405                 je 0x4d725f
// 004d725a  ffd7                 call edi
// 004d725c  5f                   pop edi
// 004d725d  5e                   pop esi
// 004d725e  c3                   ret 
// 004d725f  8b4808               mov ecx, dword ptr [eax + 8]
// 004d7262  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d7266  7518                 jne 0x4d7280
// 004d7268  8b01                 mov eax, dword ptr [ecx]
// 004d726a  80782100             cmp byte ptr [eax + 0x21], 0
// 004d726e  750a                 jne 0x4d727a
// 004d7270  8bc8                 mov ecx, eax
// 004d7272  8b01                 mov eax, dword ptr [ecx]
// 004d7274  80782100             cmp byte ptr [eax + 0x21], 0
// 004d7278  74f6                 je 0x4d7270
// 004d727a  5f                   pop edi
// 004d727b  894e04               mov dword ptr [esi + 4], ecx
// 004d727e  5e                   pop esi
// 004d727f  c3                   ret 
// 004d7280  8b4004               mov eax, dword ptr [eax + 4]
// 004d7283  80782100             cmp byte ptr [eax + 0x21], 0
// 004d7287  751d                 jne 0x4d72a6
// 004d7289  8da42400000000       lea esp, [esp]
// 004d7290  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d7293  3b4808               cmp ecx, dword ptr [eax + 8]
// 004d7296  750e                 jne 0x4d72a6
// 004d7298  894604               mov dword ptr [esi + 4], eax
// 004d729b  8bd0                 mov edx, eax
// 004d729d  8b4204               mov eax, dword ptr [edx + 4]
// 004d72a0  80782100             cmp byte ptr [eax + 0x21], 0
// 004d72a4  74ea                 je 0x4d7290
// 004d72a6  5f                   pop edi
// 004d72a7  894604               mov dword ptr [esi + 4], eax
// 004d72aa  5e                   pop esi
// 004d72ab  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
