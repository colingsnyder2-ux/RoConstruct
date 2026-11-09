// from server: 100% by auto
// roc 2010-06 005efb50  unit: RBX::ChangeHistoryService  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005efb50
//
// 005efb50  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005efb53  56                   push esi
// 005efb54  8b7004               mov esi, dword ptr [eax + 4]
// 005efb57  807e4500             cmp byte ptr [esi + 0x45], 0
// 005efb5b  57                   push edi
// 005efb5c  8bf8                 mov edi, eax
// 005efb5e  7531                 jne 0x5efb91
// 005efb60  53                   push ebx
// 005efb61  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005efb65  55                   push ebp
// 005efb66  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 005efb6c  8d642400             lea esp, [esp]
// 005efb70  8d460c               lea eax, [esi + 0xc]
// 005efb73  53                   push ebx
// 005efb74  50                   push eax
// 005efb75  ffd5                 call ebp
// 005efb77  83c408               add esp, 8
// 005efb7a  84c0                 test al, al
// 005efb7c  7405                 je 0x5efb83
// 005efb7e  8b7608               mov esi, dword ptr [esi + 8]
// 005efb81  eb04                 jmp 0x5efb87
// 005efb83  8bfe                 mov edi, esi
// 005efb85  8b36                 mov esi, dword ptr [esi]
// 005efb87  807e4500             cmp byte ptr [esi + 0x45], 0
// 005efb8b  74e3                 je 0x5efb70
// 005efb8d  5d                   pop ebp
// 005efb8e  8bc7                 mov eax, edi
// 005efb90  5b                   pop ebx
// 005efb91  5f                   pop edi
// 005efb92  5e                   pop esi
// 005efb93  c20400               ret 4
// standard library map_str<string> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
