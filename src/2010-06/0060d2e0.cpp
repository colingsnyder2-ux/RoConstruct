// from server: 100% by auto
// roc 2010-06 0060d2e0  unit: RBX::VScriptContext::?$FactoryProduct  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060d2e0
//
// 0060d2e0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0060d2e3  56                   push esi
// 0060d2e4  8b7004               mov esi, dword ptr [eax + 4]
// 0060d2e7  807e4900             cmp byte ptr [esi + 0x49], 0
// 0060d2eb  57                   push edi
// 0060d2ec  8bf8                 mov edi, eax
// 0060d2ee  7531                 jne 0x60d321
// 0060d2f0  53                   push ebx
// 0060d2f1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0060d2f5  55                   push ebp
// 0060d2f6  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 0060d2fc  8d642400             lea esp, [esp]
// 0060d300  8d460c               lea eax, [esi + 0xc]
// 0060d303  53                   push ebx
// 0060d304  50                   push eax
// 0060d305  ffd5                 call ebp
// 0060d307  83c408               add esp, 8
// 0060d30a  84c0                 test al, al
// 0060d30c  7405                 je 0x60d313
// 0060d30e  8b7608               mov esi, dword ptr [esi + 8]
// 0060d311  eb04                 jmp 0x60d317
// 0060d313  8bfe                 mov edi, esi
// 0060d315  8b36                 mov esi, dword ptr [esi]
// 0060d317  807e4900             cmp byte ptr [esi + 0x49], 0
// 0060d31b  74e3                 je 0x60d300
// 0060d31d  5d                   pop ebp
// 0060d31e  8bc7                 mov eax, edi
// 0060d320  5b                   pop ebx
// 0060d321  5f                   pop edi
// 0060d322  5e                   pop esi
// 0060d323  c20400               ret 4
// standard library map_str<pod32> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
