// from server: 100% by auto
// roc 2008-06 004970e0  unit: RBX::Network::Players  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004970e0
//
// 004970e0  53                   push ebx
// 004970e1  56                   push esi
// 004970e2  57                   push edi
// 004970e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004970e7  807f1900             cmp byte ptr [edi + 0x19], 0
// 004970eb  8bd9                 mov ebx, ecx
// 004970ed  8bf7                 mov esi, edi
// 004970ef  751e                 jne 0x49710f
// 004970f1  8b4608               mov eax, dword ptr [esi + 8]
// 004970f4  50                   push eax
// 004970f5  8bcb                 mov ecx, ebx
// 004970f7  e8e4ffffff           call 0x4970e0
// 004970fc  8b36                 mov esi, dword ptr [esi]
// 004970fe  57                   push edi
// 004970ff  e876952000           call 0x6a067a
// 00497104  83c404               add esp, 4
// 00497107  807e1900             cmp byte ptr [esi + 0x19], 0
// 0049710b  8bfe                 mov edi, esi
// 0049710d  74e2                 je 0x4970f1
// 0049710f  5f                   pop edi
// 00497110  5e                   pop esi
// 00497111  5b                   pop ebx
// 00497112  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
