// from server: 100% by auto
// roc 2007-08 005b32e0  unit: RBX::Assembly  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b32e0
//
// 005b32e0  53                   push ebx
// 005b32e1  56                   push esi
// 005b32e2  57                   push edi
// 005b32e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b32e7  807f1100             cmp byte ptr [edi + 0x11], 0
// 005b32eb  8bd9                 mov ebx, ecx
// 005b32ed  8bf7                 mov esi, edi
// 005b32ef  751e                 jne 0x5b330f
// 005b32f1  8b4608               mov eax, dword ptr [esi + 8]
// 005b32f4  50                   push eax
// 005b32f5  8bcb                 mov ecx, ebx
// 005b32f7  e8e4ffffff           call 0x5b32e0
// 005b32fc  8b36                 mov esi, dword ptr [esi]
// 005b32fe  57                   push edi
// 005b32ff  e85ec90700           call 0x62fc62
// 005b3304  83c404               add esp, 4
// 005b3307  807e1100             cmp byte ptr [esi + 0x11], 0
// 005b330b  8bfe                 mov edi, esi
// 005b330d  74e2                 je 0x5b32f1
// 005b330f  5f                   pop edi
// 005b3310  5e                   pop esi
// 005b3311  5b                   pop ebx
// 005b3312  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
