// from server: 100% by auto
// roc 2009-06 00622220  unit: RBX::RootInstance  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622220
//
// 00622220  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00622223  56                   push esi
// 00622224  8b7004               mov esi, dword ptr [eax + 4]
// 00622227  807e3100             cmp byte ptr [esi + 0x31], 0
// 0062222b  57                   push edi
// 0062222c  8bf8                 mov edi, eax
// 0062222e  7531                 jne 0x622261
// 00622230  53                   push ebx
// 00622231  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00622235  55                   push ebp
// 00622236  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 0062223c  8d642400             lea esp, [esp]
// 00622240  8d460c               lea eax, [esi + 0xc]
// 00622243  53                   push ebx
// 00622244  50                   push eax
// 00622245  ffd5                 call ebp
// 00622247  83c408               add esp, 8
// 0062224a  84c0                 test al, al
// 0062224c  7405                 je 0x622253
// 0062224e  8b7608               mov esi, dword ptr [esi + 8]
// 00622251  eb04                 jmp 0x622257
// 00622253  8bfe                 mov edi, esi
// 00622255  8b36                 mov esi, dword ptr [esi]
// 00622257  807e3100             cmp byte ptr [esi + 0x31], 0
// 0062225b  74e3                 je 0x622240
// 0062225d  5d                   pop ebp
// 0062225e  8bc7                 mov eax, edi
// 00622260  5b                   pop ebx
// 00622261  5f                   pop edi
// 00622262  5e                   pop esi
// 00622263  c20400               ret 4
// standard library map_str<pod8> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
