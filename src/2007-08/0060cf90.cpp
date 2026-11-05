// from server: 100% by auto
// roc 2007-08 0060cf90  unit: RBX::Block  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060cf90
//
// 0060cf90  53                   push ebx
// 0060cf91  56                   push esi
// 0060cf92  57                   push edi
// 0060cf93  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060cf97  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0060cf9b  8bd9                 mov ebx, ecx
// 0060cf9d  8bf7                 mov esi, edi
// 0060cf9f  751e                 jne 0x60cfbf
// 0060cfa1  8b4608               mov eax, dword ptr [esi + 8]
// 0060cfa4  50                   push eax
// 0060cfa5  8bcb                 mov ecx, ebx
// 0060cfa7  e8e4ffffff           call 0x60cf90
// 0060cfac  8b36                 mov esi, dword ptr [esi]
// 0060cfae  57                   push edi
// 0060cfaf  e8ae2c0200           call 0x62fc62
// 0060cfb4  83c404               add esp, 4
// 0060cfb7  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 0060cfbb  8bfe                 mov edi, esi
// 0060cfbd  74e2                 je 0x60cfa1
// 0060cfbf  5f                   pop edi
// 0060cfc0  5e                   pop esi
// 0060cfc1  5b                   pop ebx
// 0060cfc2  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
