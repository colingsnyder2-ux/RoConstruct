// from server: 100% by auto
// roc 2009-06 00516b10  unit: RBX::MeshRefPartAdapter  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516b10
//
// 00516b10  56                   push esi
// 00516b11  8bf1                 mov esi, ecx
// 00516b13  833e00               cmp dword ptr [esi], 0
// 00516b16  57                   push edi
// 00516b17  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00516b1d  7502                 jne 0x516b21
// 00516b1f  ffd7                 call edi
// 00516b21  8b4604               mov eax, dword ptr [esi + 4]
// 00516b24  80782100             cmp byte ptr [eax + 0x21], 0
// 00516b28  7405                 je 0x516b2f
// 00516b2a  ffd7                 call edi
// 00516b2c  5f                   pop edi
// 00516b2d  5e                   pop esi
// 00516b2e  c3                   ret 
// 00516b2f  8b4808               mov ecx, dword ptr [eax + 8]
// 00516b32  80792100             cmp byte ptr [ecx + 0x21], 0
// 00516b36  7518                 jne 0x516b50
// 00516b38  8b01                 mov eax, dword ptr [ecx]
// 00516b3a  80782100             cmp byte ptr [eax + 0x21], 0
// 00516b3e  750a                 jne 0x516b4a
// 00516b40  8bc8                 mov ecx, eax
// 00516b42  8b01                 mov eax, dword ptr [ecx]
// 00516b44  80782100             cmp byte ptr [eax + 0x21], 0
// 00516b48  74f6                 je 0x516b40
// 00516b4a  5f                   pop edi
// 00516b4b  894e04               mov dword ptr [esi + 4], ecx
// 00516b4e  5e                   pop esi
// 00516b4f  c3                   ret 
// 00516b50  8b4004               mov eax, dword ptr [eax + 4]
// 00516b53  80782100             cmp byte ptr [eax + 0x21], 0
// 00516b57  751d                 jne 0x516b76
// 00516b59  8da42400000000       lea esp, [esp]
// 00516b60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00516b63  3b4808               cmp ecx, dword ptr [eax + 8]
// 00516b66  750e                 jne 0x516b76
// 00516b68  894604               mov dword ptr [esi + 4], eax
// 00516b6b  8bd0                 mov edx, eax
// 00516b6d  8b4204               mov eax, dword ptr [edx + 4]
// 00516b70  80782100             cmp byte ptr [eax + 0x21], 0
// 00516b74  74ea                 je 0x516b60
// 00516b76  5f                   pop edi
// 00516b77  894604               mov dword ptr [esi + 4], eax
// 00516b7a  5e                   pop esi
// 00516b7b  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
