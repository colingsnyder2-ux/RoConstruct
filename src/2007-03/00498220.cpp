// from server: 100% by auto
// roc 2007-03 00498220  unit: seg_00490000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00498220
//
// 00498220  56                   push esi
// 00498221  8bf1                 mov esi, ecx
// 00498223  833e00               cmp dword ptr [esi], 0
// 00498226  57                   push edi
// 00498227  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 0049822d  7502                 jne 0x498231
// 0049822f  ffd7                 call edi
// 00498231  8b4604               mov eax, dword ptr [esi + 4]
// 00498234  80782100             cmp byte ptr [eax + 0x21], 0
// 00498238  7405                 je 0x49823f
// 0049823a  ffd7                 call edi
// 0049823c  5f                   pop edi
// 0049823d  5e                   pop esi
// 0049823e  c3                   ret 
// 0049823f  8b4808               mov ecx, dword ptr [eax + 8]
// 00498242  80792100             cmp byte ptr [ecx + 0x21], 0
// 00498246  7518                 jne 0x498260
// 00498248  8b01                 mov eax, dword ptr [ecx]
// 0049824a  80782100             cmp byte ptr [eax + 0x21], 0
// 0049824e  750a                 jne 0x49825a
// 00498250  8bc8                 mov ecx, eax
// 00498252  8b01                 mov eax, dword ptr [ecx]
// 00498254  80782100             cmp byte ptr [eax + 0x21], 0
// 00498258  74f6                 je 0x498250
// 0049825a  5f                   pop edi
// 0049825b  894e04               mov dword ptr [esi + 4], ecx
// 0049825e  5e                   pop esi
// 0049825f  c3                   ret 
// 00498260  8b4004               mov eax, dword ptr [eax + 4]
// 00498263  80782100             cmp byte ptr [eax + 0x21], 0
// 00498267  751d                 jne 0x498286
// 00498269  8da42400000000       lea esp, [esp]
// 00498270  8b4e04               mov ecx, dword ptr [esi + 4]
// 00498273  3b4808               cmp ecx, dword ptr [eax + 8]
// 00498276  750e                 jne 0x498286
// 00498278  894604               mov dword ptr [esi + 4], eax
// 0049827b  8bd0                 mov edx, eax
// 0049827d  8b4204               mov eax, dword ptr [edx + 4]
// 00498280  80782100             cmp byte ptr [eax + 0x21], 0
// 00498284  74ea                 je 0x498270
// 00498286  5f                   pop edi
// 00498287  894604               mov dword ptr [esi + 4], eax
// 0049828a  5e                   pop esi
// 0049828b  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
