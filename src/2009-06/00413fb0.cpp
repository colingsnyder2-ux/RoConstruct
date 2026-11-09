// from server: 100% by auto
// roc 2009-06 00413fb0  unit: CopyVerb  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413fb0
//
// 00413fb0  56                   push esi
// 00413fb1  8bf1                 mov esi, ecx
// 00413fb3  833e00               cmp dword ptr [esi], 0
// 00413fb6  57                   push edi
// 00413fb7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00413fbd  7502                 jne 0x413fc1
// 00413fbf  ffd7                 call edi
// 00413fc1  8b4604               mov eax, dword ptr [esi + 4]
// 00413fc4  80784500             cmp byte ptr [eax + 0x45], 0
// 00413fc8  7405                 je 0x413fcf
// 00413fca  ffd7                 call edi
// 00413fcc  5f                   pop edi
// 00413fcd  5e                   pop esi
// 00413fce  c3                   ret 
// 00413fcf  8b4808               mov ecx, dword ptr [eax + 8]
// 00413fd2  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413fd6  7518                 jne 0x413ff0
// 00413fd8  8b01                 mov eax, dword ptr [ecx]
// 00413fda  80784500             cmp byte ptr [eax + 0x45], 0
// 00413fde  750a                 jne 0x413fea
// 00413fe0  8bc8                 mov ecx, eax
// 00413fe2  8b01                 mov eax, dword ptr [ecx]
// 00413fe4  80784500             cmp byte ptr [eax + 0x45], 0
// 00413fe8  74f6                 je 0x413fe0
// 00413fea  5f                   pop edi
// 00413feb  894e04               mov dword ptr [esi + 4], ecx
// 00413fee  5e                   pop esi
// 00413fef  c3                   ret 
// 00413ff0  8b4004               mov eax, dword ptr [eax + 4]
// 00413ff3  80784500             cmp byte ptr [eax + 0x45], 0
// 00413ff7  751d                 jne 0x414016
// 00413ff9  8da42400000000       lea esp, [esp]
// 00414000  8b4e04               mov ecx, dword ptr [esi + 4]
// 00414003  3b4808               cmp ecx, dword ptr [eax + 8]
// 00414006  750e                 jne 0x414016
// 00414008  894604               mov dword ptr [esi + 4], eax
// 0041400b  8bd0                 mov edx, eax
// 0041400d  8b4204               mov eax, dword ptr [edx + 4]
// 00414010  80784500             cmp byte ptr [eax + 0x45], 0
// 00414014  74ea                 je 0x414000
// 00414016  5f                   pop edi
// 00414017  894604               mov dword ptr [esi + 4], eax
// 0041401a  5e                   pop esi
// 0041401b  c3                   ret 
// standard library map_str<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
