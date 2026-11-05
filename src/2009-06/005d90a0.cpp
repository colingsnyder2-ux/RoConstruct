// from server: 100% by auto
// roc 2009-06 005d90a0  unit: VAuthoringSettings::?$BoundPropGetSet  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d90a0
//
// 005d90a0  56                   push esi
// 005d90a1  8bf1                 mov esi, ecx
// 005d90a3  833e00               cmp dword ptr [esi], 0
// 005d90a6  57                   push edi
// 005d90a7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 005d90ad  7502                 jne 0x5d90b1
// 005d90af  ffd7                 call edi
// 005d90b1  8b4604               mov eax, dword ptr [esi + 4]
// 005d90b4  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d90b8  7411                 je 0x5d90cb
// 005d90ba  8b4008               mov eax, dword ptr [eax + 8]
// 005d90bd  894604               mov dword ptr [esi + 4], eax
// 005d90c0  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d90c4  745b                 je 0x5d9121
// 005d90c6  ffd7                 call edi
// 005d90c8  5f                   pop edi
// 005d90c9  5e                   pop esi
// 005d90ca  c3                   ret 
// 005d90cb  8b08                 mov ecx, dword ptr [eax]
// 005d90cd  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d90d1  751e                 jne 0x5d90f1
// 005d90d3  8b4108               mov eax, dword ptr [ecx + 8]
// 005d90d6  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d90da  750f                 jne 0x5d90eb
// 005d90dc  8d642400             lea esp, [esp]
// 005d90e0  8bc8                 mov ecx, eax
// 005d90e2  8b4108               mov eax, dword ptr [ecx + 8]
// 005d90e5  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d90e9  74f5                 je 0x5d90e0
// 005d90eb  5f                   pop edi
// 005d90ec  894e04               mov dword ptr [esi + 4], ecx
// 005d90ef  5e                   pop esi
// 005d90f0  c3                   ret 
// 005d90f1  8b4004               mov eax, dword ptr [eax + 4]
// 005d90f4  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d90f8  751b                 jne 0x5d9115
// 005d90fa  8d9b00000000         lea ebx, [ebx]
// 005d9100  8b4e04               mov ecx, dword ptr [esi + 4]
// 005d9103  3b08                 cmp ecx, dword ptr [eax]
// 005d9105  750e                 jne 0x5d9115
// 005d9107  894604               mov dword ptr [esi + 4], eax
// 005d910a  8bd0                 mov edx, eax
// 005d910c  8b4204               mov eax, dword ptr [edx + 4]
// 005d910f  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d9113  74eb                 je 0x5d9100
// 005d9115  8b4e04               mov ecx, dword ptr [esi + 4]
// 005d9118  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d911c  75a8                 jne 0x5d90c6
// 005d911e  894604               mov dword ptr [esi + 4], eax
// 005d9121  5f                   pop edi
// 005d9122  5e                   pop esi
// 005d9123  c3                   ret 
// standard library map_str<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
