// from server: 100% by auto
// roc 2011-06 004cbe40  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004cbe40
//
// 004cbe40  53                   push ebx
// 004cbe41  56                   push esi
// 004cbe42  57                   push edi
// 004cbe43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004cbe47  807f2900             cmp byte ptr [edi + 0x29], 0
// 004cbe4b  8bd9                 mov ebx, ecx
// 004cbe4d  8bf7                 mov esi, edi
// 004cbe4f  7527                 jne 0x4cbe78
// 004cbe51  8b4608               mov eax, dword ptr [esi + 8]
// 004cbe54  50                   push eax
// 004cbe55  8bcb                 mov ecx, ebx
// 004cbe57  e8e4ffffff           call 0x4cbe40
// 004cbe5c  8b36                 mov esi, dword ptr [esi]
// 004cbe5e  8d4f0c               lea ecx, [edi + 0xc]
// 004cbe61  ff15d004a400         call dword ptr [0xa404d0]
// 004cbe67  57                   push edi
// 004cbe68  e8ebe13300           call 0x80a058
// 004cbe6d  83c404               add esp, 4
// 004cbe70  807e2900             cmp byte ptr [esi + 0x29], 0
// 004cbe74  8bfe                 mov edi, esi
// 004cbe76  74d9                 je 0x4cbe51
// 004cbe78  5f                   pop edi
// 004cbe79  5e                   pop esi
// 004cbe7a  5b                   pop ebx
// 004cbe7b  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
