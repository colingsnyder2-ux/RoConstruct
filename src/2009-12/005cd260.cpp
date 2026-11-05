// from server: 100% by auto
// roc 2009-12 005cd260  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd260
//
// 005cd260  56                   push esi
// 005cd261  8bf1                 mov esi, ecx
// 005cd263  833e00               cmp dword ptr [esi], 0
// 005cd266  57                   push edi
// 005cd267  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 005cd26d  7502                 jne 0x5cd271
// 005cd26f  ffd7                 call edi
// 005cd271  8b4604               mov eax, dword ptr [esi + 4]
// 005cd274  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd278  7405                 je 0x5cd27f
// 005cd27a  ffd7                 call edi
// 005cd27c  5f                   pop edi
// 005cd27d  5e                   pop esi
// 005cd27e  c3                   ret 
// 005cd27f  8b4808               mov ecx, dword ptr [eax + 8]
// 005cd282  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cd286  7518                 jne 0x5cd2a0
// 005cd288  8b01                 mov eax, dword ptr [ecx]
// 005cd28a  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd28e  750a                 jne 0x5cd29a
// 005cd290  8bc8                 mov ecx, eax
// 005cd292  8b01                 mov eax, dword ptr [ecx]
// 005cd294  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd298  74f6                 je 0x5cd290
// 005cd29a  5f                   pop edi
// 005cd29b  894e04               mov dword ptr [esi + 4], ecx
// 005cd29e  5e                   pop esi
// 005cd29f  c3                   ret 
// 005cd2a0  8b4004               mov eax, dword ptr [eax + 4]
// 005cd2a3  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd2a7  751d                 jne 0x5cd2c6
// 005cd2a9  8da42400000000       lea esp, [esp]
// 005cd2b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cd2b3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005cd2b6  750e                 jne 0x5cd2c6
// 005cd2b8  894604               mov dword ptr [esi + 4], eax
// 005cd2bb  8bd0                 mov edx, eax
// 005cd2bd  8b4204               mov eax, dword ptr [edx + 4]
// 005cd2c0  80782900             cmp byte ptr [eax + 0x29], 0
// 005cd2c4  74ea                 je 0x5cd2b0
// 005cd2c6  5f                   pop edi
// 005cd2c7  894604               mov dword ptr [esi + 4], eax
// 005cd2ca  5e                   pop esi
// 005cd2cb  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
