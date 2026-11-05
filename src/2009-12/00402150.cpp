// from server: 100% by auto
// roc 2009-12 00402150  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402150
//
// 00402150  53                   push ebx
// 00402151  56                   push esi
// 00402152  57                   push edi
// 00402153  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00402157  807f1100             cmp byte ptr [edi + 0x11], 0
// 0040215b  8bd9                 mov ebx, ecx
// 0040215d  8bf7                 mov esi, edi
// 0040215f  751e                 jne 0x40217f
// 00402161  8b4608               mov eax, dword ptr [esi + 8]
// 00402164  50                   push eax
// 00402165  8bcb                 mov ecx, ebx
// 00402167  e8e4ffffff           call 0x402150
// 0040216c  8b36                 mov esi, dword ptr [esi]
// 0040216e  57                   push edi
// 0040216f  e8e6163f00           call 0x7f385a
// 00402174  83c404               add esp, 4
// 00402177  807e1100             cmp byte ptr [esi + 0x11], 0
// 0040217b  8bfe                 mov edi, esi
// 0040217d  74e2                 je 0x402161
// 0040217f  5f                   pop edi
// 00402180  5e                   pop esi
// 00402181  5b                   pop ebx
// 00402182  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
