// from server: 100% by auto
// roc 2009-12 006ad2a0  unit: RBX::Accoutrement  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad2a0
//
// 006ad2a0  53                   push ebx
// 006ad2a1  56                   push esi
// 006ad2a2  57                   push edi
// 006ad2a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ad2a7  807f2100             cmp byte ptr [edi + 0x21], 0
// 006ad2ab  8bd9                 mov ebx, ecx
// 006ad2ad  8bf7                 mov esi, edi
// 006ad2af  751e                 jne 0x6ad2cf
// 006ad2b1  8b4608               mov eax, dword ptr [esi + 8]
// 006ad2b4  50                   push eax
// 006ad2b5  8bcb                 mov ecx, ebx
// 006ad2b7  e8e4ffffff           call 0x6ad2a0
// 006ad2bc  8b36                 mov esi, dword ptr [esi]
// 006ad2be  57                   push edi
// 006ad2bf  e896651400           call 0x7f385a
// 006ad2c4  83c404               add esp, 4
// 006ad2c7  807e2100             cmp byte ptr [esi + 0x21], 0
// 006ad2cb  8bfe                 mov edi, esi
// 006ad2cd  74e2                 je 0x6ad2b1
// 006ad2cf  5f                   pop edi
// 006ad2d0  5e                   pop esi
// 006ad2d1  5b                   pop ebx
// 006ad2d2  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
