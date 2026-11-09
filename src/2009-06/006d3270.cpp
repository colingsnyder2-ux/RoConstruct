// from server: 100% by auto
// roc 2009-06 006d3270  unit: RBX::Block  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d3270
//
// 006d3270  53                   push ebx
// 006d3271  56                   push esi
// 006d3272  57                   push edi
// 006d3273  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006d3277  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 006d327b  8bd9                 mov ebx, ecx
// 006d327d  8bf7                 mov esi, edi
// 006d327f  751e                 jne 0x6d329f
// 006d3281  8b4608               mov eax, dword ptr [esi + 8]
// 006d3284  50                   push eax
// 006d3285  8bcb                 mov ecx, ebx
// 006d3287  e8e4ffffff           call 0x6d3270
// 006d328c  8b36                 mov esi, dword ptr [esi]
// 006d328e  57                   push edi
// 006d328f  e89e570400           call 0x718a32
// 006d3294  83c404               add esp, 4
// 006d3297  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 006d329b  8bfe                 mov edi, esi
// 006d329d  74e2                 je 0x6d3281
// 006d329f  5f                   pop edi
// 006d32a0  5e                   pop esi
// 006d32a1  5b                   pop ebx
// 006d32a2  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
