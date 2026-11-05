// from server: 100% by auto
// roc 2010-06 006f4050  unit: RBX::VStudioTool::?$EventDesc  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f4050
//
// 006f4050  53                   push ebx
// 006f4051  56                   push esi
// 006f4052  57                   push edi
// 006f4053  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006f4057  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006f405b  8bd9                 mov ebx, ecx
// 006f405d  8bf7                 mov esi, edi
// 006f405f  751e                 jne 0x6f407f
// 006f4061  8b4608               mov eax, dword ptr [esi + 8]
// 006f4064  50                   push eax
// 006f4065  8bcb                 mov ecx, ebx
// 006f4067  e8e4ffffff           call 0x6f4050
// 006f406c  8b36                 mov esi, dword ptr [esi]
// 006f406e  57                   push edi
// 006f406f  e826390b00           call 0x7a799a
// 006f4074  83c404               add esp, 4
// 006f4077  807e0e00             cmp byte ptr [esi + 0xe], 0
// 006f407b  8bfe                 mov edi, esi
// 006f407d  74e2                 je 0x6f4061
// 006f407f  5f                   pop edi
// 006f4080  5e                   pop esi
// 006f4081  5b                   pop ebx
// 006f4082  c20400               ret 4
// standard library set<char> (function ?_Erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
