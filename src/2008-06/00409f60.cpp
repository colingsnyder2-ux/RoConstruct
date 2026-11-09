// from server: 100% by auto
// roc 2008-06 00409f60  unit: RBX::GlobalSettings::Item  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00409f60
//
// 00409f60  56                   push esi
// 00409f61  8bf1                 mov esi, ecx
// 00409f63  833e00               cmp dword ptr [esi], 0
// 00409f66  57                   push edi
// 00409f67  8b3d90288000         mov edi, dword ptr [0x802890]
// 00409f6d  7502                 jne 0x409f71
// 00409f6f  ffd7                 call edi
// 00409f71  8b4604               mov eax, dword ptr [esi + 4]
// 00409f74  80783500             cmp byte ptr [eax + 0x35], 0
// 00409f78  7405                 je 0x409f7f
// 00409f7a  ffd7                 call edi
// 00409f7c  5f                   pop edi
// 00409f7d  5e                   pop esi
// 00409f7e  c3                   ret 
// 00409f7f  8b4808               mov ecx, dword ptr [eax + 8]
// 00409f82  80793500             cmp byte ptr [ecx + 0x35], 0
// 00409f86  7518                 jne 0x409fa0
// 00409f88  8b01                 mov eax, dword ptr [ecx]
// 00409f8a  80783500             cmp byte ptr [eax + 0x35], 0
// 00409f8e  750a                 jne 0x409f9a
// 00409f90  8bc8                 mov ecx, eax
// 00409f92  8b01                 mov eax, dword ptr [ecx]
// 00409f94  80783500             cmp byte ptr [eax + 0x35], 0
// 00409f98  74f6                 je 0x409f90
// 00409f9a  5f                   pop edi
// 00409f9b  894e04               mov dword ptr [esi + 4], ecx
// 00409f9e  5e                   pop esi
// 00409f9f  c3                   ret 
// 00409fa0  8b4004               mov eax, dword ptr [eax + 4]
// 00409fa3  80783500             cmp byte ptr [eax + 0x35], 0
// 00409fa7  751d                 jne 0x409fc6
// 00409fa9  8da42400000000       lea esp, [esp]
// 00409fb0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00409fb3  3b4808               cmp ecx, dword ptr [eax + 8]
// 00409fb6  750e                 jne 0x409fc6
// 00409fb8  894604               mov dword ptr [esi + 4], eax
// 00409fbb  8bd0                 mov edx, eax
// 00409fbd  8b4204               mov eax, dword ptr [edx + 4]
// 00409fc0  80783500             cmp byte ptr [eax + 0x35], 0
// 00409fc4  74ea                 je 0x409fb0
// 00409fc6  5f                   pop edi
// 00409fc7  894604               mov dword ptr [esi + 4], eax
// 00409fca  5e                   pop esi
// 00409fcb  c3                   ret 
// standard library set<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
