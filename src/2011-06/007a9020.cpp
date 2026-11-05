// from server: 100% by auto
// roc 2011-06 007a9020  unit: RBX::WedgePoly  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a9020
//
// 007a9020  53                   push ebx
// 007a9021  56                   push esi
// 007a9022  57                   push edi
// 007a9023  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007a9027  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007a902b  8bd9                 mov ebx, ecx
// 007a902d  8bf7                 mov esi, edi
// 007a902f  751e                 jne 0x7a904f
// 007a9031  8b4608               mov eax, dword ptr [esi + 8]
// 007a9034  50                   push eax
// 007a9035  8bcb                 mov ecx, ebx
// 007a9037  e8e4ffffff           call 0x7a9020
// 007a903c  8b36                 mov esi, dword ptr [esi]
// 007a903e  57                   push edi
// 007a903f  e814100600           call 0x80a058
// 007a9044  83c404               add esp, 4
// 007a9047  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 007a904b  8bfe                 mov edi, esi
// 007a904d  74e2                 je 0x7a9031
// 007a904f  5f                   pop edi
// 007a9050  5e                   pop esi
// 007a9051  5b                   pop ebx
// 007a9052  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
