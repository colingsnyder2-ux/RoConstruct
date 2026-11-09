// from server: 100% by auto
// roc 2010-06 0076b050  unit: RBX::ImageButton  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076b050
//
// 0076b050  56                   push esi
// 0076b051  8bf1                 mov esi, ecx
// 0076b053  833e00               cmp dword ptr [esi], 0
// 0076b056  57                   push edi
// 0076b057  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0076b05d  7502                 jne 0x76b061
// 0076b05f  ffd7                 call edi
// 0076b061  8b4604               mov eax, dword ptr [esi + 4]
// 0076b064  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b068  7411                 je 0x76b07b
// 0076b06a  8b4008               mov eax, dword ptr [eax + 8]
// 0076b06d  894604               mov dword ptr [esi + 4], eax
// 0076b070  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b074  745b                 je 0x76b0d1
// 0076b076  ffd7                 call edi
// 0076b078  5f                   pop edi
// 0076b079  5e                   pop esi
// 0076b07a  c3                   ret 
// 0076b07b  8b08                 mov ecx, dword ptr [eax]
// 0076b07d  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076b081  751e                 jne 0x76b0a1
// 0076b083  8b4108               mov eax, dword ptr [ecx + 8]
// 0076b086  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b08a  750f                 jne 0x76b09b
// 0076b08c  8d642400             lea esp, [esp]
// 0076b090  8bc8                 mov ecx, eax
// 0076b092  8b4108               mov eax, dword ptr [ecx + 8]
// 0076b095  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b099  74f5                 je 0x76b090
// 0076b09b  5f                   pop edi
// 0076b09c  894e04               mov dword ptr [esi + 4], ecx
// 0076b09f  5e                   pop esi
// 0076b0a0  c3                   ret 
// 0076b0a1  8b4004               mov eax, dword ptr [eax + 4]
// 0076b0a4  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b0a8  751b                 jne 0x76b0c5
// 0076b0aa  8d9b00000000         lea ebx, [ebx]
// 0076b0b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076b0b3  3b08                 cmp ecx, dword ptr [eax]
// 0076b0b5  750e                 jne 0x76b0c5
// 0076b0b7  894604               mov dword ptr [esi + 4], eax
// 0076b0ba  8bd0                 mov edx, eax
// 0076b0bc  8b4204               mov eax, dword ptr [edx + 4]
// 0076b0bf  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b0c3  74eb                 je 0x76b0b0
// 0076b0c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076b0c8  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076b0cc  75a8                 jne 0x76b076
// 0076b0ce  894604               mov dword ptr [esi + 4], eax
// 0076b0d1  5f                   pop edi
// 0076b0d2  5e                   pop esi
// 0076b0d3  c3                   ret 
// standard library map_str<pod36> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
