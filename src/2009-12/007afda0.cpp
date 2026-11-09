// from server: 100% by auto
// roc 2009-12 007afda0  unit: RBX::Block  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007afda0
//
// 007afda0  53                   push ebx
// 007afda1  56                   push esi
// 007afda2  57                   push edi
// 007afda3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007afda7  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 007afdab  8bd9                 mov ebx, ecx
// 007afdad  8bf7                 mov esi, edi
// 007afdaf  751e                 jne 0x7afdcf
// 007afdb1  8b4608               mov eax, dword ptr [esi + 8]
// 007afdb4  50                   push eax
// 007afdb5  8bcb                 mov ecx, ebx
// 007afdb7  e8e4ffffff           call 0x7afda0
// 007afdbc  8b36                 mov esi, dword ptr [esi]
// 007afdbe  57                   push edi
// 007afdbf  e8963a0400           call 0x7f385a
// 007afdc4  83c404               add esp, 4
// 007afdc7  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 007afdcb  8bfe                 mov edi, esi
// 007afdcd  74e2                 je 0x7afdb1
// 007afdcf  5f                   pop edi
// 007afdd0  5e                   pop esi
// 007afdd1  5b                   pop ebx
// 007afdd2  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
