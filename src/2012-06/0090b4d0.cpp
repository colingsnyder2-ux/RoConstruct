// from server: 100% by auto
// roc 2012-06 0090b4d0  unit: RBX::PrismPoly  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0090b4d0
//
// 0090b4d0  53                   push ebx
// 0090b4d1  56                   push esi
// 0090b4d2  57                   push edi
// 0090b4d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0090b4d7  807f2500             cmp byte ptr [edi + 0x25], 0
// 0090b4db  8bd9                 mov ebx, ecx
// 0090b4dd  8bf7                 mov esi, edi
// 0090b4df  751e                 jne 0x90b4ff
// 0090b4e1  8b4608               mov eax, dword ptr [esi + 8]
// 0090b4e4  50                   push eax
// 0090b4e5  8bcb                 mov ecx, ebx
// 0090b4e7  e8e4ffffff           call 0x90b4d0
// 0090b4ec  8b36                 mov esi, dword ptr [esi]
// 0090b4ee  57                   push edi
// 0090b4ef  e8206c0700           call 0x982114
// 0090b4f4  83c404               add esp, 4
// 0090b4f7  807e2500             cmp byte ptr [esi + 0x25], 0
// 0090b4fb  8bfe                 mov edi, esi
// 0090b4fd  74e2                 je 0x90b4e1
// 0090b4ff  5f                   pop edi
// 0090b500  5e                   pop esi
// 0090b501  5b                   pop ebx
// 0090b502  c20400               ret 4
// standard library set<pod24> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
