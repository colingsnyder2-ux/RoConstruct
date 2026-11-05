// from server: 100% by auto
// roc 2012-06 004c3d70  unit: RBX::AdornRbxGfx  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c3d70
//
// 004c3d70  53                   push ebx
// 004c3d71  56                   push esi
// 004c3d72  57                   push edi
// 004c3d73  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c3d77  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 004c3d7b  8bd9                 mov ebx, ecx
// 004c3d7d  8bf7                 mov esi, edi
// 004c3d7f  751e                 jne 0x4c3d9f
// 004c3d81  8b4608               mov eax, dword ptr [esi + 8]
// 004c3d84  50                   push eax
// 004c3d85  8bcb                 mov ecx, ebx
// 004c3d87  e8e4ffffff           call 0x4c3d70
// 004c3d8c  8b36                 mov esi, dword ptr [esi]
// 004c3d8e  57                   push edi
// 004c3d8f  e880e34b00           call 0x982114
// 004c3d94  83c404               add esp, 4
// 004c3d97  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 004c3d9b  8bfe                 mov edi, esi
// 004c3d9d  74e2                 je 0x4c3d81
// 004c3d9f  5f                   pop edi
// 004c3da0  5e                   pop esi
// 004c3da1  5b                   pop ebx
// 004c3da2  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
