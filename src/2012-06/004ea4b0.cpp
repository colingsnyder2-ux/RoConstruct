// from server: 100% by auto
// roc 2012-06 004ea4b0  unit: RBX::RbxTextureProxy  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ea4b0
//
// 004ea4b0  53                   push ebx
// 004ea4b1  56                   push esi
// 004ea4b2  57                   push edi
// 004ea4b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ea4b7  807f2100             cmp byte ptr [edi + 0x21], 0
// 004ea4bb  8bd9                 mov ebx, ecx
// 004ea4bd  8bf7                 mov esi, edi
// 004ea4bf  751e                 jne 0x4ea4df
// 004ea4c1  8b4608               mov eax, dword ptr [esi + 8]
// 004ea4c4  50                   push eax
// 004ea4c5  8bcb                 mov ecx, ebx
// 004ea4c7  e8e4ffffff           call 0x4ea4b0
// 004ea4cc  8b36                 mov esi, dword ptr [esi]
// 004ea4ce  57                   push edi
// 004ea4cf  e8407c4900           call 0x982114
// 004ea4d4  83c404               add esp, 4
// 004ea4d7  807e2100             cmp byte ptr [esi + 0x21], 0
// 004ea4db  8bfe                 mov edi, esi
// 004ea4dd  74e2                 je 0x4ea4c1
// 004ea4df  5f                   pop edi
// 004ea4e0  5e                   pop esi
// 004ea4e1  5b                   pop ebx
// 004ea4e2  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
