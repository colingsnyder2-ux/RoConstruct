// from server: 100% by auto
// roc 2008-06 006510f0  unit: RBX::ScoreHud  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006510f0
//
// 006510f0  56                   push esi
// 006510f1  8bf1                 mov esi, ecx
// 006510f3  833e00               cmp dword ptr [esi], 0
// 006510f6  57                   push edi
// 006510f7  8b3d90288000         mov edi, dword ptr [0x802890]
// 006510fd  7502                 jne 0x651101
// 006510ff  ffd7                 call edi
// 00651101  8b4604               mov eax, dword ptr [esi + 4]
// 00651104  80784900             cmp byte ptr [eax + 0x49], 0
// 00651108  7405                 je 0x65110f
// 0065110a  ffd7                 call edi
// 0065110c  5f                   pop edi
// 0065110d  5e                   pop esi
// 0065110e  c3                   ret 
// 0065110f  8b4808               mov ecx, dword ptr [eax + 8]
// 00651112  80794900             cmp byte ptr [ecx + 0x49], 0
// 00651116  7518                 jne 0x651130
// 00651118  8b01                 mov eax, dword ptr [ecx]
// 0065111a  80784900             cmp byte ptr [eax + 0x49], 0
// 0065111e  750a                 jne 0x65112a
// 00651120  8bc8                 mov ecx, eax
// 00651122  8b01                 mov eax, dword ptr [ecx]
// 00651124  80784900             cmp byte ptr [eax + 0x49], 0
// 00651128  74f6                 je 0x651120
// 0065112a  5f                   pop edi
// 0065112b  894e04               mov dword ptr [esi + 4], ecx
// 0065112e  5e                   pop esi
// 0065112f  c3                   ret 
// 00651130  8b4004               mov eax, dword ptr [eax + 4]
// 00651133  80784900             cmp byte ptr [eax + 0x49], 0
// 00651137  751d                 jne 0x651156
// 00651139  8da42400000000       lea esp, [esp]
// 00651140  8b4e04               mov ecx, dword ptr [esi + 4]
// 00651143  3b4808               cmp ecx, dword ptr [eax + 8]
// 00651146  750e                 jne 0x651156
// 00651148  894604               mov dword ptr [esi + 4], eax
// 0065114b  8bd0                 mov edx, eax
// 0065114d  8b4204               mov eax, dword ptr [edx + 4]
// 00651150  80784900             cmp byte ptr [eax + 0x49], 0
// 00651154  74ea                 je 0x651140
// 00651156  5f                   pop edi
// 00651157  894604               mov dword ptr [esi + 4], eax
// 0065115a  5e                   pop esi
// 0065115b  c3                   ret 
// standard library map_str<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
