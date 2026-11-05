// from server: 100% by auto
// roc 2010-06 004c3e40  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c3e40
//
// 004c3e40  53                   push ebx
// 004c3e41  56                   push esi
// 004c3e42  57                   push edi
// 004c3e43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c3e47  807f2900             cmp byte ptr [edi + 0x29], 0
// 004c3e4b  8bd9                 mov ebx, ecx
// 004c3e4d  8bf7                 mov esi, edi
// 004c3e4f  7527                 jne 0x4c3e78
// 004c3e51  8b4608               mov eax, dword ptr [esi + 8]
// 004c3e54  50                   push eax
// 004c3e55  8bcb                 mov ecx, ebx
// 004c3e57  e8e4ffffff           call 0x4c3e40
// 004c3e5c  8b36                 mov esi, dword ptr [esi]
// 004c3e5e  8d4f0c               lea ecx, [edi + 0xc]
// 004c3e61  ff1500a49e00         call dword ptr [0x9ea400]
// 004c3e67  57                   push edi
// 004c3e68  e82d3b2e00           call 0x7a799a
// 004c3e6d  83c404               add esp, 4
// 004c3e70  807e2900             cmp byte ptr [esi + 0x29], 0
// 004c3e74  8bfe                 mov edi, esi
// 004c3e76  74d9                 je 0x4c3e51
// 004c3e78  5f                   pop edi
// 004c3e79  5e                   pop esi
// 004c3e7a  5b                   pop ebx
// 004c3e7b  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
