// from server: 100% by auto
// roc 2010-06 004dc9f0  unit: RBX::Network::GuidRegistryService  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004dc9f0
//
// 004dc9f0  53                   push ebx
// 004dc9f1  56                   push esi
// 004dc9f2  57                   push edi
// 004dc9f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004dc9f7  807f1900             cmp byte ptr [edi + 0x19], 0
// 004dc9fb  8bd9                 mov ebx, ecx
// 004dc9fd  8bf7                 mov esi, edi
// 004dc9ff  751e                 jne 0x4dca1f
// 004dca01  8b4608               mov eax, dword ptr [esi + 8]
// 004dca04  50                   push eax
// 004dca05  8bcb                 mov ecx, ebx
// 004dca07  e8e4ffffff           call 0x4dc9f0
// 004dca0c  8b36                 mov esi, dword ptr [esi]
// 004dca0e  57                   push edi
// 004dca0f  e886af2c00           call 0x7a799a
// 004dca14  83c404               add esp, 4
// 004dca17  807e1900             cmp byte ptr [esi + 0x19], 0
// 004dca1b  8bfe                 mov edi, esi
// 004dca1d  74e2                 je 0x4dca01
// 004dca1f  5f                   pop edi
// 004dca20  5e                   pop esi
// 004dca21  5b                   pop ebx
// 004dca22  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
