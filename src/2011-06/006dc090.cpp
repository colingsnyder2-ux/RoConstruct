// from server: 100% by auto
// roc 2011-06 006dc090  unit: RBX::VPhysicsService::?$EventDesc  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006dc090
//
// 006dc090  53                   push ebx
// 006dc091  56                   push esi
// 006dc092  57                   push edi
// 006dc093  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006dc097  807f1100             cmp byte ptr [edi + 0x11], 0
// 006dc09b  8bd9                 mov ebx, ecx
// 006dc09d  8bf7                 mov esi, edi
// 006dc09f  751e                 jne 0x6dc0bf
// 006dc0a1  8b4608               mov eax, dword ptr [esi + 8]
// 006dc0a4  50                   push eax
// 006dc0a5  8bcb                 mov ecx, ebx
// 006dc0a7  e8e4ffffff           call 0x6dc090
// 006dc0ac  8b36                 mov esi, dword ptr [esi]
// 006dc0ae  57                   push edi
// 006dc0af  e8a4df1200           call 0x80a058
// 006dc0b4  83c404               add esp, 4
// 006dc0b7  807e1100             cmp byte ptr [esi + 0x11], 0
// 006dc0bb  8bfe                 mov edi, esi
// 006dc0bd  74e2                 je 0x6dc0a1
// 006dc0bf  5f                   pop edi
// 006dc0c0  5e                   pop esi
// 006dc0c1  5b                   pop ebx
// 006dc0c2  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
