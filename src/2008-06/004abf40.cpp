// from server: 100% by auto
// roc 2008-06 004abf40  unit: RBX::Network::Replicator  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004abf40
//
// 004abf40  56                   push esi
// 004abf41  8bf1                 mov esi, ecx
// 004abf43  833e00               cmp dword ptr [esi], 0
// 004abf46  57                   push edi
// 004abf47  8b3d90288000         mov edi, dword ptr [0x802890]
// 004abf4d  7502                 jne 0x4abf51
// 004abf4f  ffd7                 call edi
// 004abf51  8b4604               mov eax, dword ptr [esi + 4]
// 004abf54  80781900             cmp byte ptr [eax + 0x19], 0
// 004abf58  7411                 je 0x4abf6b
// 004abf5a  8b4008               mov eax, dword ptr [eax + 8]
// 004abf5d  894604               mov dword ptr [esi + 4], eax
// 004abf60  80781900             cmp byte ptr [eax + 0x19], 0
// 004abf64  745b                 je 0x4abfc1
// 004abf66  ffd7                 call edi
// 004abf68  5f                   pop edi
// 004abf69  5e                   pop esi
// 004abf6a  c3                   ret 
// 004abf6b  8b08                 mov ecx, dword ptr [eax]
// 004abf6d  80791900             cmp byte ptr [ecx + 0x19], 0
// 004abf71  751e                 jne 0x4abf91
// 004abf73  8b4108               mov eax, dword ptr [ecx + 8]
// 004abf76  80781900             cmp byte ptr [eax + 0x19], 0
// 004abf7a  750f                 jne 0x4abf8b
// 004abf7c  8d642400             lea esp, [esp]
// 004abf80  8bc8                 mov ecx, eax
// 004abf82  8b4108               mov eax, dword ptr [ecx + 8]
// 004abf85  80781900             cmp byte ptr [eax + 0x19], 0
// 004abf89  74f5                 je 0x4abf80
// 004abf8b  5f                   pop edi
// 004abf8c  894e04               mov dword ptr [esi + 4], ecx
// 004abf8f  5e                   pop esi
// 004abf90  c3                   ret 
// 004abf91  8b4004               mov eax, dword ptr [eax + 4]
// 004abf94  80781900             cmp byte ptr [eax + 0x19], 0
// 004abf98  751b                 jne 0x4abfb5
// 004abf9a  8d9b00000000         lea ebx, [ebx]
// 004abfa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004abfa3  3b08                 cmp ecx, dword ptr [eax]
// 004abfa5  750e                 jne 0x4abfb5
// 004abfa7  894604               mov dword ptr [esi + 4], eax
// 004abfaa  8bd0                 mov edx, eax
// 004abfac  8b4204               mov eax, dword ptr [edx + 4]
// 004abfaf  80781900             cmp byte ptr [eax + 0x19], 0
// 004abfb3  74eb                 je 0x4abfa0
// 004abfb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004abfb8  80791900             cmp byte ptr [ecx + 0x19], 0
// 004abfbc  75a8                 jne 0x4abf66
// 004abfbe  894604               mov dword ptr [esi + 4], eax
// 004abfc1  5f                   pop edi
// 004abfc2  5e                   pop esi
// 004abfc3  c3                   ret 
// standard library map_int<pod8> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
