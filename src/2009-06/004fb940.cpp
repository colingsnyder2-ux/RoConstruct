// from server: 100% by auto
// roc 2009-06 004fb940  unit: RBX::Network::ServerReplicator  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fb940
//
// 004fb940  56                   push esi
// 004fb941  8bf1                 mov esi, ecx
// 004fb943  833e00               cmp dword ptr [esi], 0
// 004fb946  57                   push edi
// 004fb947  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 004fb94d  7502                 jne 0x4fb951
// 004fb94f  ffd7                 call edi
// 004fb951  8b4604               mov eax, dword ptr [esi + 4]
// 004fb954  80783900             cmp byte ptr [eax + 0x39], 0
// 004fb958  7405                 je 0x4fb95f
// 004fb95a  ffd7                 call edi
// 004fb95c  5f                   pop edi
// 004fb95d  5e                   pop esi
// 004fb95e  c3                   ret 
// 004fb95f  8b4808               mov ecx, dword ptr [eax + 8]
// 004fb962  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fb966  7518                 jne 0x4fb980
// 004fb968  8b01                 mov eax, dword ptr [ecx]
// 004fb96a  80783900             cmp byte ptr [eax + 0x39], 0
// 004fb96e  750a                 jne 0x4fb97a
// 004fb970  8bc8                 mov ecx, eax
// 004fb972  8b01                 mov eax, dword ptr [ecx]
// 004fb974  80783900             cmp byte ptr [eax + 0x39], 0
// 004fb978  74f6                 je 0x4fb970
// 004fb97a  5f                   pop edi
// 004fb97b  894e04               mov dword ptr [esi + 4], ecx
// 004fb97e  5e                   pop esi
// 004fb97f  c3                   ret 
// 004fb980  8b4004               mov eax, dword ptr [eax + 4]
// 004fb983  80783900             cmp byte ptr [eax + 0x39], 0
// 004fb987  751d                 jne 0x4fb9a6
// 004fb989  8da42400000000       lea esp, [esp]
// 004fb990  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fb993  3b4808               cmp ecx, dword ptr [eax + 8]
// 004fb996  750e                 jne 0x4fb9a6
// 004fb998  894604               mov dword ptr [esi + 4], eax
// 004fb99b  8bd0                 mov edx, eax
// 004fb99d  8b4204               mov eax, dword ptr [edx + 4]
// 004fb9a0  80783900             cmp byte ptr [eax + 0x39], 0
// 004fb9a4  74ea                 je 0x4fb990
// 004fb9a6  5f                   pop edi
// 004fb9a7  894604               mov dword ptr [esi + 4], eax
// 004fb9aa  5e                   pop esi
// 004fb9ab  c3                   ret 
// standard library map_int<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
