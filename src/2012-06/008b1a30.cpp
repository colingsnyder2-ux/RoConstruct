// from server: 100% by auto
// roc 2012-06 008b1a30  unit: RBX::PluginMouse  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b1a30
//
// 008b1a30  53                   push ebx
// 008b1a31  56                   push esi
// 008b1a32  57                   push edi
// 008b1a33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008b1a37  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 008b1a3b  8bd9                 mov ebx, ecx
// 008b1a3d  8bf7                 mov esi, edi
// 008b1a3f  7527                 jne 0x8b1a68
// 008b1a41  8b4608               mov eax, dword ptr [esi + 8]
// 008b1a44  50                   push eax
// 008b1a45  8bcb                 mov ecx, ebx
// 008b1a47  e8e4ffffff           call 0x8b1a30
// 008b1a4c  8b36                 mov esi, dword ptr [esi]
// 008b1a4e  8d4f0c               lea ecx, [edi + 0xc]
// 008b1a51  ff153c26b200         call dword ptr [0xb2263c]
// 008b1a57  57                   push edi
// 008b1a58  e8b7060d00           call 0x982114
// 008b1a5d  83c404               add esp, 4
// 008b1a60  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 008b1a64  8bfe                 mov edi, esi
// 008b1a66  74d9                 je 0x8b1a41
// 008b1a68  5f                   pop edi
// 008b1a69  5e                   pop esi
// 008b1a6a  5b                   pop ebx
// 008b1a6b  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
