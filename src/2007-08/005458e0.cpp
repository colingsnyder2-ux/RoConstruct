// from server: 100% by auto
// roc 2007-08 005458e0  unit: RBX::MD5HasherImpl  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005458e0
//
// 005458e0  8b4104               mov eax, dword ptr [ecx + 4]
// 005458e3  56                   push esi
// 005458e4  8b7004               mov esi, dword ptr [eax + 4]
// 005458e7  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005458eb  57                   push edi
// 005458ec  8bf8                 mov edi, eax
// 005458ee  7531                 jne 0x545921
// 005458f0  53                   push ebx
// 005458f1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005458f5  55                   push ebp
// 005458f6  8b2d20e67700         mov ebp, dword ptr [0x77e620]
// 005458fc  8d642400             lea esp, [esp]
// 00545900  8d460c               lea eax, [esi + 0xc]
// 00545903  53                   push ebx
// 00545904  50                   push eax
// 00545905  ffd5                 call ebp
// 00545907  83c408               add esp, 8
// 0054590a  84c0                 test al, al
// 0054590c  7405                 je 0x545913
// 0054590e  8b7608               mov esi, dword ptr [esi + 8]
// 00545911  eb04                 jmp 0x545917
// 00545913  8bfe                 mov edi, esi
// 00545915  8b36                 mov esi, dword ptr [esi]
// 00545917  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 0054591b  74e3                 je 0x545900
// 0054591d  5d                   pop ebp
// 0054591e  8bc7                 mov eax, edi
// 00545920  5b                   pop ebx
// 00545921  5f                   pop edi
// 00545922  5e                   pop esi
// 00545923  c20400               ret 4
// standard library map_str<pod20> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
