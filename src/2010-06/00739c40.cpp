// from server: 100% by auto
// roc 2010-06 00739c40  unit: seg_00730000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00739c40
//
// 00739c40  53                   push ebx
// 00739c41  56                   push esi
// 00739c42  57                   push edi
// 00739c43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00739c47  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00739c4b  8bd9                 mov ebx, ecx
// 00739c4d  8bf7                 mov esi, edi
// 00739c4f  7527                 jne 0x739c78
// 00739c51  8b4608               mov eax, dword ptr [esi + 8]
// 00739c54  50                   push eax
// 00739c55  8bcb                 mov ecx, ebx
// 00739c57  e8e4ffffff           call 0x739c40
// 00739c5c  8b36                 mov esi, dword ptr [esi]
// 00739c5e  8d4f0c               lea ecx, [edi + 0xc]
// 00739c61  ff1500a49e00         call dword ptr [0x9ea400]
// 00739c67  57                   push edi
// 00739c68  e82ddd0600           call 0x7a799a
// 00739c6d  83c404               add esp, 4
// 00739c70  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00739c74  8bfe                 mov edi, esi
// 00739c76  74d9                 je 0x739c51
// 00739c78  5f                   pop edi
// 00739c79  5e                   pop esi
// 00739c7a  5b                   pop ebx
// 00739c7b  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
