// from server: 100% by auto
// roc 2007-08 0060ca40  unit: RBX::Block  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060ca40
//
// 0060ca40  56                   push esi
// 0060ca41  8bf1                 mov esi, ecx
// 0060ca43  833e00               cmp dword ptr [esi], 0
// 0060ca46  57                   push edi
// 0060ca47  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0060ca4d  7502                 jne 0x60ca51
// 0060ca4f  ffd7                 call edi
// 0060ca51  8b4604               mov eax, dword ptr [esi + 4]
// 0060ca54  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060ca58  7411                 je 0x60ca6b
// 0060ca5a  8b4008               mov eax, dword ptr [eax + 8]
// 0060ca5d  894604               mov dword ptr [esi + 4], eax
// 0060ca60  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060ca64  745b                 je 0x60cac1
// 0060ca66  ffd7                 call edi
// 0060ca68  5f                   pop edi
// 0060ca69  5e                   pop esi
// 0060ca6a  c3                   ret 
// 0060ca6b  8b08                 mov ecx, dword ptr [eax]
// 0060ca6d  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0060ca71  751e                 jne 0x60ca91
// 0060ca73  8b4108               mov eax, dword ptr [ecx + 8]
// 0060ca76  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060ca7a  750f                 jne 0x60ca8b
// 0060ca7c  8d642400             lea esp, [esp]
// 0060ca80  8bc8                 mov ecx, eax
// 0060ca82  8b4108               mov eax, dword ptr [ecx + 8]
// 0060ca85  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060ca89  74f5                 je 0x60ca80
// 0060ca8b  5f                   pop edi
// 0060ca8c  894e04               mov dword ptr [esi + 4], ecx
// 0060ca8f  5e                   pop esi
// 0060ca90  c3                   ret 
// 0060ca91  8b4004               mov eax, dword ptr [eax + 4]
// 0060ca94  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060ca98  751b                 jne 0x60cab5
// 0060ca9a  8d9b00000000         lea ebx, [ebx]
// 0060caa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060caa3  3b08                 cmp ecx, dword ptr [eax]
// 0060caa5  750e                 jne 0x60cab5
// 0060caa7  894604               mov dword ptr [esi + 4], eax
// 0060caaa  8bd0                 mov edx, eax
// 0060caac  8b4204               mov eax, dword ptr [edx + 4]
// 0060caaf  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060cab3  74eb                 je 0x60caa0
// 0060cab5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060cab8  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0060cabc  75a8                 jne 0x60ca66
// 0060cabe  894604               mov dword ptr [esi + 4], eax
// 0060cac1  5f                   pop edi
// 0060cac2  5e                   pop esi
// 0060cac3  c3                   ret 
// standard library map_int<pod12> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
