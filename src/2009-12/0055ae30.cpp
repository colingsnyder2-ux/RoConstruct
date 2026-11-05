// from server: 100% by auto
// roc 2009-12 0055ae30  unit: RBX::Network::ServerReplicator  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055ae30
//
// 0055ae30  56                   push esi
// 0055ae31  8bf1                 mov esi, ecx
// 0055ae33  833e00               cmp dword ptr [esi], 0
// 0055ae36  57                   push edi
// 0055ae37  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0055ae3d  7502                 jne 0x55ae41
// 0055ae3f  ffd7                 call edi
// 0055ae41  8b4604               mov eax, dword ptr [esi + 4]
// 0055ae44  80782500             cmp byte ptr [eax + 0x25], 0
// 0055ae48  7405                 je 0x55ae4f
// 0055ae4a  ffd7                 call edi
// 0055ae4c  5f                   pop edi
// 0055ae4d  5e                   pop esi
// 0055ae4e  c3                   ret 
// 0055ae4f  8b4808               mov ecx, dword ptr [eax + 8]
// 0055ae52  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055ae56  7518                 jne 0x55ae70
// 0055ae58  8b01                 mov eax, dword ptr [ecx]
// 0055ae5a  80782500             cmp byte ptr [eax + 0x25], 0
// 0055ae5e  750a                 jne 0x55ae6a
// 0055ae60  8bc8                 mov ecx, eax
// 0055ae62  8b01                 mov eax, dword ptr [ecx]
// 0055ae64  80782500             cmp byte ptr [eax + 0x25], 0
// 0055ae68  74f6                 je 0x55ae60
// 0055ae6a  5f                   pop edi
// 0055ae6b  894e04               mov dword ptr [esi + 4], ecx
// 0055ae6e  5e                   pop esi
// 0055ae6f  c3                   ret 
// 0055ae70  8b4004               mov eax, dword ptr [eax + 4]
// 0055ae73  80782500             cmp byte ptr [eax + 0x25], 0
// 0055ae77  751d                 jne 0x55ae96
// 0055ae79  8da42400000000       lea esp, [esp]
// 0055ae80  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055ae83  3b4808               cmp ecx, dword ptr [eax + 8]
// 0055ae86  750e                 jne 0x55ae96
// 0055ae88  894604               mov dword ptr [esi + 4], eax
// 0055ae8b  8bd0                 mov edx, eax
// 0055ae8d  8b4204               mov eax, dword ptr [edx + 4]
// 0055ae90  80782500             cmp byte ptr [eax + 0x25], 0
// 0055ae94  74ea                 je 0x55ae80
// 0055ae96  5f                   pop edi
// 0055ae97  894604               mov dword ptr [esi + 4], eax
// 0055ae9a  5e                   pop esi
// 0055ae9b  c3                   ret 
// standard library set<pod24> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
