// from server: 100% by auto
// roc 2007-03 004c4d40  unit: seg_004c0000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c4d40
//
// 004c4d40  56                   push esi
// 004c4d41  8bf1                 mov esi, ecx
// 004c4d43  833e00               cmp dword ptr [esi], 0
// 004c4d46  57                   push edi
// 004c4d47  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 004c4d4d  7502                 jne 0x4c4d51
// 004c4d4f  ffd7                 call edi
// 004c4d51  8b4604               mov eax, dword ptr [esi + 4]
// 004c4d54  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4d58  7411                 je 0x4c4d6b
// 004c4d5a  8b4008               mov eax, dword ptr [eax + 8]
// 004c4d5d  894604               mov dword ptr [esi + 4], eax
// 004c4d60  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4d64  745b                 je 0x4c4dc1
// 004c4d66  ffd7                 call edi
// 004c4d68  5f                   pop edi
// 004c4d69  5e                   pop esi
// 004c4d6a  c3                   ret 
// 004c4d6b  8b08                 mov ecx, dword ptr [eax]
// 004c4d6d  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c4d71  751e                 jne 0x4c4d91
// 004c4d73  8b4108               mov eax, dword ptr [ecx + 8]
// 004c4d76  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4d7a  750f                 jne 0x4c4d8b
// 004c4d7c  8d642400             lea esp, [esp]
// 004c4d80  8bc8                 mov ecx, eax
// 004c4d82  8b4108               mov eax, dword ptr [ecx + 8]
// 004c4d85  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4d89  74f5                 je 0x4c4d80
// 004c4d8b  5f                   pop edi
// 004c4d8c  894e04               mov dword ptr [esi + 4], ecx
// 004c4d8f  5e                   pop esi
// 004c4d90  c3                   ret 
// 004c4d91  8b4004               mov eax, dword ptr [eax + 4]
// 004c4d94  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4d98  751b                 jne 0x4c4db5
// 004c4d9a  8d9b00000000         lea ebx, [ebx]
// 004c4da0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c4da3  3b08                 cmp ecx, dword ptr [eax]
// 004c4da5  750e                 jne 0x4c4db5
// 004c4da7  894604               mov dword ptr [esi + 4], eax
// 004c4daa  8bd0                 mov edx, eax
// 004c4dac  8b4204               mov eax, dword ptr [edx + 4]
// 004c4daf  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4db3  74eb                 je 0x4c4da0
// 004c4db5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c4db8  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c4dbc  75a8                 jne 0x4c4d66
// 004c4dbe  894604               mov dword ptr [esi + 4], eax
// 004c4dc1  5f                   pop edi
// 004c4dc2  5e                   pop esi
// 004c4dc3  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
