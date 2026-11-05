// from server: 100% by auto
// roc 2009-06 0048b7a0  unit: Ogre::RbxManualTextureLoader  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b7a0
//
// 0048b7a0  56                   push esi
// 0048b7a1  8bf1                 mov esi, ecx
// 0048b7a3  833e00               cmp dword ptr [esi], 0
// 0048b7a6  57                   push edi
// 0048b7a7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0048b7ad  7502                 jne 0x48b7b1
// 0048b7af  ffd7                 call edi
// 0048b7b1  8b4604               mov eax, dword ptr [esi + 4]
// 0048b7b4  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b7b8  7405                 je 0x48b7bf
// 0048b7ba  ffd7                 call edi
// 0048b7bc  5f                   pop edi
// 0048b7bd  5e                   pop esi
// 0048b7be  c3                   ret 
// 0048b7bf  8b4808               mov ecx, dword ptr [eax + 8]
// 0048b7c2  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b7c6  7518                 jne 0x48b7e0
// 0048b7c8  8b01                 mov eax, dword ptr [ecx]
// 0048b7ca  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b7ce  750a                 jne 0x48b7da
// 0048b7d0  8bc8                 mov ecx, eax
// 0048b7d2  8b01                 mov eax, dword ptr [ecx]
// 0048b7d4  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b7d8  74f6                 je 0x48b7d0
// 0048b7da  5f                   pop edi
// 0048b7db  894e04               mov dword ptr [esi + 4], ecx
// 0048b7de  5e                   pop esi
// 0048b7df  c3                   ret 
// 0048b7e0  8b4004               mov eax, dword ptr [eax + 4]
// 0048b7e3  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b7e7  751d                 jne 0x48b806
// 0048b7e9  8da42400000000       lea esp, [esp]
// 0048b7f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048b7f3  3b4808               cmp ecx, dword ptr [eax + 8]
// 0048b7f6  750e                 jne 0x48b806
// 0048b7f8  894604               mov dword ptr [esi + 4], eax
// 0048b7fb  8bd0                 mov edx, eax
// 0048b7fd  8b4204               mov eax, dword ptr [edx + 4]
// 0048b800  80786900             cmp byte ptr [eax + 0x69], 0
// 0048b804  74ea                 je 0x48b7f0
// 0048b806  5f                   pop edi
// 0048b807  894604               mov dword ptr [esi + 4], eax
// 0048b80a  5e                   pop esi
// 0048b80b  c3                   ret 
// standard library map_str<pod64> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
