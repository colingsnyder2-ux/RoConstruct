// from server: 100% by auto
// roc 2012-06 0040b240  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040b240
//
// 0040b240  64a100000000         mov eax, dword ptr fs:[0]
// 0040b246  6aff                 push -1
// 0040b248  68b9a3ac00           push 0xaca3b9
// 0040b24d  50                   push eax
// 0040b24e  64892500000000       mov dword ptr fs:[0], esp
// 0040b255  53                   push ebx
// 0040b256  55                   push ebp
// 0040b257  56                   push esi
// 0040b258  57                   push edi
// 0040b259  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040b25d  807f4500             cmp byte ptr [edi + 0x45], 0
// 0040b261  8bd9                 mov ebx, ecx
// 0040b263  8bf7                 mov esi, edi
// 0040b265  7546                 jne 0x40b2ad
// 0040b267  8b4608               mov eax, dword ptr [esi + 8]
// 0040b26a  50                   push eax
// 0040b26b  8bcb                 mov ecx, ebx
// 0040b26d  e8ceffffff           call 0x40b240
// 0040b272  8b36                 mov esi, dword ptr [esi]
// 0040b274  8d6f0c               lea ebp, [edi + 0xc]
// 0040b277  896c2420             mov dword ptr [esp + 0x20], ebp
// 0040b27b  8d4d1c               lea ecx, [ebp + 0x1c]
// 0040b27e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040b286  ff153c26b200         call dword ptr [0xb2263c]
// 0040b28c  8bcd                 mov ecx, ebp
// 0040b28e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040b296  ff153c26b200         call dword ptr [0xb2263c]
// 0040b29c  57                   push edi
// 0040b29d  e8726e5700           call 0x982114
// 0040b2a2  83c404               add esp, 4
// 0040b2a5  807e4500             cmp byte ptr [esi + 0x45], 0
// 0040b2a9  8bfe                 mov edi, esi
// 0040b2ab  74ba                 je 0x40b267
// 0040b2ad  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040b2b1  5f                   pop edi
// 0040b2b2  5e                   pop esi
// 0040b2b3  5d                   pop ebp
// 0040b2b4  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b2bb  5b                   pop ebx
// 0040b2bc  83c40c               add esp, 0xc
// 0040b2bf  c20400               ret 4
// standard library map_str<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
