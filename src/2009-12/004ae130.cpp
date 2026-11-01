// from server: 100% by auto
// roc 2009-12 004ae130  unit: Ogre::RbxManualTextureLoader  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae130
//
// 004ae130  56                   push esi
// 004ae131  8bf1                 mov esi, ecx
// 004ae133  833e00               cmp dword ptr [esi], 0
// 004ae136  57                   push edi
// 004ae137  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 004ae13d  7502                 jne 0x4ae141
// 004ae13f  ffd7                 call edi
// 004ae141  8b4604               mov eax, dword ptr [esi + 4]
// 004ae144  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae148  7405                 je 0x4ae14f
// 004ae14a  ffd7                 call edi
// 004ae14c  5f                   pop edi
// 004ae14d  5e                   pop esi
// 004ae14e  c3                   ret 
// 004ae14f  8b4808               mov ecx, dword ptr [eax + 8]
// 004ae152  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae156  7518                 jne 0x4ae170
// 004ae158  8b01                 mov eax, dword ptr [ecx]
// 004ae15a  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae15e  750a                 jne 0x4ae16a
// 004ae160  8bc8                 mov ecx, eax
// 004ae162  8b01                 mov eax, dword ptr [ecx]
// 004ae164  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae168  74f6                 je 0x4ae160
// 004ae16a  5f                   pop edi
// 004ae16b  894e04               mov dword ptr [esi + 4], ecx
// 004ae16e  5e                   pop esi
// 004ae16f  c3                   ret 
// 004ae170  8b4004               mov eax, dword ptr [eax + 4]
// 004ae173  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae177  751d                 jne 0x4ae196
// 004ae179  8da42400000000       lea esp, [esp]
// 004ae180  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae183  3b4808               cmp ecx, dword ptr [eax + 8]
// 004ae186  750e                 jne 0x4ae196
// 004ae188  894604               mov dword ptr [esi + 4], eax
// 004ae18b  8bd0                 mov edx, eax
// 004ae18d  8b4204               mov eax, dword ptr [edx + 4]
// 004ae190  80786900             cmp byte ptr [eax + 0x69], 0
// 004ae194  74ea                 je 0x4ae180
// 004ae196  5f                   pop edi
// 004ae197  894604               mov dword ptr [esi + 4], eax
// 004ae19a  5e                   pop esi
// 004ae19b  c3                   ret 
// standard library map_str<pod64> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
