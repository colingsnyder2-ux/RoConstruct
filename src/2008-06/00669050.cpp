// from server: 100% by auto
// roc 2008-06 00669050  unit: RBX::TreeStage  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00669050
//
// 00669050  53                   push ebx
// 00669051  56                   push esi
// 00669052  57                   push edi
// 00669053  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00669057  807f1100             cmp byte ptr [edi + 0x11], 0
// 0066905b  8bd9                 mov ebx, ecx
// 0066905d  8bf7                 mov esi, edi
// 0066905f  751e                 jne 0x66907f
// 00669061  8b4608               mov eax, dword ptr [esi + 8]
// 00669064  50                   push eax
// 00669065  8bcb                 mov ecx, ebx
// 00669067  e8e4ffffff           call 0x669050
// 0066906c  8b36                 mov esi, dword ptr [esi]
// 0066906e  57                   push edi
// 0066906f  e806760300           call 0x6a067a
// 00669074  83c404               add esp, 4
// 00669077  807e1100             cmp byte ptr [esi + 0x11], 0
// 0066907b  8bfe                 mov edi, esi
// 0066907d  74e2                 je 0x669061
// 0066907f  5f                   pop edi
// 00669080  5e                   pop esi
// 00669081  5b                   pop ebx
// 00669082  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
