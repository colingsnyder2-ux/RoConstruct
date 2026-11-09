// from server: 100% by auto
// roc 2009-06 005e9170  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e9170
//
// 005e9170  56                   push esi
// 005e9171  8bf1                 mov esi, ecx
// 005e9173  833e00               cmp dword ptr [esi], 0
// 005e9176  57                   push edi
// 005e9177  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 005e917d  7502                 jne 0x5e9181
// 005e917f  ffd7                 call edi
// 005e9181  8b4604               mov eax, dword ptr [esi + 4]
// 005e9184  80781500             cmp byte ptr [eax + 0x15], 0
// 005e9188  7405                 je 0x5e918f
// 005e918a  ffd7                 call edi
// 005e918c  5f                   pop edi
// 005e918d  5e                   pop esi
// 005e918e  c3                   ret 
// 005e918f  8b4808               mov ecx, dword ptr [eax + 8]
// 005e9192  80791500             cmp byte ptr [ecx + 0x15], 0
// 005e9196  7518                 jne 0x5e91b0
// 005e9198  8b01                 mov eax, dword ptr [ecx]
// 005e919a  80781500             cmp byte ptr [eax + 0x15], 0
// 005e919e  750a                 jne 0x5e91aa
// 005e91a0  8bc8                 mov ecx, eax
// 005e91a2  8b01                 mov eax, dword ptr [ecx]
// 005e91a4  80781500             cmp byte ptr [eax + 0x15], 0
// 005e91a8  74f6                 je 0x5e91a0
// 005e91aa  5f                   pop edi
// 005e91ab  894e04               mov dword ptr [esi + 4], ecx
// 005e91ae  5e                   pop esi
// 005e91af  c3                   ret 
// 005e91b0  8b4004               mov eax, dword ptr [eax + 4]
// 005e91b3  80781500             cmp byte ptr [eax + 0x15], 0
// 005e91b7  751d                 jne 0x5e91d6
// 005e91b9  8da42400000000       lea esp, [esp]
// 005e91c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e91c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005e91c6  750e                 jne 0x5e91d6
// 005e91c8  894604               mov dword ptr [esi + 4], eax
// 005e91cb  8bd0                 mov edx, eax
// 005e91cd  8b4204               mov eax, dword ptr [edx + 4]
// 005e91d0  80781500             cmp byte ptr [eax + 0x15], 0
// 005e91d4  74ea                 je 0x5e91c0
// 005e91d6  5f                   pop edi
// 005e91d7  894604               mov dword ptr [esi + 4], eax
// 005e91da  5e                   pop esi
// 005e91db  c3                   ret 
// standard library set<pod8> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
