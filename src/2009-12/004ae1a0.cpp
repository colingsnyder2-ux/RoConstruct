// from server: 100% by auto
// roc 2009-12 004ae1a0  unit: Ogre::RbxManualTextureLoader  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae1a0
//
// 004ae1a0  56                   push esi
// 004ae1a1  8bf1                 mov esi, ecx
// 004ae1a3  833e00               cmp dword ptr [esi], 0
// 004ae1a6  57                   push edi
// 004ae1a7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 004ae1ad  7502                 jne 0x4ae1b1
// 004ae1af  ffd7                 call edi
// 004ae1b1  8b4604               mov eax, dword ptr [esi + 4]
// 004ae1b4  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae1b8  7411                 je 0x4ae1cb
// 004ae1ba  8b4008               mov eax, dword ptr [eax + 8]
// 004ae1bd  894604               mov dword ptr [esi + 4], eax
// 004ae1c0  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae1c4  745b                 je 0x4ae221
// 004ae1c6  ffd7                 call edi
// 004ae1c8  5f                   pop edi
// 004ae1c9  5e                   pop esi
// 004ae1ca  c3                   ret 
// 004ae1cb  8b08                 mov ecx, dword ptr [eax]
// 004ae1cd  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae1d1  751e                 jne 0x4ae1f1
// 004ae1d3  8b4108               mov eax, dword ptr [ecx + 8]
// 004ae1d6  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae1da  750f                 jne 0x4ae1eb
// 004ae1dc  8d642400             lea esp, [esp]
// 004ae1e0  8bc8                 mov ecx, eax
// 004ae1e2  8b4108               mov eax, dword ptr [ecx + 8]
// 004ae1e5  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae1e9  74f5                 je 0x4ae1e0
// 004ae1eb  5f                   pop edi
// 004ae1ec  894e04               mov dword ptr [esi + 4], ecx
// 004ae1ef  5e                   pop esi
// 004ae1f0  c3                   ret 
// 004ae1f1  8b4004               mov eax, dword ptr [eax + 4]
// 004ae1f4  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae1f8  751b                 jne 0x4ae215
// 004ae1fa  8d9b00000000         lea ebx, [ebx]
// 004ae200  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae203  3b08                 cmp ecx, dword ptr [eax]
// 004ae205  750e                 jne 0x4ae215
// 004ae207  894604               mov dword ptr [esi + 4], eax
// 004ae20a  8bd0                 mov edx, eax
// 004ae20c  8b4204               mov eax, dword ptr [edx + 4]
// 004ae20f  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae213  74eb                 je 0x4ae200
// 004ae215  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae218  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae21c  75a8                 jne 0x4ae1c6
// 004ae21e  894604               mov dword ptr [esi + 4], eax
// 004ae221  5f                   pop edi
// 004ae222  5e                   pop esi
// 004ae223  c3                   ret 
// standard library map_str<pod64> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
