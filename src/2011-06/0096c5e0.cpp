// from server: 100% by auto
// roc 2011-06 0096c5e0  unit: RBX::SceneUpdater  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0096c5e0
//
// 0096c5e0  53                   push ebx
// 0096c5e1  56                   push esi
// 0096c5e2  57                   push edi
// 0096c5e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0096c5e7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0096c5eb  8bd9                 mov ebx, ecx
// 0096c5ed  8bf7                 mov esi, edi
// 0096c5ef  7527                 jne 0x96c618
// 0096c5f1  8b4608               mov eax, dword ptr [esi + 8]
// 0096c5f4  50                   push eax
// 0096c5f5  8bcb                 mov ecx, ebx
// 0096c5f7  e8e4ffffff           call 0x96c5e0
// 0096c5fc  8b36                 mov esi, dword ptr [esi]
// 0096c5fe  8d4f10               lea ecx, [edi + 0x10]
// 0096c601  ff15d004a400         call dword ptr [0xa404d0]
// 0096c607  57                   push edi
// 0096c608  e84bdae9ff           call 0x80a058
// 0096c60d  83c404               add esp, 4
// 0096c610  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0096c614  8bfe                 mov edi, esi
// 0096c616  74d9                 je 0x96c5f1
// 0096c618  5f                   pop edi
// 0096c619  5e                   pop esi
// 0096c61a  5b                   pop ebx
// 0096c61b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
