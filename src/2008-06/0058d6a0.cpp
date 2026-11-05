// from server: 100% by auto
// roc 2008-06 0058d6a0  unit: RBX::ChangeHistoryService  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058d6a0
//
// 0058d6a0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0058d6a3  56                   push esi
// 0058d6a4  8b7004               mov esi, dword ptr [eax + 4]
// 0058d6a7  807e4500             cmp byte ptr [esi + 0x45], 0
// 0058d6ab  57                   push edi
// 0058d6ac  8bf8                 mov edi, eax
// 0058d6ae  7531                 jne 0x58d6e1
// 0058d6b0  53                   push ebx
// 0058d6b1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058d6b5  55                   push ebp
// 0058d6b6  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 0058d6bc  8d642400             lea esp, [esp]
// 0058d6c0  8d460c               lea eax, [esi + 0xc]
// 0058d6c3  53                   push ebx
// 0058d6c4  50                   push eax
// 0058d6c5  ffd5                 call ebp
// 0058d6c7  83c408               add esp, 8
// 0058d6ca  84c0                 test al, al
// 0058d6cc  7405                 je 0x58d6d3
// 0058d6ce  8b7608               mov esi, dword ptr [esi + 8]
// 0058d6d1  eb04                 jmp 0x58d6d7
// 0058d6d3  8bfe                 mov edi, esi
// 0058d6d5  8b36                 mov esi, dword ptr [esi]
// 0058d6d7  807e4500             cmp byte ptr [esi + 0x45], 0
// 0058d6db  74e3                 je 0x58d6c0
// 0058d6dd  5d                   pop ebp
// 0058d6de  8bc7                 mov eax, edi
// 0058d6e0  5b                   pop ebx
// 0058d6e1  5f                   pop edi
// 0058d6e2  5e                   pop esi
// 0058d6e3  c20400               ret 4
// standard library map_str<string> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
