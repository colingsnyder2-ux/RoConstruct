// from server: 100% by auto
// roc 2009-12 00413a20  unit: CopyVerb  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413a20
//
// 00413a20  56                   push esi
// 00413a21  8bf1                 mov esi, ecx
// 00413a23  833e00               cmp dword ptr [esi], 0
// 00413a26  57                   push edi
// 00413a27  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00413a2d  7502                 jne 0x413a31
// 00413a2f  ffd7                 call edi
// 00413a31  8b4604               mov eax, dword ptr [esi + 4]
// 00413a34  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a38  7405                 je 0x413a3f
// 00413a3a  ffd7                 call edi
// 00413a3c  5f                   pop edi
// 00413a3d  5e                   pop esi
// 00413a3e  c3                   ret 
// 00413a3f  8b4808               mov ecx, dword ptr [eax + 8]
// 00413a42  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413a46  7518                 jne 0x413a60
// 00413a48  8b01                 mov eax, dword ptr [ecx]
// 00413a4a  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a4e  750a                 jne 0x413a5a
// 00413a50  8bc8                 mov ecx, eax
// 00413a52  8b01                 mov eax, dword ptr [ecx]
// 00413a54  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a58  74f6                 je 0x413a50
// 00413a5a  5f                   pop edi
// 00413a5b  894e04               mov dword ptr [esi + 4], ecx
// 00413a5e  5e                   pop esi
// 00413a5f  c3                   ret 
// 00413a60  8b4004               mov eax, dword ptr [eax + 4]
// 00413a63  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a67  751d                 jne 0x413a86
// 00413a69  8da42400000000       lea esp, [esp]
// 00413a70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413a73  3b4808               cmp ecx, dword ptr [eax + 8]
// 00413a76  750e                 jne 0x413a86
// 00413a78  894604               mov dword ptr [esi + 4], eax
// 00413a7b  8bd0                 mov edx, eax
// 00413a7d  8b4204               mov eax, dword ptr [edx + 4]
// 00413a80  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a84  74ea                 je 0x413a70
// 00413a86  5f                   pop edi
// 00413a87  894604               mov dword ptr [esi + 4], eax
// 00413a8a  5e                   pop esi
// 00413a8b  c3                   ret 
// standard library map_str<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
