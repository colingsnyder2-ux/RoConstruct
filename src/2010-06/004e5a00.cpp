// from server: 100% by auto
// roc 2010-06 004e5a00  unit: RBX::Network::Replicator  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e5a00
//
// 004e5a00  56                   push esi
// 004e5a01  8bf1                 mov esi, ecx
// 004e5a03  833e00               cmp dword ptr [esi], 0
// 004e5a06  57                   push edi
// 004e5a07  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 004e5a0d  7502                 jne 0x4e5a11
// 004e5a0f  ffd7                 call edi
// 004e5a11  8b4604               mov eax, dword ptr [esi + 4]
// 004e5a14  80783500             cmp byte ptr [eax + 0x35], 0
// 004e5a18  7405                 je 0x4e5a1f
// 004e5a1a  ffd7                 call edi
// 004e5a1c  5f                   pop edi
// 004e5a1d  5e                   pop esi
// 004e5a1e  c3                   ret 
// 004e5a1f  8b4808               mov ecx, dword ptr [eax + 8]
// 004e5a22  80793500             cmp byte ptr [ecx + 0x35], 0
// 004e5a26  7518                 jne 0x4e5a40
// 004e5a28  8b01                 mov eax, dword ptr [ecx]
// 004e5a2a  80783500             cmp byte ptr [eax + 0x35], 0
// 004e5a2e  750a                 jne 0x4e5a3a
// 004e5a30  8bc8                 mov ecx, eax
// 004e5a32  8b01                 mov eax, dword ptr [ecx]
// 004e5a34  80783500             cmp byte ptr [eax + 0x35], 0
// 004e5a38  74f6                 je 0x4e5a30
// 004e5a3a  5f                   pop edi
// 004e5a3b  894e04               mov dword ptr [esi + 4], ecx
// 004e5a3e  5e                   pop esi
// 004e5a3f  c3                   ret 
// 004e5a40  8b4004               mov eax, dword ptr [eax + 4]
// 004e5a43  80783500             cmp byte ptr [eax + 0x35], 0
// 004e5a47  751d                 jne 0x4e5a66
// 004e5a49  8da42400000000       lea esp, [esp]
// 004e5a50  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e5a53  3b4808               cmp ecx, dword ptr [eax + 8]
// 004e5a56  750e                 jne 0x4e5a66
// 004e5a58  894604               mov dword ptr [esi + 4], eax
// 004e5a5b  8bd0                 mov edx, eax
// 004e5a5d  8b4204               mov eax, dword ptr [edx + 4]
// 004e5a60  80783500             cmp byte ptr [eax + 0x35], 0
// 004e5a64  74ea                 je 0x4e5a50
// 004e5a66  5f                   pop edi
// 004e5a67  894604               mov dword ptr [esi + 4], eax
// 004e5a6a  5e                   pop esi
// 004e5a6b  c3                   ret 
// standard library set<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
