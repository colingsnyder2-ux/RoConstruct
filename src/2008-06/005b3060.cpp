// from server: 100% by auto
// roc 2008-06 005b3060  unit: RBX::VHat::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3060
//
// 005b3060  53                   push ebx
// 005b3061  56                   push esi
// 005b3062  57                   push edi
// 005b3063  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b3067  807f2100             cmp byte ptr [edi + 0x21], 0
// 005b306b  8bd9                 mov ebx, ecx
// 005b306d  8bf7                 mov esi, edi
// 005b306f  751e                 jne 0x5b308f
// 005b3071  8b4608               mov eax, dword ptr [esi + 8]
// 005b3074  50                   push eax
// 005b3075  8bcb                 mov ecx, ebx
// 005b3077  e8e4ffffff           call 0x5b3060
// 005b307c  8b36                 mov esi, dword ptr [esi]
// 005b307e  57                   push edi
// 005b307f  e8f6d50e00           call 0x6a067a
// 005b3084  83c404               add esp, 4
// 005b3087  807e2100             cmp byte ptr [esi + 0x21], 0
// 005b308b  8bfe                 mov edi, esi
// 005b308d  74e2                 je 0x5b3071
// 005b308f  5f                   pop edi
// 005b3090  5e                   pop esi
// 005b3091  5b                   pop ebx
// 005b3092  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
