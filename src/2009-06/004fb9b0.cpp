// from server: 100% by auto
// roc 2009-06 004fb9b0  unit: RBX::Network::ServerReplicator  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fb9b0
//
// 004fb9b0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004fb9b3  56                   push esi
// 004fb9b4  8b7004               mov esi, dword ptr [eax + 4]
// 004fb9b7  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fb9bb  57                   push edi
// 004fb9bc  8bf8                 mov edi, eax
// 004fb9be  7531                 jne 0x4fb9f1
// 004fb9c0  53                   push ebx
// 004fb9c1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004fb9c5  55                   push ebp
// 004fb9c6  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 004fb9cc  8d642400             lea esp, [esp]
// 004fb9d0  8d460c               lea eax, [esi + 0xc]
// 004fb9d3  53                   push ebx
// 004fb9d4  50                   push eax
// 004fb9d5  ffd5                 call ebp
// 004fb9d7  83c408               add esp, 8
// 004fb9da  84c0                 test al, al
// 004fb9dc  7405                 je 0x4fb9e3
// 004fb9de  8b7608               mov esi, dword ptr [esi + 8]
// 004fb9e1  eb04                 jmp 0x4fb9e7
// 004fb9e3  8bfe                 mov edi, esi
// 004fb9e5  8b36                 mov esi, dword ptr [esi]
// 004fb9e7  807e3900             cmp byte ptr [esi + 0x39], 0
// 004fb9eb  74e3                 je 0x4fb9d0
// 004fb9ed  5d                   pop ebp
// 004fb9ee  8bc7                 mov eax, edi
// 004fb9f0  5b                   pop ebx
// 004fb9f1  5f                   pop edi
// 004fb9f2  5e                   pop esi
// 004fb9f3  c20400               ret 4
// standard library map_str<pod16> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
