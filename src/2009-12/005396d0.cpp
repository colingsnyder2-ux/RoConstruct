// from server: 100% by auto
// roc 2009-12 005396d0  unit: G3D::VRay::?$holder  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005396d0
//
// 005396d0  53                   push ebx
// 005396d1  56                   push esi
// 005396d2  57                   push edi
// 005396d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005396d7  807f1900             cmp byte ptr [edi + 0x19], 0
// 005396db  8bd9                 mov ebx, ecx
// 005396dd  8bf7                 mov esi, edi
// 005396df  751e                 jne 0x5396ff
// 005396e1  8b4608               mov eax, dword ptr [esi + 8]
// 005396e4  50                   push eax
// 005396e5  8bcb                 mov ecx, ebx
// 005396e7  e8e4ffffff           call 0x5396d0
// 005396ec  8b36                 mov esi, dword ptr [esi]
// 005396ee  57                   push edi
// 005396ef  e866a12b00           call 0x7f385a
// 005396f4  83c404               add esp, 4
// 005396f7  807e1900             cmp byte ptr [esi + 0x19], 0
// 005396fb  8bfe                 mov edi, esi
// 005396fd  74e2                 je 0x5396e1
// 005396ff  5f                   pop edi
// 00539700  5e                   pop esi
// 00539701  5b                   pop ebx
// 00539702  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
