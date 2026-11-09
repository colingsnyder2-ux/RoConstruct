// from server: 100% by auto
// roc 2008-06 004143e0  unit: CopyVerb  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004143e0
//
// 004143e0  64a100000000         mov eax, dword ptr fs:[0]
// 004143e6  6aff                 push -1
// 004143e8  68a9c87d00           push 0x7dc8a9
// 004143ed  50                   push eax
// 004143ee  64892500000000       mov dword ptr fs:[0], esp
// 004143f5  53                   push ebx
// 004143f6  55                   push ebp
// 004143f7  56                   push esi
// 004143f8  57                   push edi
// 004143f9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004143fd  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414401  8bd9                 mov ebx, ecx
// 00414403  8bf7                 mov esi, edi
// 00414405  7546                 jne 0x41444d
// 00414407  8b4608               mov eax, dword ptr [esi + 8]
// 0041440a  50                   push eax
// 0041440b  8bcb                 mov ecx, ebx
// 0041440d  e8ceffffff           call 0x4143e0
// 00414412  8b36                 mov esi, dword ptr [esi]
// 00414414  8d6f0c               lea ebp, [edi + 0xc]
// 00414417  896c2420             mov dword ptr [esp + 0x20], ebp
// 0041441b  8d4d1c               lea ecx, [ebp + 0x1c]
// 0041441e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00414426  ff1568248000         call dword ptr [0x802468]
// 0041442c  8bcd                 mov ecx, ebp
// 0041442e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00414436  ff1568248000         call dword ptr [0x802468]
// 0041443c  57                   push edi
// 0041443d  e838c22800           call 0x6a067a
// 00414442  83c404               add esp, 4
// 00414445  807e4500             cmp byte ptr [esi + 0x45], 0
// 00414449  8bfe                 mov edi, esi
// 0041444b  74ba                 je 0x414407
// 0041444d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00414451  5f                   pop edi
// 00414452  5e                   pop esi
// 00414453  5d                   pop ebp
// 00414454  64890d00000000       mov dword ptr fs:[0], ecx
// 0041445b  5b                   pop ebx
// 0041445c  83c40c               add esp, 0xc
// 0041445f  c20400               ret 4
// standard library map_str<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
