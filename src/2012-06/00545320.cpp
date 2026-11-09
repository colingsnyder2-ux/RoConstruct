// from server: 100% by auto
// roc 2012-06 00545320  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00545320
//
// 00545320  53                   push ebx
// 00545321  56                   push esi
// 00545322  57                   push edi
// 00545323  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00545327  807f2900             cmp byte ptr [edi + 0x29], 0
// 0054532b  8bd9                 mov ebx, ecx
// 0054532d  8bf7                 mov esi, edi
// 0054532f  7527                 jne 0x545358
// 00545331  8b4608               mov eax, dword ptr [esi + 8]
// 00545334  50                   push eax
// 00545335  8bcb                 mov ecx, ebx
// 00545337  e8e4ffffff           call 0x545320
// 0054533c  8b36                 mov esi, dword ptr [esi]
// 0054533e  8d4f0c               lea ecx, [edi + 0xc]
// 00545341  ff153c26b200         call dword ptr [0xb2263c]
// 00545347  57                   push edi
// 00545348  e8c7cd4300           call 0x982114
// 0054534d  83c404               add esp, 4
// 00545350  807e2900             cmp byte ptr [esi + 0x29], 0
// 00545354  8bfe                 mov edi, esi
// 00545356  74d9                 je 0x545331
// 00545358  5f                   pop edi
// 00545359  5e                   pop esi
// 0054535a  5b                   pop ebx
// 0054535b  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
