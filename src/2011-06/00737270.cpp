// from server: 100% by auto
// roc 2011-06 00737270  unit: RBX::Network::P8Player::?$GetImpl  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00737270
//
// 00737270  53                   push ebx
// 00737271  56                   push esi
// 00737272  57                   push edi
// 00737273  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00737277  807f0e00             cmp byte ptr [edi + 0xe], 0
// 0073727b  8bd9                 mov ebx, ecx
// 0073727d  8bf7                 mov esi, edi
// 0073727f  751e                 jne 0x73729f
// 00737281  8b4608               mov eax, dword ptr [esi + 8]
// 00737284  50                   push eax
// 00737285  8bcb                 mov ecx, ebx
// 00737287  e8e4ffffff           call 0x737270
// 0073728c  8b36                 mov esi, dword ptr [esi]
// 0073728e  57                   push edi
// 0073728f  e8c42d0d00           call 0x80a058
// 00737294  83c404               add esp, 4
// 00737297  807e0e00             cmp byte ptr [esi + 0xe], 0
// 0073729b  8bfe                 mov edi, esi
// 0073729d  74e2                 je 0x737281
// 0073729f  5f                   pop edi
// 007372a0  5e                   pop esi
// 007372a1  5b                   pop ebx
// 007372a2  c20400               ret 4
// standard library set<char> (function ?_Erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
