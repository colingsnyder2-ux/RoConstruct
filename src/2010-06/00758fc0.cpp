// from server: 100% by auto
// roc 2010-06 00758fc0  unit: RBX::PyramidPoly  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00758fc0
//
// 00758fc0  53                   push ebx
// 00758fc1  56                   push esi
// 00758fc2  57                   push edi
// 00758fc3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00758fc7  807f2500             cmp byte ptr [edi + 0x25], 0
// 00758fcb  8bd9                 mov ebx, ecx
// 00758fcd  8bf7                 mov esi, edi
// 00758fcf  751e                 jne 0x758fef
// 00758fd1  8b4608               mov eax, dword ptr [esi + 8]
// 00758fd4  50                   push eax
// 00758fd5  8bcb                 mov ecx, ebx
// 00758fd7  e8e4ffffff           call 0x758fc0
// 00758fdc  8b36                 mov esi, dword ptr [esi]
// 00758fde  57                   push edi
// 00758fdf  e8b6e90400           call 0x7a799a
// 00758fe4  83c404               add esp, 4
// 00758fe7  807e2500             cmp byte ptr [esi + 0x25], 0
// 00758feb  8bfe                 mov edi, esi
// 00758fed  74e2                 je 0x758fd1
// 00758fef  5f                   pop edi
// 00758ff0  5e                   pop esi
// 00758ff1  5b                   pop ebx
// 00758ff2  c20400               ret 4
// standard library set<pod24> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
