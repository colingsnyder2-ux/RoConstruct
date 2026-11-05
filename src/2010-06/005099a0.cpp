// from server: 100% by auto
// roc 2010-06 005099a0  unit: RBX::Network::ServerReplicator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005099a0
//
// 005099a0  53                   push ebx
// 005099a1  56                   push esi
// 005099a2  57                   push edi
// 005099a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005099a7  807f2900             cmp byte ptr [edi + 0x29], 0
// 005099ab  8bd9                 mov ebx, ecx
// 005099ad  8bf7                 mov esi, edi
// 005099af  751e                 jne 0x5099cf
// 005099b1  8b4608               mov eax, dword ptr [esi + 8]
// 005099b4  50                   push eax
// 005099b5  8bcb                 mov ecx, ebx
// 005099b7  e8e4ffffff           call 0x5099a0
// 005099bc  8b36                 mov esi, dword ptr [esi]
// 005099be  57                   push edi
// 005099bf  e8d6df2900           call 0x7a799a
// 005099c4  83c404               add esp, 4
// 005099c7  807e2900             cmp byte ptr [esi + 0x29], 0
// 005099cb  8bfe                 mov edi, esi
// 005099cd  74e2                 je 0x5099b1
// 005099cf  5f                   pop edi
// 005099d0  5e                   pop esi
// 005099d1  5b                   pop ebx
// 005099d2  c20400               ret 4
// standard library set<pod28> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod28>
struct E { int v[7]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
