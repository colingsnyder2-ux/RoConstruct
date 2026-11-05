// from server: 100% by auto
// roc 2012-06 005a6440  unit: RBX::Network::NetworkOwnerJob  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a6440
//
// 005a6440  53                   push ebx
// 005a6441  56                   push esi
// 005a6442  57                   push edi
// 005a6443  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005a6447  807f2900             cmp byte ptr [edi + 0x29], 0
// 005a644b  8bd9                 mov ebx, ecx
// 005a644d  8bf7                 mov esi, edi
// 005a644f  751e                 jne 0x5a646f
// 005a6451  8b4608               mov eax, dword ptr [esi + 8]
// 005a6454  50                   push eax
// 005a6455  8bcb                 mov ecx, ebx
// 005a6457  e8e4ffffff           call 0x5a6440
// 005a645c  8b36                 mov esi, dword ptr [esi]
// 005a645e  57                   push edi
// 005a645f  e8b0bc3d00           call 0x982114
// 005a6464  83c404               add esp, 4
// 005a6467  807e2900             cmp byte ptr [esi + 0x29], 0
// 005a646b  8bfe                 mov edi, esi
// 005a646d  74e2                 je 0x5a6451
// 005a646f  5f                   pop edi
// 005a6470  5e                   pop esi
// 005a6471  5b                   pop ebx
// 005a6472  c20400               ret 4
// standard library set<pod28> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod28>
struct E { int v[7]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
