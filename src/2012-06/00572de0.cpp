// from server: 100% by auto
// roc 2012-06 00572de0  unit: AsyncResult  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00572de0
//
// 00572de0  53                   push ebx
// 00572de1  56                   push esi
// 00572de2  57                   push edi
// 00572de3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00572de7  807f1900             cmp byte ptr [edi + 0x19], 0
// 00572deb  8bd9                 mov ebx, ecx
// 00572ded  8bf7                 mov esi, edi
// 00572def  751e                 jne 0x572e0f
// 00572df1  8b4608               mov eax, dword ptr [esi + 8]
// 00572df4  50                   push eax
// 00572df5  8bcb                 mov ecx, ebx
// 00572df7  e8e4ffffff           call 0x572de0
// 00572dfc  8b36                 mov esi, dword ptr [esi]
// 00572dfe  57                   push edi
// 00572dff  e810f34000           call 0x982114
// 00572e04  83c404               add esp, 4
// 00572e07  807e1900             cmp byte ptr [esi + 0x19], 0
// 00572e0b  8bfe                 mov edi, esi
// 00572e0d  74e2                 je 0x572df1
// 00572e0f  5f                   pop edi
// 00572e10  5e                   pop esi
// 00572e11  5b                   pop ebx
// 00572e12  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
