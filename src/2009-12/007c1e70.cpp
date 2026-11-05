// from server: 100% by auto
// roc 2009-12 007c1e70  unit: RBX::ImageButton  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c1e70
//
// 007c1e70  56                   push esi
// 007c1e71  8bf1                 mov esi, ecx
// 007c1e73  833e00               cmp dword ptr [esi], 0
// 007c1e76  57                   push edi
// 007c1e77  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 007c1e7d  7502                 jne 0x7c1e81
// 007c1e7f  ffd7                 call edi
// 007c1e81  8b4604               mov eax, dword ptr [esi + 4]
// 007c1e84  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1e88  7405                 je 0x7c1e8f
// 007c1e8a  ffd7                 call edi
// 007c1e8c  5f                   pop edi
// 007c1e8d  5e                   pop esi
// 007c1e8e  c3                   ret 
// 007c1e8f  8b4808               mov ecx, dword ptr [eax + 8]
// 007c1e92  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1e96  7518                 jne 0x7c1eb0
// 007c1e98  8b01                 mov eax, dword ptr [ecx]
// 007c1e9a  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1e9e  750a                 jne 0x7c1eaa
// 007c1ea0  8bc8                 mov ecx, eax
// 007c1ea2  8b01                 mov eax, dword ptr [ecx]
// 007c1ea4  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1ea8  74f6                 je 0x7c1ea0
// 007c1eaa  5f                   pop edi
// 007c1eab  894e04               mov dword ptr [esi + 4], ecx
// 007c1eae  5e                   pop esi
// 007c1eaf  c3                   ret 
// 007c1eb0  8b4004               mov eax, dword ptr [eax + 4]
// 007c1eb3  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1eb7  751d                 jne 0x7c1ed6
// 007c1eb9  8da42400000000       lea esp, [esp]
// 007c1ec0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c1ec3  3b4808               cmp ecx, dword ptr [eax + 8]
// 007c1ec6  750e                 jne 0x7c1ed6
// 007c1ec8  894604               mov dword ptr [esi + 4], eax
// 007c1ecb  8bd0                 mov edx, eax
// 007c1ecd  8b4204               mov eax, dword ptr [edx + 4]
// 007c1ed0  80784d00             cmp byte ptr [eax + 0x4d], 0
// 007c1ed4  74ea                 je 0x7c1ec0
// 007c1ed6  5f                   pop edi
// 007c1ed7  894604               mov dword ptr [esi + 4], eax
// 007c1eda  5e                   pop esi
// 007c1edb  c3                   ret 
// standard library set<pod64> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
