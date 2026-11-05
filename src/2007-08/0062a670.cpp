// from server: 100% by auto
// roc 2007-08 0062a670  unit: RBX::AssemblyStage  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062a670
//
// 0062a670  53                   push ebx
// 0062a671  56                   push esi
// 0062a672  57                   push edi
// 0062a673  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0062a677  807f2900             cmp byte ptr [edi + 0x29], 0
// 0062a67b  8bd9                 mov ebx, ecx
// 0062a67d  8bf7                 mov esi, edi
// 0062a67f  7527                 jne 0x62a6a8
// 0062a681  8b4608               mov eax, dword ptr [esi + 8]
// 0062a684  50                   push eax
// 0062a685  8bcb                 mov ecx, ebx
// 0062a687  e8e4ffffff           call 0x62a670
// 0062a68c  8b36                 mov esi, dword ptr [esi]
// 0062a68e  8d4f0c               lea ecx, [edi + 0xc]
// 0062a691  ff15ace67700         call dword ptr [0x77e6ac]
// 0062a697  57                   push edi
// 0062a698  e8c5550000           call 0x62fc62
// 0062a69d  83c404               add esp, 4
// 0062a6a0  807e2900             cmp byte ptr [esi + 0x29], 0
// 0062a6a4  8bfe                 mov edi, esi
// 0062a6a6  74d9                 je 0x62a681
// 0062a6a8  5f                   pop edi
// 0062a6a9  5e                   pop esi
// 0062a6aa  5b                   pop ebx
// 0062a6ab  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
