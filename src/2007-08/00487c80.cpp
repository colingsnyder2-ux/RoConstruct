// from server: 100% by auto
// roc 2007-08 00487c80  unit: P8CRenderSettings::?$GetSetImpl  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00487c80
//
// 00487c80  53                   push ebx
// 00487c81  56                   push esi
// 00487c82  57                   push edi
// 00487c83  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00487c87  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00487c8b  8bd9                 mov ebx, ecx
// 00487c8d  8bf7                 mov esi, edi
// 00487c8f  751e                 jne 0x487caf
// 00487c91  8b4608               mov eax, dword ptr [esi + 8]
// 00487c94  50                   push eax
// 00487c95  8bcb                 mov ecx, ebx
// 00487c97  e8e4ffffff           call 0x487c80
// 00487c9c  8b36                 mov esi, dword ptr [esi]
// 00487c9e  57                   push edi
// 00487c9f  e8be7f1a00           call 0x62fc62
// 00487ca4  83c404               add esp, 4
// 00487ca7  807e0e00             cmp byte ptr [esi + 0xe], 0
// 00487cab  8bfe                 mov edi, esi
// 00487cad  74e2                 je 0x487c91
// 00487caf  5f                   pop edi
// 00487cb0  5e                   pop esi
// 00487cb1  5b                   pop ebx
// 00487cb2  c20400               ret 4
// standard library set<char> (function ?_Erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
