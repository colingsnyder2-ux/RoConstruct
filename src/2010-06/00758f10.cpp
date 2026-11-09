// from server: 100% by auto
// roc 2010-06 00758f10  unit: RBX::PyramidPoly  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00758f10
//
// 00758f10  56                   push esi
// 00758f11  8bf1                 mov esi, ecx
// 00758f13  833e00               cmp dword ptr [esi], 0
// 00758f16  57                   push edi
// 00758f17  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00758f1d  7502                 jne 0x758f21
// 00758f1f  ffd7                 call edi
// 00758f21  8b4604               mov eax, dword ptr [esi + 4]
// 00758f24  80782500             cmp byte ptr [eax + 0x25], 0
// 00758f28  7405                 je 0x758f2f
// 00758f2a  ffd7                 call edi
// 00758f2c  5f                   pop edi
// 00758f2d  5e                   pop esi
// 00758f2e  c3                   ret 
// 00758f2f  8b4808               mov ecx, dword ptr [eax + 8]
// 00758f32  80792500             cmp byte ptr [ecx + 0x25], 0
// 00758f36  7518                 jne 0x758f50
// 00758f38  8b01                 mov eax, dword ptr [ecx]
// 00758f3a  80782500             cmp byte ptr [eax + 0x25], 0
// 00758f3e  750a                 jne 0x758f4a
// 00758f40  8bc8                 mov ecx, eax
// 00758f42  8b01                 mov eax, dword ptr [ecx]
// 00758f44  80782500             cmp byte ptr [eax + 0x25], 0
// 00758f48  74f6                 je 0x758f40
// 00758f4a  5f                   pop edi
// 00758f4b  894e04               mov dword ptr [esi + 4], ecx
// 00758f4e  5e                   pop esi
// 00758f4f  c3                   ret 
// 00758f50  8b4004               mov eax, dword ptr [eax + 4]
// 00758f53  80782500             cmp byte ptr [eax + 0x25], 0
// 00758f57  751d                 jne 0x758f76
// 00758f59  8da42400000000       lea esp, [esp]
// 00758f60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00758f63  3b4808               cmp ecx, dword ptr [eax + 8]
// 00758f66  750e                 jne 0x758f76
// 00758f68  894604               mov dword ptr [esi + 4], eax
// 00758f6b  8bd0                 mov edx, eax
// 00758f6d  8b4204               mov eax, dword ptr [edx + 4]
// 00758f70  80782500             cmp byte ptr [eax + 0x25], 0
// 00758f74  74ea                 je 0x758f60
// 00758f76  5f                   pop edi
// 00758f77  894604               mov dword ptr [esi + 4], eax
// 00758f7a  5e                   pop esi
// 00758f7b  c3                   ret 
// standard library set<pod24> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
