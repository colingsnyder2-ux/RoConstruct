// from server: 100% by auto
// roc 2009-12 007af970  unit: RBX::Block  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007af970
//
// 007af970  56                   push esi
// 007af971  8bf1                 mov esi, ecx
// 007af973  833e00               cmp dword ptr [esi], 0
// 007af976  57                   push edi
// 007af977  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 007af97d  7502                 jne 0x7af981
// 007af97f  ffd7                 call edi
// 007af981  8b4604               mov eax, dword ptr [esi + 4]
// 007af984  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007af988  7405                 je 0x7af98f
// 007af98a  ffd7                 call edi
// 007af98c  5f                   pop edi
// 007af98d  5e                   pop esi
// 007af98e  c3                   ret 
// 007af98f  8b4808               mov ecx, dword ptr [eax + 8]
// 007af992  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007af996  7518                 jne 0x7af9b0
// 007af998  8b01                 mov eax, dword ptr [ecx]
// 007af99a  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007af99e  750a                 jne 0x7af9aa
// 007af9a0  8bc8                 mov ecx, eax
// 007af9a2  8b01                 mov eax, dword ptr [ecx]
// 007af9a4  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007af9a8  74f6                 je 0x7af9a0
// 007af9aa  5f                   pop edi
// 007af9ab  894e04               mov dword ptr [esi + 4], ecx
// 007af9ae  5e                   pop esi
// 007af9af  c3                   ret 
// 007af9b0  8b4004               mov eax, dword ptr [eax + 4]
// 007af9b3  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007af9b7  751d                 jne 0x7af9d6
// 007af9b9  8da42400000000       lea esp, [esp]
// 007af9c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007af9c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 007af9c6  750e                 jne 0x7af9d6
// 007af9c8  894604               mov dword ptr [esi + 4], eax
// 007af9cb  8bd0                 mov edx, eax
// 007af9cd  8b4204               mov eax, dword ptr [edx + 4]
// 007af9d0  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007af9d4  74ea                 je 0x7af9c0
// 007af9d6  5f                   pop edi
// 007af9d7  894604               mov dword ptr [esi + 4], eax
// 007af9da  5e                   pop esi
// 007af9db  c3                   ret 
// standard library set<pod16> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
