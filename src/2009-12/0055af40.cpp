// from server: 100% by auto
// roc 2009-12 0055af40  unit: RBX::Network::ServerReplicator  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055af40
//
// 0055af40  56                   push esi
// 0055af41  8bf1                 mov esi, ecx
// 0055af43  833e00               cmp dword ptr [esi], 0
// 0055af46  57                   push edi
// 0055af47  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0055af4d  7502                 jne 0x55af51
// 0055af4f  ffd7                 call edi
// 0055af51  8b4604               mov eax, dword ptr [esi + 4]
// 0055af54  80782500             cmp byte ptr [eax + 0x25], 0
// 0055af58  7411                 je 0x55af6b
// 0055af5a  8b4008               mov eax, dword ptr [eax + 8]
// 0055af5d  894604               mov dword ptr [esi + 4], eax
// 0055af60  80782500             cmp byte ptr [eax + 0x25], 0
// 0055af64  745b                 je 0x55afc1
// 0055af66  ffd7                 call edi
// 0055af68  5f                   pop edi
// 0055af69  5e                   pop esi
// 0055af6a  c3                   ret 
// 0055af6b  8b08                 mov ecx, dword ptr [eax]
// 0055af6d  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055af71  751e                 jne 0x55af91
// 0055af73  8b4108               mov eax, dword ptr [ecx + 8]
// 0055af76  80782500             cmp byte ptr [eax + 0x25], 0
// 0055af7a  750f                 jne 0x55af8b
// 0055af7c  8d642400             lea esp, [esp]
// 0055af80  8bc8                 mov ecx, eax
// 0055af82  8b4108               mov eax, dword ptr [ecx + 8]
// 0055af85  80782500             cmp byte ptr [eax + 0x25], 0
// 0055af89  74f5                 je 0x55af80
// 0055af8b  5f                   pop edi
// 0055af8c  894e04               mov dword ptr [esi + 4], ecx
// 0055af8f  5e                   pop esi
// 0055af90  c3                   ret 
// 0055af91  8b4004               mov eax, dword ptr [eax + 4]
// 0055af94  80782500             cmp byte ptr [eax + 0x25], 0
// 0055af98  751b                 jne 0x55afb5
// 0055af9a  8d9b00000000         lea ebx, [ebx]
// 0055afa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055afa3  3b08                 cmp ecx, dword ptr [eax]
// 0055afa5  750e                 jne 0x55afb5
// 0055afa7  894604               mov dword ptr [esi + 4], eax
// 0055afaa  8bd0                 mov edx, eax
// 0055afac  8b4204               mov eax, dword ptr [edx + 4]
// 0055afaf  80782500             cmp byte ptr [eax + 0x25], 0
// 0055afb3  74eb                 je 0x55afa0
// 0055afb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055afb8  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055afbc  75a8                 jne 0x55af66
// 0055afbe  894604               mov dword ptr [esi + 4], eax
// 0055afc1  5f                   pop edi
// 0055afc2  5e                   pop esi
// 0055afc3  c3                   ret 
// standard library map_int<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
