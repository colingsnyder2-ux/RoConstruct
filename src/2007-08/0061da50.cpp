// from server: 100% by auto
// roc 2007-08 0061da50  unit: RBX::ChatOutput  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061da50
//
// 0061da50  56                   push esi
// 0061da51  8bf1                 mov esi, ecx
// 0061da53  833e00               cmp dword ptr [esi], 0
// 0061da56  57                   push edi
// 0061da57  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0061da5d  7502                 jne 0x61da61
// 0061da5f  ffd7                 call edi
// 0061da61  8b4604               mov eax, dword ptr [esi + 4]
// 0061da64  80783500             cmp byte ptr [eax + 0x35], 0
// 0061da68  7411                 je 0x61da7b
// 0061da6a  8b4008               mov eax, dword ptr [eax + 8]
// 0061da6d  894604               mov dword ptr [esi + 4], eax
// 0061da70  80783500             cmp byte ptr [eax + 0x35], 0
// 0061da74  745b                 je 0x61dad1
// 0061da76  ffd7                 call edi
// 0061da78  5f                   pop edi
// 0061da79  5e                   pop esi
// 0061da7a  c3                   ret 
// 0061da7b  8b08                 mov ecx, dword ptr [eax]
// 0061da7d  80793500             cmp byte ptr [ecx + 0x35], 0
// 0061da81  751e                 jne 0x61daa1
// 0061da83  8b4108               mov eax, dword ptr [ecx + 8]
// 0061da86  80783500             cmp byte ptr [eax + 0x35], 0
// 0061da8a  750f                 jne 0x61da9b
// 0061da8c  8d642400             lea esp, [esp]
// 0061da90  8bc8                 mov ecx, eax
// 0061da92  8b4108               mov eax, dword ptr [ecx + 8]
// 0061da95  80783500             cmp byte ptr [eax + 0x35], 0
// 0061da99  74f5                 je 0x61da90
// 0061da9b  5f                   pop edi
// 0061da9c  894e04               mov dword ptr [esi + 4], ecx
// 0061da9f  5e                   pop esi
// 0061daa0  c3                   ret 
// 0061daa1  8b4004               mov eax, dword ptr [eax + 4]
// 0061daa4  80783500             cmp byte ptr [eax + 0x35], 0
// 0061daa8  751b                 jne 0x61dac5
// 0061daaa  8d9b00000000         lea ebx, [ebx]
// 0061dab0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061dab3  3b08                 cmp ecx, dword ptr [eax]
// 0061dab5  750e                 jne 0x61dac5
// 0061dab7  894604               mov dword ptr [esi + 4], eax
// 0061daba  8bd0                 mov edx, eax
// 0061dabc  8b4204               mov eax, dword ptr [edx + 4]
// 0061dabf  80783500             cmp byte ptr [eax + 0x35], 0
// 0061dac3  74eb                 je 0x61dab0
// 0061dac5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061dac8  80793500             cmp byte ptr [ecx + 0x35], 0
// 0061dacc  75a8                 jne 0x61da76
// 0061dace  894604               mov dword ptr [esi + 4], eax
// 0061dad1  5f                   pop edi
// 0061dad2  5e                   pop esi
// 0061dad3  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
