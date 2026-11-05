// from server: 100% by auto
// roc 2007-08 004a5190  unit: RBX::Network::Server::ClientProxy  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a5190
//
// 004a5190  56                   push esi
// 004a5191  8bf1                 mov esi, ecx
// 004a5193  833e00               cmp dword ptr [esi], 0
// 004a5196  57                   push edi
// 004a5197  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004a519d  7502                 jne 0x4a51a1
// 004a519f  ffd7                 call edi
// 004a51a1  8b4604               mov eax, dword ptr [esi + 4]
// 004a51a4  80782500             cmp byte ptr [eax + 0x25], 0
// 004a51a8  7405                 je 0x4a51af
// 004a51aa  ffd7                 call edi
// 004a51ac  5f                   pop edi
// 004a51ad  5e                   pop esi
// 004a51ae  c3                   ret 
// 004a51af  8b4808               mov ecx, dword ptr [eax + 8]
// 004a51b2  80792500             cmp byte ptr [ecx + 0x25], 0
// 004a51b6  7518                 jne 0x4a51d0
// 004a51b8  8b01                 mov eax, dword ptr [ecx]
// 004a51ba  80782500             cmp byte ptr [eax + 0x25], 0
// 004a51be  750a                 jne 0x4a51ca
// 004a51c0  8bc8                 mov ecx, eax
// 004a51c2  8b01                 mov eax, dword ptr [ecx]
// 004a51c4  80782500             cmp byte ptr [eax + 0x25], 0
// 004a51c8  74f6                 je 0x4a51c0
// 004a51ca  5f                   pop edi
// 004a51cb  894e04               mov dword ptr [esi + 4], ecx
// 004a51ce  5e                   pop esi
// 004a51cf  c3                   ret 
// 004a51d0  8b4004               mov eax, dword ptr [eax + 4]
// 004a51d3  80782500             cmp byte ptr [eax + 0x25], 0
// 004a51d7  751d                 jne 0x4a51f6
// 004a51d9  8da42400000000       lea esp, [esp]
// 004a51e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a51e3  3b4808               cmp ecx, dword ptr [eax + 8]
// 004a51e6  750e                 jne 0x4a51f6
// 004a51e8  894604               mov dword ptr [esi + 4], eax
// 004a51eb  8bd0                 mov edx, eax
// 004a51ed  8b4204               mov eax, dword ptr [edx + 4]
// 004a51f0  80782500             cmp byte ptr [eax + 0x25], 0
// 004a51f4  74ea                 je 0x4a51e0
// 004a51f6  5f                   pop edi
// 004a51f7  894604               mov dword ptr [esi + 4], eax
// 004a51fa  5e                   pop esi
// 004a51fb  c3                   ret 
// standard library set<pod24> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
