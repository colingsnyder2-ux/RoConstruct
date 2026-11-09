// from server: 100% by auto
// roc 2011-06 007a8790  unit: RBX::PyramidPoly  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a8790
//
// 007a8790  53                   push ebx
// 007a8791  56                   push esi
// 007a8792  57                   push edi
// 007a8793  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007a8797  807f2500             cmp byte ptr [edi + 0x25], 0
// 007a879b  8bd9                 mov ebx, ecx
// 007a879d  8bf7                 mov esi, edi
// 007a879f  751e                 jne 0x7a87bf
// 007a87a1  8b4608               mov eax, dword ptr [esi + 8]
// 007a87a4  50                   push eax
// 007a87a5  8bcb                 mov ecx, ebx
// 007a87a7  e8e4ffffff           call 0x7a8790
// 007a87ac  8b36                 mov esi, dword ptr [esi]
// 007a87ae  57                   push edi
// 007a87af  e8a4180600           call 0x80a058
// 007a87b4  83c404               add esp, 4
// 007a87b7  807e2500             cmp byte ptr [esi + 0x25], 0
// 007a87bb  8bfe                 mov edi, esi
// 007a87bd  74e2                 je 0x7a87a1
// 007a87bf  5f                   pop edi
// 007a87c0  5e                   pop esi
// 007a87c1  5b                   pop ebx
// 007a87c2  c20400               ret 4
// standard library set<pod24> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
