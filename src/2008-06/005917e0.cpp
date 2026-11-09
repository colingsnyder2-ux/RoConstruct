// from server: 100% by auto
// roc 2008-06 005917e0  unit: RBX::RootInstance  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005917e0
//
// 005917e0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005917e3  56                   push esi
// 005917e4  8b7004               mov esi, dword ptr [eax + 4]
// 005917e7  807e3100             cmp byte ptr [esi + 0x31], 0
// 005917eb  57                   push edi
// 005917ec  8bf8                 mov edi, eax
// 005917ee  7531                 jne 0x591821
// 005917f0  53                   push ebx
// 005917f1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005917f5  55                   push ebp
// 005917f6  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 005917fc  8d642400             lea esp, [esp]
// 00591800  8d460c               lea eax, [esi + 0xc]
// 00591803  53                   push ebx
// 00591804  50                   push eax
// 00591805  ffd5                 call ebp
// 00591807  83c408               add esp, 8
// 0059180a  84c0                 test al, al
// 0059180c  7405                 je 0x591813
// 0059180e  8b7608               mov esi, dword ptr [esi + 8]
// 00591811  eb04                 jmp 0x591817
// 00591813  8bfe                 mov edi, esi
// 00591815  8b36                 mov esi, dword ptr [esi]
// 00591817  807e3100             cmp byte ptr [esi + 0x31], 0
// 0059181b  74e3                 je 0x591800
// 0059181d  5d                   pop ebp
// 0059181e  8bc7                 mov eax, edi
// 00591820  5b                   pop ebx
// 00591821  5f                   pop edi
// 00591822  5e                   pop esi
// 00591823  c20400               ret 4
// standard library map_str<pod8> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
