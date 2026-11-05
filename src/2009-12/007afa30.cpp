// from server: 100% by auto
// roc 2009-12 007afa30  unit: RBX::Block  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007afa30
//
// 007afa30  56                   push esi
// 007afa31  8bf1                 mov esi, ecx
// 007afa33  833e00               cmp dword ptr [esi], 0
// 007afa36  57                   push edi
// 007afa37  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 007afa3d  7502                 jne 0x7afa41
// 007afa3f  ffd7                 call edi
// 007afa41  8b4604               mov eax, dword ptr [esi + 4]
// 007afa44  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afa48  7411                 je 0x7afa5b
// 007afa4a  8b4008               mov eax, dword ptr [eax + 8]
// 007afa4d  894604               mov dword ptr [esi + 4], eax
// 007afa50  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afa54  745b                 je 0x7afab1
// 007afa56  ffd7                 call edi
// 007afa58  5f                   pop edi
// 007afa59  5e                   pop esi
// 007afa5a  c3                   ret 
// 007afa5b  8b08                 mov ecx, dword ptr [eax]
// 007afa5d  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007afa61  751e                 jne 0x7afa81
// 007afa63  8b4108               mov eax, dword ptr [ecx + 8]
// 007afa66  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afa6a  750f                 jne 0x7afa7b
// 007afa6c  8d642400             lea esp, [esp]
// 007afa70  8bc8                 mov ecx, eax
// 007afa72  8b4108               mov eax, dword ptr [ecx + 8]
// 007afa75  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afa79  74f5                 je 0x7afa70
// 007afa7b  5f                   pop edi
// 007afa7c  894e04               mov dword ptr [esi + 4], ecx
// 007afa7f  5e                   pop esi
// 007afa80  c3                   ret 
// 007afa81  8b4004               mov eax, dword ptr [eax + 4]
// 007afa84  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afa88  751b                 jne 0x7afaa5
// 007afa8a  8d9b00000000         lea ebx, [ebx]
// 007afa90  8b4e04               mov ecx, dword ptr [esi + 4]
// 007afa93  3b08                 cmp ecx, dword ptr [eax]
// 007afa95  750e                 jne 0x7afaa5
// 007afa97  894604               mov dword ptr [esi + 4], eax
// 007afa9a  8bd0                 mov edx, eax
// 007afa9c  8b4204               mov eax, dword ptr [edx + 4]
// 007afa9f  80781d00             cmp byte ptr [eax + 0x1d], 0
// 007afaa3  74eb                 je 0x7afa90
// 007afaa5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007afaa8  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007afaac  75a8                 jne 0x7afa56
// 007afaae  894604               mov dword ptr [esi + 4], eax
// 007afab1  5f                   pop edi
// 007afab2  5e                   pop esi
// 007afab3  c3                   ret 
// standard library map_int<pod12> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
