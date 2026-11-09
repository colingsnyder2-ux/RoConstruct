// from server: 100% by auto
// roc 2007-08 005dedb0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dedb0
//
// 005dedb0  53                   push ebx
// 005dedb1  56                   push esi
// 005dedb2  57                   push edi
// 005dedb3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005dedb7  807f1900             cmp byte ptr [edi + 0x19], 0
// 005dedbb  8bd9                 mov ebx, ecx
// 005dedbd  8bf7                 mov esi, edi
// 005dedbf  751e                 jne 0x5deddf
// 005dedc1  8b4608               mov eax, dword ptr [esi + 8]
// 005dedc4  50                   push eax
// 005dedc5  8bcb                 mov ecx, ebx
// 005dedc7  e8e4ffffff           call 0x5dedb0
// 005dedcc  8b36                 mov esi, dword ptr [esi]
// 005dedce  57                   push edi
// 005dedcf  e88e0e0500           call 0x62fc62
// 005dedd4  83c404               add esp, 4
// 005dedd7  807e1900             cmp byte ptr [esi + 0x19], 0
// 005deddb  8bfe                 mov edi, esi
// 005deddd  74e2                 je 0x5dedc1
// 005deddf  5f                   pop edi
// 005dede0  5e                   pop esi
// 005dede1  5b                   pop ebx
// 005dede2  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
