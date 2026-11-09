// from server: 100% by auto
// roc 2010-06 006be800  unit: RBX::VCollectionService::?$FactoryProduct  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006be800
//
// 006be800  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006be803  56                   push esi
// 006be804  8b7004               mov esi, dword ptr [eax + 4]
// 006be807  807e3100             cmp byte ptr [esi + 0x31], 0
// 006be80b  57                   push edi
// 006be80c  8bf8                 mov edi, eax
// 006be80e  7531                 jne 0x6be841
// 006be810  53                   push ebx
// 006be811  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006be815  55                   push ebp
// 006be816  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 006be81c  8d642400             lea esp, [esp]
// 006be820  8d460c               lea eax, [esi + 0xc]
// 006be823  53                   push ebx
// 006be824  50                   push eax
// 006be825  ffd5                 call ebp
// 006be827  83c408               add esp, 8
// 006be82a  84c0                 test al, al
// 006be82c  7405                 je 0x6be833
// 006be82e  8b7608               mov esi, dword ptr [esi + 8]
// 006be831  eb04                 jmp 0x6be837
// 006be833  8bfe                 mov edi, esi
// 006be835  8b36                 mov esi, dword ptr [esi]
// 006be837  807e3100             cmp byte ptr [esi + 0x31], 0
// 006be83b  74e3                 je 0x6be820
// 006be83d  5d                   pop ebp
// 006be83e  8bc7                 mov eax, edi
// 006be840  5b                   pop ebx
// 006be841  5f                   pop edi
// 006be842  5e                   pop esi
// 006be843  c20400               ret 4
// standard library map_str<pod8> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
