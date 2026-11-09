// from server: 100% by auto
// roc 2009-12 0047a910  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047a910
//
// 0047a910  56                   push esi
// 0047a911  8bf1                 mov esi, ecx
// 0047a913  833e00               cmp dword ptr [esi], 0
// 0047a916  57                   push edi
// 0047a917  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0047a91d  7502                 jne 0x47a921
// 0047a91f  ffd7                 call edi
// 0047a921  8b4604               mov eax, dword ptr [esi + 4]
// 0047a924  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047a928  7405                 je 0x47a92f
// 0047a92a  ffd7                 call edi
// 0047a92c  5f                   pop edi
// 0047a92d  5e                   pop esi
// 0047a92e  c3                   ret 
// 0047a92f  8b4808               mov ecx, dword ptr [eax + 8]
// 0047a932  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0047a936  7518                 jne 0x47a950
// 0047a938  8b01                 mov eax, dword ptr [ecx]
// 0047a93a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047a93e  750a                 jne 0x47a94a
// 0047a940  8bc8                 mov ecx, eax
// 0047a942  8b01                 mov eax, dword ptr [ecx]
// 0047a944  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047a948  74f6                 je 0x47a940
// 0047a94a  5f                   pop edi
// 0047a94b  894e04               mov dword ptr [esi + 4], ecx
// 0047a94e  5e                   pop esi
// 0047a94f  c3                   ret 
// 0047a950  8b4004               mov eax, dword ptr [eax + 4]
// 0047a953  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047a957  751d                 jne 0x47a976
// 0047a959  8da42400000000       lea esp, [esp]
// 0047a960  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047a963  3b4808               cmp ecx, dword ptr [eax + 8]
// 0047a966  750e                 jne 0x47a976
// 0047a968  894604               mov dword ptr [esi + 4], eax
// 0047a96b  8bd0                 mov edx, eax
// 0047a96d  8b4204               mov eax, dword ptr [edx + 4]
// 0047a970  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047a974  74ea                 je 0x47a960
// 0047a976  5f                   pop edi
// 0047a977  894604               mov dword ptr [esi + 4], eax
// 0047a97a  5e                   pop esi
// 0047a97b  c3                   ret 
// standard library set<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
