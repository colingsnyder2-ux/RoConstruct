// from server: 100% by auto
// roc 2012-06 005cb6b0  unit: RBX::SceneUpdater  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005cb6b0
//
// 005cb6b0  53                   push ebx
// 005cb6b1  56                   push esi
// 005cb6b2  57                   push edi
// 005cb6b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005cb6b7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cb6bb  8bd9                 mov ebx, ecx
// 005cb6bd  8bf7                 mov esi, edi
// 005cb6bf  7527                 jne 0x5cb6e8
// 005cb6c1  8b4608               mov eax, dword ptr [esi + 8]
// 005cb6c4  50                   push eax
// 005cb6c5  8bcb                 mov ecx, ebx
// 005cb6c7  e8e4ffffff           call 0x5cb6b0
// 005cb6cc  8b36                 mov esi, dword ptr [esi]
// 005cb6ce  8d4f10               lea ecx, [edi + 0x10]
// 005cb6d1  ff153c26b200         call dword ptr [0xb2263c]
// 005cb6d7  57                   push edi
// 005cb6d8  e8376a3b00           call 0x982114
// 005cb6dd  83c404               add esp, 4
// 005cb6e0  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005cb6e4  8bfe                 mov edi, esi
// 005cb6e6  74d9                 je 0x5cb6c1
// 005cb6e8  5f                   pop edi
// 005cb6e9  5e                   pop esi
// 005cb6ea  5b                   pop ebx
// 005cb6eb  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
