// from server: 100% by auto
// roc 2011-06 005153e0  unit: CXTPCommandBar  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005153e0
//
// 005153e0  53                   push ebx
// 005153e1  56                   push esi
// 005153e2  57                   push edi
// 005153e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005153e7  807f2900             cmp byte ptr [edi + 0x29], 0
// 005153eb  8bd9                 mov ebx, ecx
// 005153ed  8bf7                 mov esi, edi
// 005153ef  751e                 jne 0x51540f
// 005153f1  8b4608               mov eax, dword ptr [esi + 8]
// 005153f4  50                   push eax
// 005153f5  8bcb                 mov ecx, ebx
// 005153f7  e8e4ffffff           call 0x5153e0
// 005153fc  8b36                 mov esi, dword ptr [esi]
// 005153fe  57                   push edi
// 005153ff  e8544c2f00           call 0x80a058
// 00515404  83c404               add esp, 4
// 00515407  807e2900             cmp byte ptr [esi + 0x29], 0
// 0051540b  8bfe                 mov edi, esi
// 0051540d  74e2                 je 0x5153f1
// 0051540f  5f                   pop edi
// 00515410  5e                   pop esi
// 00515411  5b                   pop ebx
// 00515412  c20400               ret 4
// standard library set<pod28> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod28>
struct E { int v[7]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
