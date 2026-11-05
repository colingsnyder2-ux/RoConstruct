// from server: 100% by auto
// roc 2007-08 004d07e0  unit: RBX::View::PartChunk  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d07e0
//
// 004d07e0  56                   push esi
// 004d07e1  8bf1                 mov esi, ecx
// 004d07e3  833e00               cmp dword ptr [esi], 0
// 004d07e6  57                   push edi
// 004d07e7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004d07ed  7502                 jne 0x4d07f1
// 004d07ef  ffd7                 call edi
// 004d07f1  8b4604               mov eax, dword ptr [esi + 4]
// 004d07f4  80782900             cmp byte ptr [eax + 0x29], 0
// 004d07f8  7411                 je 0x4d080b
// 004d07fa  8b4008               mov eax, dword ptr [eax + 8]
// 004d07fd  894604               mov dword ptr [esi + 4], eax
// 004d0800  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0804  745b                 je 0x4d0861
// 004d0806  ffd7                 call edi
// 004d0808  5f                   pop edi
// 004d0809  5e                   pop esi
// 004d080a  c3                   ret 
// 004d080b  8b08                 mov ecx, dword ptr [eax]
// 004d080d  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d0811  751e                 jne 0x4d0831
// 004d0813  8b4108               mov eax, dword ptr [ecx + 8]
// 004d0816  80782900             cmp byte ptr [eax + 0x29], 0
// 004d081a  750f                 jne 0x4d082b
// 004d081c  8d642400             lea esp, [esp]
// 004d0820  8bc8                 mov ecx, eax
// 004d0822  8b4108               mov eax, dword ptr [ecx + 8]
// 004d0825  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0829  74f5                 je 0x4d0820
// 004d082b  5f                   pop edi
// 004d082c  894e04               mov dword ptr [esi + 4], ecx
// 004d082f  5e                   pop esi
// 004d0830  c3                   ret 
// 004d0831  8b4004               mov eax, dword ptr [eax + 4]
// 004d0834  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0838  751b                 jne 0x4d0855
// 004d083a  8d9b00000000         lea ebx, [ebx]
// 004d0840  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0843  3b08                 cmp ecx, dword ptr [eax]
// 004d0845  750e                 jne 0x4d0855
// 004d0847  894604               mov dword ptr [esi + 4], eax
// 004d084a  8bd0                 mov edx, eax
// 004d084c  8b4204               mov eax, dword ptr [edx + 4]
// 004d084f  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0853  74eb                 je 0x4d0840
// 004d0855  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0858  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d085c  75a8                 jne 0x4d0806
// 004d085e  894604               mov dword ptr [esi + 4], eax
// 004d0861  5f                   pop edi
// 004d0862  5e                   pop esi
// 004d0863  c3                   ret 
// standard library map_int<pod24> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
