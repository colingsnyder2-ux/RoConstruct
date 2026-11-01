// from server: 100% by auto
// roc 2009-12 007c2110  unit: RBX::ImageButton  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c2110
//
// 007c2110  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007c2113  56                   push esi
// 007c2114  8b7004               mov esi, dword ptr [eax + 4]
// 007c2117  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c211b  57                   push edi
// 007c211c  8bf8                 mov edi, eax
// 007c211e  7531                 jne 0x7c2151
// 007c2120  53                   push ebx
// 007c2121  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007c2125  55                   push ebp
// 007c2126  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 007c212c  8d642400             lea esp, [esp]
// 007c2130  8d460c               lea eax, [esi + 0xc]
// 007c2133  53                   push ebx
// 007c2134  50                   push eax
// 007c2135  ffd5                 call ebp
// 007c2137  83c408               add esp, 8
// 007c213a  84c0                 test al, al
// 007c213c  7405                 je 0x7c2143
// 007c213e  8b7608               mov esi, dword ptr [esi + 8]
// 007c2141  eb04                 jmp 0x7c2147
// 007c2143  8bfe                 mov edi, esi
// 007c2145  8b36                 mov esi, dword ptr [esi]
// 007c2147  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c214b  74e3                 je 0x7c2130
// 007c214d  5d                   pop ebp
// 007c214e  8bc7                 mov eax, edi
// 007c2150  5b                   pop ebx
// 007c2151  5f                   pop edi
// 007c2152  5e                   pop esi
// 007c2153  c20400               ret 4
// standard library map_str<pod36> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
