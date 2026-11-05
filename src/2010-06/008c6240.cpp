// from server: 100% by auto
// roc 2010-06 008c6240  unit: RBX::AdornRbxGfx  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6240
//
// 008c6240  56                   push esi
// 008c6241  8bf1                 mov esi, ecx
// 008c6243  833e00               cmp dword ptr [esi], 0
// 008c6246  57                   push edi
// 008c6247  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 008c624d  7502                 jne 0x8c6251
// 008c624f  ffd7                 call edi
// 008c6251  8b4604               mov eax, dword ptr [esi + 4]
// 008c6254  80782d00             cmp byte ptr [eax + 0x2d], 0
// 008c6258  7405                 je 0x8c625f
// 008c625a  ffd7                 call edi
// 008c625c  5f                   pop edi
// 008c625d  5e                   pop esi
// 008c625e  c3                   ret 
// 008c625f  8b4808               mov ecx, dword ptr [eax + 8]
// 008c6262  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 008c6266  7518                 jne 0x8c6280
// 008c6268  8b01                 mov eax, dword ptr [ecx]
// 008c626a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 008c626e  750a                 jne 0x8c627a
// 008c6270  8bc8                 mov ecx, eax
// 008c6272  8b01                 mov eax, dword ptr [ecx]
// 008c6274  80782d00             cmp byte ptr [eax + 0x2d], 0
// 008c6278  74f6                 je 0x8c6270
// 008c627a  5f                   pop edi
// 008c627b  894e04               mov dword ptr [esi + 4], ecx
// 008c627e  5e                   pop esi
// 008c627f  c3                   ret 
// 008c6280  8b4004               mov eax, dword ptr [eax + 4]
// 008c6283  80782d00             cmp byte ptr [eax + 0x2d], 0
// 008c6287  751d                 jne 0x8c62a6
// 008c6289  8da42400000000       lea esp, [esp]
// 008c6290  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c6293  3b4808               cmp ecx, dword ptr [eax + 8]
// 008c6296  750e                 jne 0x8c62a6
// 008c6298  894604               mov dword ptr [esi + 4], eax
// 008c629b  8bd0                 mov edx, eax
// 008c629d  8b4204               mov eax, dword ptr [edx + 4]
// 008c62a0  80782d00             cmp byte ptr [eax + 0x2d], 0
// 008c62a4  74ea                 je 0x8c6290
// 008c62a6  5f                   pop edi
// 008c62a7  894604               mov dword ptr [esi + 4], eax
// 008c62aa  5e                   pop esi
// 008c62ab  c3                   ret 
// standard library set<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
