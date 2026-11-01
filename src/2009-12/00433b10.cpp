// from server: 100% by auto
// roc 2009-12 00433b10  unit: CPropGrid::UpdateItemsJob  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433b10
//
// 00433b10  53                   push ebx
// 00433b11  56                   push esi
// 00433b12  57                   push edi
// 00433b13  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00433b17  807f1500             cmp byte ptr [edi + 0x15], 0
// 00433b1b  8bd9                 mov ebx, ecx
// 00433b1d  8bf7                 mov esi, edi
// 00433b1f  751e                 jne 0x433b3f
// 00433b21  8b4608               mov eax, dword ptr [esi + 8]
// 00433b24  50                   push eax
// 00433b25  8bcb                 mov ecx, ebx
// 00433b27  e8e4ffffff           call 0x433b10
// 00433b2c  8b36                 mov esi, dword ptr [esi]
// 00433b2e  57                   push edi
// 00433b2f  e826fd3b00           call 0x7f385a
// 00433b34  83c404               add esp, 4
// 00433b37  807e1500             cmp byte ptr [esi + 0x15], 0
// 00433b3b  8bfe                 mov edi, esi
// 00433b3d  74e2                 je 0x433b21
// 00433b3f  5f                   pop edi
// 00433b40  5e                   pop esi
// 00433b41  5b                   pop ebx
// 00433b42  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
