// from server: 100% by auto
// roc 2010-06 00413c40  unit: CopyVerb  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413c40
//
// 00413c40  56                   push esi
// 00413c41  8bf1                 mov esi, ecx
// 00413c43  833e00               cmp dword ptr [esi], 0
// 00413c46  57                   push edi
// 00413c47  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00413c4d  7502                 jne 0x413c51
// 00413c4f  ffd7                 call edi
// 00413c51  8b4604               mov eax, dword ptr [esi + 4]
// 00413c54  80784500             cmp byte ptr [eax + 0x45], 0
// 00413c58  7405                 je 0x413c5f
// 00413c5a  ffd7                 call edi
// 00413c5c  5f                   pop edi
// 00413c5d  5e                   pop esi
// 00413c5e  c3                   ret 
// 00413c5f  8b4808               mov ecx, dword ptr [eax + 8]
// 00413c62  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413c66  7518                 jne 0x413c80
// 00413c68  8b01                 mov eax, dword ptr [ecx]
// 00413c6a  80784500             cmp byte ptr [eax + 0x45], 0
// 00413c6e  750a                 jne 0x413c7a
// 00413c70  8bc8                 mov ecx, eax
// 00413c72  8b01                 mov eax, dword ptr [ecx]
// 00413c74  80784500             cmp byte ptr [eax + 0x45], 0
// 00413c78  74f6                 je 0x413c70
// 00413c7a  5f                   pop edi
// 00413c7b  894e04               mov dword ptr [esi + 4], ecx
// 00413c7e  5e                   pop esi
// 00413c7f  c3                   ret 
// 00413c80  8b4004               mov eax, dword ptr [eax + 4]
// 00413c83  80784500             cmp byte ptr [eax + 0x45], 0
// 00413c87  751d                 jne 0x413ca6
// 00413c89  8da42400000000       lea esp, [esp]
// 00413c90  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413c93  3b4808               cmp ecx, dword ptr [eax + 8]
// 00413c96  750e                 jne 0x413ca6
// 00413c98  894604               mov dword ptr [esi + 4], eax
// 00413c9b  8bd0                 mov edx, eax
// 00413c9d  8b4204               mov eax, dword ptr [edx + 4]
// 00413ca0  80784500             cmp byte ptr [eax + 0x45], 0
// 00413ca4  74ea                 je 0x413c90
// 00413ca6  5f                   pop edi
// 00413ca7  894604               mov dword ptr [esi + 4], eax
// 00413caa  5e                   pop esi
// 00413cab  c3                   ret 
// standard library map_str<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
