// from server: 100% by auto
// roc 2011-06 00421810  unit: RBX::FunctionMarshaller  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00421810
//
// 00421810  53                   push ebx
// 00421811  56                   push esi
// 00421812  57                   push edi
// 00421813  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00421817  807f1500             cmp byte ptr [edi + 0x15], 0
// 0042181b  8bd9                 mov ebx, ecx
// 0042181d  8bf7                 mov esi, edi
// 0042181f  751e                 jne 0x42183f
// 00421821  8b4608               mov eax, dword ptr [esi + 8]
// 00421824  50                   push eax
// 00421825  8bcb                 mov ecx, ebx
// 00421827  e8e4ffffff           call 0x421810
// 0042182c  8b36                 mov esi, dword ptr [esi]
// 0042182e  57                   push edi
// 0042182f  e824883e00           call 0x80a058
// 00421834  83c404               add esp, 4
// 00421837  807e1500             cmp byte ptr [esi + 0x15], 0
// 0042183b  8bfe                 mov edi, esi
// 0042183d  74e2                 je 0x421821
// 0042183f  5f                   pop edi
// 00421840  5e                   pop esi
// 00421841  5b                   pop ebx
// 00421842  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
