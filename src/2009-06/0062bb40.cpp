// from server: 100% by auto
// roc 2009-06 0062bb40  unit: RBX::Workspace  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062bb40
//
// 0062bb40  53                   push ebx
// 0062bb41  56                   push esi
// 0062bb42  57                   push edi
// 0062bb43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0062bb47  807f1100             cmp byte ptr [edi + 0x11], 0
// 0062bb4b  8bd9                 mov ebx, ecx
// 0062bb4d  8bf7                 mov esi, edi
// 0062bb4f  751e                 jne 0x62bb6f
// 0062bb51  8b4608               mov eax, dword ptr [esi + 8]
// 0062bb54  50                   push eax
// 0062bb55  8bcb                 mov ecx, ebx
// 0062bb57  e8e4ffffff           call 0x62bb40
// 0062bb5c  8b36                 mov esi, dword ptr [esi]
// 0062bb5e  57                   push edi
// 0062bb5f  e8cece0e00           call 0x718a32
// 0062bb64  83c404               add esp, 4
// 0062bb67  807e1100             cmp byte ptr [esi + 0x11], 0
// 0062bb6b  8bfe                 mov edi, esi
// 0062bb6d  74e2                 je 0x62bb51
// 0062bb6f  5f                   pop edi
// 0062bb70  5e                   pop esi
// 0062bb71  5b                   pop ebx
// 0062bb72  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
