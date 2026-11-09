// from server: 100% by auto
// roc 2010-06 00434ec0  unit: CPropGrid::UpdateItemsJob  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00434ec0
//
// 00434ec0  53                   push ebx
// 00434ec1  56                   push esi
// 00434ec2  57                   push edi
// 00434ec3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00434ec7  807f1100             cmp byte ptr [edi + 0x11], 0
// 00434ecb  8bd9                 mov ebx, ecx
// 00434ecd  8bf7                 mov esi, edi
// 00434ecf  751e                 jne 0x434eef
// 00434ed1  8b4608               mov eax, dword ptr [esi + 8]
// 00434ed4  50                   push eax
// 00434ed5  8bcb                 mov ecx, ebx
// 00434ed7  e8e4ffffff           call 0x434ec0
// 00434edc  8b36                 mov esi, dword ptr [esi]
// 00434ede  57                   push edi
// 00434edf  e8b62a3700           call 0x7a799a
// 00434ee4  83c404               add esp, 4
// 00434ee7  807e1100             cmp byte ptr [esi + 0x11], 0
// 00434eeb  8bfe                 mov edi, esi
// 00434eed  74e2                 je 0x434ed1
// 00434eef  5f                   pop edi
// 00434ef0  5e                   pop esi
// 00434ef1  5b                   pop ebx
// 00434ef2  c20400               ret 4
// standard library set<ptr> (function ?_Erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
