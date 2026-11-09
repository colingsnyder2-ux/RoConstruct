// from server: 100% by auto
// roc 2009-06 006d2f40  unit: RBX::Block  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d2f40
//
// 006d2f40  56                   push esi
// 006d2f41  8bf1                 mov esi, ecx
// 006d2f43  833e00               cmp dword ptr [esi], 0
// 006d2f46  57                   push edi
// 006d2f47  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006d2f4d  7502                 jne 0x6d2f51
// 006d2f4f  ffd7                 call edi
// 006d2f51  8b4604               mov eax, dword ptr [esi + 4]
// 006d2f54  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d2f58  7405                 je 0x6d2f5f
// 006d2f5a  ffd7                 call edi
// 006d2f5c  5f                   pop edi
// 006d2f5d  5e                   pop esi
// 006d2f5e  c3                   ret 
// 006d2f5f  8b4808               mov ecx, dword ptr [eax + 8]
// 006d2f62  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d2f66  7518                 jne 0x6d2f80
// 006d2f68  8b01                 mov eax, dword ptr [ecx]
// 006d2f6a  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d2f6e  750a                 jne 0x6d2f7a
// 006d2f70  8bc8                 mov ecx, eax
// 006d2f72  8b01                 mov eax, dword ptr [ecx]
// 006d2f74  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d2f78  74f6                 je 0x6d2f70
// 006d2f7a  5f                   pop edi
// 006d2f7b  894e04               mov dword ptr [esi + 4], ecx
// 006d2f7e  5e                   pop esi
// 006d2f7f  c3                   ret 
// 006d2f80  8b4004               mov eax, dword ptr [eax + 4]
// 006d2f83  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d2f87  751d                 jne 0x6d2fa6
// 006d2f89  8da42400000000       lea esp, [esp]
// 006d2f90  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d2f93  3b4808               cmp ecx, dword ptr [eax + 8]
// 006d2f96  750e                 jne 0x6d2fa6
// 006d2f98  894604               mov dword ptr [esi + 4], eax
// 006d2f9b  8bd0                 mov edx, eax
// 006d2f9d  8b4204               mov eax, dword ptr [edx + 4]
// 006d2fa0  80781d00             cmp byte ptr [eax + 0x1d], 0
// 006d2fa4  74ea                 je 0x6d2f90
// 006d2fa6  5f                   pop edi
// 006d2fa7  894604               mov dword ptr [esi + 4], eax
// 006d2faa  5e                   pop esi
// 006d2fab  c3                   ret 
// standard library set<pod16> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
