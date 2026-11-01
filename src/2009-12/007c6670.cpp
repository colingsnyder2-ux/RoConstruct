// from server: 100% by auto
// roc 2009-12 007c6670  unit: RBX::ScoreHud  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6670
//
// 007c6670  56                   push esi
// 007c6671  8bf1                 mov esi, ecx
// 007c6673  833e00               cmp dword ptr [esi], 0
// 007c6676  57                   push edi
// 007c6677  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 007c667d  7502                 jne 0x7c6681
// 007c667f  ffd7                 call edi
// 007c6681  8b4604               mov eax, dword ptr [esi + 4]
// 007c6684  80784900             cmp byte ptr [eax + 0x49], 0
// 007c6688  7405                 je 0x7c668f
// 007c668a  ffd7                 call edi
// 007c668c  5f                   pop edi
// 007c668d  5e                   pop esi
// 007c668e  c3                   ret 
// 007c668f  8b4808               mov ecx, dword ptr [eax + 8]
// 007c6692  80794900             cmp byte ptr [ecx + 0x49], 0
// 007c6696  7518                 jne 0x7c66b0
// 007c6698  8b01                 mov eax, dword ptr [ecx]
// 007c669a  80784900             cmp byte ptr [eax + 0x49], 0
// 007c669e  750a                 jne 0x7c66aa
// 007c66a0  8bc8                 mov ecx, eax
// 007c66a2  8b01                 mov eax, dword ptr [ecx]
// 007c66a4  80784900             cmp byte ptr [eax + 0x49], 0
// 007c66a8  74f6                 je 0x7c66a0
// 007c66aa  5f                   pop edi
// 007c66ab  894e04               mov dword ptr [esi + 4], ecx
// 007c66ae  5e                   pop esi
// 007c66af  c3                   ret 
// 007c66b0  8b4004               mov eax, dword ptr [eax + 4]
// 007c66b3  80784900             cmp byte ptr [eax + 0x49], 0
// 007c66b7  751d                 jne 0x7c66d6
// 007c66b9  8da42400000000       lea esp, [esp]
// 007c66c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c66c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 007c66c6  750e                 jne 0x7c66d6
// 007c66c8  894604               mov dword ptr [esi + 4], eax
// 007c66cb  8bd0                 mov edx, eax
// 007c66cd  8b4204               mov eax, dword ptr [edx + 4]
// 007c66d0  80784900             cmp byte ptr [eax + 0x49], 0
// 007c66d4  74ea                 je 0x7c66c0
// 007c66d6  5f                   pop edi
// 007c66d7  894604               mov dword ptr [esi + 4], eax
// 007c66da  5e                   pop esi
// 007c66db  c3                   ret 
// standard library map_str<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
