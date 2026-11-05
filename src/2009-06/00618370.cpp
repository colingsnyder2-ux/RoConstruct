// from server: 100% by auto
// roc 2009-06 00618370  unit: RBX::Script  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618370
//
// 00618370  56                   push esi
// 00618371  8bf1                 mov esi, ecx
// 00618373  833e00               cmp dword ptr [esi], 0
// 00618376  57                   push edi
// 00618377  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0061837d  7502                 jne 0x618381
// 0061837f  ffd7                 call edi
// 00618381  8b4604               mov eax, dword ptr [esi + 4]
// 00618384  80784900             cmp byte ptr [eax + 0x49], 0
// 00618388  7405                 je 0x61838f
// 0061838a  ffd7                 call edi
// 0061838c  5f                   pop edi
// 0061838d  5e                   pop esi
// 0061838e  c3                   ret 
// 0061838f  8b4808               mov ecx, dword ptr [eax + 8]
// 00618392  80794900             cmp byte ptr [ecx + 0x49], 0
// 00618396  7518                 jne 0x6183b0
// 00618398  8b01                 mov eax, dword ptr [ecx]
// 0061839a  80784900             cmp byte ptr [eax + 0x49], 0
// 0061839e  750a                 jne 0x6183aa
// 006183a0  8bc8                 mov ecx, eax
// 006183a2  8b01                 mov eax, dword ptr [ecx]
// 006183a4  80784900             cmp byte ptr [eax + 0x49], 0
// 006183a8  74f6                 je 0x6183a0
// 006183aa  5f                   pop edi
// 006183ab  894e04               mov dword ptr [esi + 4], ecx
// 006183ae  5e                   pop esi
// 006183af  c3                   ret 
// 006183b0  8b4004               mov eax, dword ptr [eax + 4]
// 006183b3  80784900             cmp byte ptr [eax + 0x49], 0
// 006183b7  751d                 jne 0x6183d6
// 006183b9  8da42400000000       lea esp, [esp]
// 006183c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006183c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 006183c6  750e                 jne 0x6183d6
// 006183c8  894604               mov dword ptr [esi + 4], eax
// 006183cb  8bd0                 mov edx, eax
// 006183cd  8b4204               mov eax, dword ptr [edx + 4]
// 006183d0  80784900             cmp byte ptr [eax + 0x49], 0
// 006183d4  74ea                 je 0x6183c0
// 006183d6  5f                   pop edi
// 006183d7  894604               mov dword ptr [esi + 4], eax
// 006183da  5e                   pop esi
// 006183db  c3                   ret 
// standard library map_str<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
