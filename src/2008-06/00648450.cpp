// from server: 100% by auto
// roc 2008-06 00648450  unit: RBX::Block  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648450
//
// 00648450  53                   push ebx
// 00648451  56                   push esi
// 00648452  57                   push edi
// 00648453  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00648457  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0064845b  8bd9                 mov ebx, ecx
// 0064845d  8bf7                 mov esi, edi
// 0064845f  751e                 jne 0x64847f
// 00648461  8b4608               mov eax, dword ptr [esi + 8]
// 00648464  50                   push eax
// 00648465  8bcb                 mov ecx, ebx
// 00648467  e8e4ffffff           call 0x648450
// 0064846c  8b36                 mov esi, dword ptr [esi]
// 0064846e  57                   push edi
// 0064846f  e806820500           call 0x6a067a
// 00648474  83c404               add esp, 4
// 00648477  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 0064847b  8bfe                 mov edi, esi
// 0064847d  74e2                 je 0x648461
// 0064847f  5f                   pop edi
// 00648480  5e                   pop esi
// 00648481  5b                   pop ebx
// 00648482  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
