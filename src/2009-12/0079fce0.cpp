// from server: 100% by auto
// roc 2009-12 0079fce0  unit: seg_00790000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079fce0
//
// 0079fce0  53                   push ebx
// 0079fce1  56                   push esi
// 0079fce2  57                   push edi
// 0079fce3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0079fce7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0079fceb  8bd9                 mov ebx, ecx
// 0079fced  8bf7                 mov esi, edi
// 0079fcef  7527                 jne 0x79fd18
// 0079fcf1  8b4608               mov eax, dword ptr [esi + 8]
// 0079fcf4  50                   push eax
// 0079fcf5  8bcb                 mov ecx, ebx
// 0079fcf7  e8e4ffffff           call 0x79fce0
// 0079fcfc  8b36                 mov esi, dword ptr [esi]
// 0079fcfe  8d4f0c               lea ecx, [edi + 0xc]
// 0079fd01  ff15e4b69800         call dword ptr [0x98b6e4]
// 0079fd07  57                   push edi
// 0079fd08  e84d3b0500           call 0x7f385a
// 0079fd0d  83c404               add esp, 4
// 0079fd10  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0079fd14  8bfe                 mov edi, esi
// 0079fd16  74d9                 je 0x79fcf1
// 0079fd18  5f                   pop edi
// 0079fd19  5e                   pop esi
// 0079fd1a  5b                   pop ebx
// 0079fd1b  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
