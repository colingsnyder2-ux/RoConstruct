// from server: 100% by auto
// roc 2007-08 005453a0  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005453a0
//
// 005453a0  56                   push esi
// 005453a1  8bf1                 mov esi, ecx
// 005453a3  833e00               cmp dword ptr [esi], 0
// 005453a6  57                   push edi
// 005453a7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 005453ad  7502                 jne 0x5453b1
// 005453af  ffd7                 call edi
// 005453b1  8b4604               mov eax, dword ptr [esi + 4]
// 005453b4  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005453b8  7411                 je 0x5453cb
// 005453ba  8b4008               mov eax, dword ptr [eax + 8]
// 005453bd  894604               mov dword ptr [esi + 4], eax
// 005453c0  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005453c4  745b                 je 0x545421
// 005453c6  ffd7                 call edi
// 005453c8  5f                   pop edi
// 005453c9  5e                   pop esi
// 005453ca  c3                   ret 
// 005453cb  8b08                 mov ecx, dword ptr [eax]
// 005453cd  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005453d1  751e                 jne 0x5453f1
// 005453d3  8b4108               mov eax, dword ptr [ecx + 8]
// 005453d6  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005453da  750f                 jne 0x5453eb
// 005453dc  8d642400             lea esp, [esp]
// 005453e0  8bc8                 mov ecx, eax
// 005453e2  8b4108               mov eax, dword ptr [ecx + 8]
// 005453e5  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005453e9  74f5                 je 0x5453e0
// 005453eb  5f                   pop edi
// 005453ec  894e04               mov dword ptr [esi + 4], ecx
// 005453ef  5e                   pop esi
// 005453f0  c3                   ret 
// 005453f1  8b4004               mov eax, dword ptr [eax + 4]
// 005453f4  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005453f8  751b                 jne 0x545415
// 005453fa  8d9b00000000         lea ebx, [ebx]
// 00545400  8b4e04               mov ecx, dword ptr [esi + 4]
// 00545403  3b08                 cmp ecx, dword ptr [eax]
// 00545405  750e                 jne 0x545415
// 00545407  894604               mov dword ptr [esi + 4], eax
// 0054540a  8bd0                 mov edx, eax
// 0054540c  8b4204               mov eax, dword ptr [edx + 4]
// 0054540f  80783d00             cmp byte ptr [eax + 0x3d], 0
// 00545413  74eb                 je 0x545400
// 00545415  8b4e04               mov ecx, dword ptr [esi + 4]
// 00545418  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0054541c  75a8                 jne 0x5453c6
// 0054541e  894604               mov dword ptr [esi + 4], eax
// 00545421  5f                   pop edi
// 00545422  5e                   pop esi
// 00545423  c3                   ret 
// standard library map_str<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
