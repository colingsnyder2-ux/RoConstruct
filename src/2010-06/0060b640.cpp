// from server: 100% by auto
// roc 2010-06 0060b640  unit: RBX::ScriptContext  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060b640
//
// 0060b640  56                   push esi
// 0060b641  8bf1                 mov esi, ecx
// 0060b643  833e00               cmp dword ptr [esi], 0
// 0060b646  57                   push edi
// 0060b647  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0060b64d  7502                 jne 0x60b651
// 0060b64f  ffd7                 call edi
// 0060b651  8b4604               mov eax, dword ptr [esi + 4]
// 0060b654  80784900             cmp byte ptr [eax + 0x49], 0
// 0060b658  7405                 je 0x60b65f
// 0060b65a  ffd7                 call edi
// 0060b65c  5f                   pop edi
// 0060b65d  5e                   pop esi
// 0060b65e  c3                   ret 
// 0060b65f  8b4808               mov ecx, dword ptr [eax + 8]
// 0060b662  80794900             cmp byte ptr [ecx + 0x49], 0
// 0060b666  7518                 jne 0x60b680
// 0060b668  8b01                 mov eax, dword ptr [ecx]
// 0060b66a  80784900             cmp byte ptr [eax + 0x49], 0
// 0060b66e  750a                 jne 0x60b67a
// 0060b670  8bc8                 mov ecx, eax
// 0060b672  8b01                 mov eax, dword ptr [ecx]
// 0060b674  80784900             cmp byte ptr [eax + 0x49], 0
// 0060b678  74f6                 je 0x60b670
// 0060b67a  5f                   pop edi
// 0060b67b  894e04               mov dword ptr [esi + 4], ecx
// 0060b67e  5e                   pop esi
// 0060b67f  c3                   ret 
// 0060b680  8b4004               mov eax, dword ptr [eax + 4]
// 0060b683  80784900             cmp byte ptr [eax + 0x49], 0
// 0060b687  751d                 jne 0x60b6a6
// 0060b689  8da42400000000       lea esp, [esp]
// 0060b690  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060b693  3b4808               cmp ecx, dword ptr [eax + 8]
// 0060b696  750e                 jne 0x60b6a6
// 0060b698  894604               mov dword ptr [esi + 4], eax
// 0060b69b  8bd0                 mov edx, eax
// 0060b69d  8b4204               mov eax, dword ptr [edx + 4]
// 0060b6a0  80784900             cmp byte ptr [eax + 0x49], 0
// 0060b6a4  74ea                 je 0x60b690
// 0060b6a6  5f                   pop edi
// 0060b6a7  894604               mov dword ptr [esi + 4], eax
// 0060b6aa  5e                   pop esi
// 0060b6ab  c3                   ret 
// standard library map_str<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
