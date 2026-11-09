// from server: 100% by auto
// roc 2009-06 0063ebd0  unit: RBX::Accoutrement  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ebd0
//
// 0063ebd0  53                   push ebx
// 0063ebd1  56                   push esi
// 0063ebd2  57                   push edi
// 0063ebd3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063ebd7  807f2100             cmp byte ptr [edi + 0x21], 0
// 0063ebdb  8bd9                 mov ebx, ecx
// 0063ebdd  8bf7                 mov esi, edi
// 0063ebdf  751e                 jne 0x63ebff
// 0063ebe1  8b4608               mov eax, dword ptr [esi + 8]
// 0063ebe4  50                   push eax
// 0063ebe5  8bcb                 mov ecx, ebx
// 0063ebe7  e8e4ffffff           call 0x63ebd0
// 0063ebec  8b36                 mov esi, dword ptr [esi]
// 0063ebee  57                   push edi
// 0063ebef  e83e9e0d00           call 0x718a32
// 0063ebf4  83c404               add esp, 4
// 0063ebf7  807e2100             cmp byte ptr [esi + 0x21], 0
// 0063ebfb  8bfe                 mov edi, esi
// 0063ebfd  74e2                 je 0x63ebe1
// 0063ebff  5f                   pop edi
// 0063ec00  5e                   pop esi
// 0063ec01  5b                   pop ebx
// 0063ec02  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
