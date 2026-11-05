// from server: 100% by auto
// roc 2010-06 0061b1d0  unit: RBX::Accoutrement  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b1d0
//
// 0061b1d0  53                   push ebx
// 0061b1d1  56                   push esi
// 0061b1d2  57                   push edi
// 0061b1d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061b1d7  807f2100             cmp byte ptr [edi + 0x21], 0
// 0061b1db  8bd9                 mov ebx, ecx
// 0061b1dd  8bf7                 mov esi, edi
// 0061b1df  751e                 jne 0x61b1ff
// 0061b1e1  8b4608               mov eax, dword ptr [esi + 8]
// 0061b1e4  50                   push eax
// 0061b1e5  8bcb                 mov ecx, ebx
// 0061b1e7  e8e4ffffff           call 0x61b1d0
// 0061b1ec  8b36                 mov esi, dword ptr [esi]
// 0061b1ee  57                   push edi
// 0061b1ef  e8a6c71800           call 0x7a799a
// 0061b1f4  83c404               add esp, 4
// 0061b1f7  807e2100             cmp byte ptr [esi + 0x21], 0
// 0061b1fb  8bfe                 mov edi, esi
// 0061b1fd  74e2                 je 0x61b1e1
// 0061b1ff  5f                   pop edi
// 0061b200  5e                   pop esi
// 0061b201  5b                   pop ebx
// 0061b202  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
