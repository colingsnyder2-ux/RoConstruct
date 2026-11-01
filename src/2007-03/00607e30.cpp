// from server: 100% by auto
// roc 2007-03 00607e30  unit: seg_00600000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00607e30
//
// 00607e30  56                   push esi
// 00607e31  8bf1                 mov esi, ecx
// 00607e33  833e00               cmp dword ptr [esi], 0
// 00607e36  57                   push edi
// 00607e37  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 00607e3d  7502                 jne 0x607e41
// 00607e3f  ffd7                 call edi
// 00607e41  8b4604               mov eax, dword ptr [esi + 4]
// 00607e44  80783500             cmp byte ptr [eax + 0x35], 0
// 00607e48  7411                 je 0x607e5b
// 00607e4a  8b4008               mov eax, dword ptr [eax + 8]
// 00607e4d  894604               mov dword ptr [esi + 4], eax
// 00607e50  80783500             cmp byte ptr [eax + 0x35], 0
// 00607e54  745b                 je 0x607eb1
// 00607e56  ffd7                 call edi
// 00607e58  5f                   pop edi
// 00607e59  5e                   pop esi
// 00607e5a  c3                   ret 
// 00607e5b  8b08                 mov ecx, dword ptr [eax]
// 00607e5d  80793500             cmp byte ptr [ecx + 0x35], 0
// 00607e61  751e                 jne 0x607e81
// 00607e63  8b4108               mov eax, dword ptr [ecx + 8]
// 00607e66  80783500             cmp byte ptr [eax + 0x35], 0
// 00607e6a  750f                 jne 0x607e7b
// 00607e6c  8d642400             lea esp, [esp]
// 00607e70  8bc8                 mov ecx, eax
// 00607e72  8b4108               mov eax, dword ptr [ecx + 8]
// 00607e75  80783500             cmp byte ptr [eax + 0x35], 0
// 00607e79  74f5                 je 0x607e70
// 00607e7b  5f                   pop edi
// 00607e7c  894e04               mov dword ptr [esi + 4], ecx
// 00607e7f  5e                   pop esi
// 00607e80  c3                   ret 
// 00607e81  8b4004               mov eax, dword ptr [eax + 4]
// 00607e84  80783500             cmp byte ptr [eax + 0x35], 0
// 00607e88  751b                 jne 0x607ea5
// 00607e8a  8d9b00000000         lea ebx, [ebx]
// 00607e90  8b4e04               mov ecx, dword ptr [esi + 4]
// 00607e93  3b08                 cmp ecx, dword ptr [eax]
// 00607e95  750e                 jne 0x607ea5
// 00607e97  894604               mov dword ptr [esi + 4], eax
// 00607e9a  8bd0                 mov edx, eax
// 00607e9c  8b4204               mov eax, dword ptr [edx + 4]
// 00607e9f  80783500             cmp byte ptr [eax + 0x35], 0
// 00607ea3  74eb                 je 0x607e90
// 00607ea5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00607ea8  80793500             cmp byte ptr [ecx + 0x35], 0
// 00607eac  75a8                 jne 0x607e56
// 00607eae  894604               mov dword ptr [esi + 4], eax
// 00607eb1  5f                   pop edi
// 00607eb2  5e                   pop esi
// 00607eb3  c3                   ret 
// standard library map_int<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
