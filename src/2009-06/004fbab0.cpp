// from server: 100% by auto
// roc 2009-06 004fbab0  unit: RBX::Network::ServerReplicator  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fbab0
//
// 004fbab0  56                   push esi
// 004fbab1  8bf1                 mov esi, ecx
// 004fbab3  833e00               cmp dword ptr [esi], 0
// 004fbab6  57                   push edi
// 004fbab7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 004fbabd  7502                 jne 0x4fbac1
// 004fbabf  ffd7                 call edi
// 004fbac1  8b4604               mov eax, dword ptr [esi + 4]
// 004fbac4  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbac8  7411                 je 0x4fbadb
// 004fbaca  8b4008               mov eax, dword ptr [eax + 8]
// 004fbacd  894604               mov dword ptr [esi + 4], eax
// 004fbad0  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbad4  745b                 je 0x4fbb31
// 004fbad6  ffd7                 call edi
// 004fbad8  5f                   pop edi
// 004fbad9  5e                   pop esi
// 004fbada  c3                   ret 
// 004fbadb  8b08                 mov ecx, dword ptr [eax]
// 004fbadd  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fbae1  751e                 jne 0x4fbb01
// 004fbae3  8b4108               mov eax, dword ptr [ecx + 8]
// 004fbae6  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbaea  750f                 jne 0x4fbafb
// 004fbaec  8d642400             lea esp, [esp]
// 004fbaf0  8bc8                 mov ecx, eax
// 004fbaf2  8b4108               mov eax, dword ptr [ecx + 8]
// 004fbaf5  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbaf9  74f5                 je 0x4fbaf0
// 004fbafb  5f                   pop edi
// 004fbafc  894e04               mov dword ptr [esi + 4], ecx
// 004fbaff  5e                   pop esi
// 004fbb00  c3                   ret 
// 004fbb01  8b4004               mov eax, dword ptr [eax + 4]
// 004fbb04  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbb08  751b                 jne 0x4fbb25
// 004fbb0a  8d9b00000000         lea ebx, [ebx]
// 004fbb10  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fbb13  3b08                 cmp ecx, dword ptr [eax]
// 004fbb15  750e                 jne 0x4fbb25
// 004fbb17  894604               mov dword ptr [esi + 4], eax
// 004fbb1a  8bd0                 mov edx, eax
// 004fbb1c  8b4204               mov eax, dword ptr [edx + 4]
// 004fbb1f  80783900             cmp byte ptr [eax + 0x39], 0
// 004fbb23  74eb                 je 0x4fbb10
// 004fbb25  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fbb28  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fbb2c  75a8                 jne 0x4fbad6
// 004fbb2e  894604               mov dword ptr [esi + 4], eax
// 004fbb31  5f                   pop edi
// 004fbb32  5e                   pop esi
// 004fbb33  c3                   ret 
// standard library map_int<pod40> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
