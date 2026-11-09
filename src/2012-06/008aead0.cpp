// from server: 100% by auto
// roc 2012-06 008aead0  unit: RBX::Flag  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008aead0
//
// 008aead0  53                   push ebx
// 008aead1  56                   push esi
// 008aead2  57                   push edi
// 008aead3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008aead7  807f1100             cmp byte ptr [edi + 0x11], 0
// 008aeadb  8bd9                 mov ebx, ecx
// 008aeadd  8bf7                 mov esi, edi
// 008aeadf  751e                 jne 0x8aeaff
// 008aeae1  8b4608               mov eax, dword ptr [esi + 8]
// 008aeae4  50                   push eax
// 008aeae5  8bcb                 mov ecx, ebx
// 008aeae7  e8e4ffffff           call 0x8aead0
// 008aeaec  8b36                 mov esi, dword ptr [esi]
// 008aeaee  57                   push edi
// 008aeaef  e820360d00           call 0x982114
// 008aeaf4  83c404               add esp, 4
// 008aeaf7  807e1100             cmp byte ptr [esi + 0x11], 0
// 008aeafb  8bfe                 mov edi, esi
// 008aeafd  74e2                 je 0x8aeae1
// 008aeaff  5f                   pop edi
// 008aeb00  5e                   pop esi
// 008aeb01  5b                   pop ebx
// 008aeb02  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
