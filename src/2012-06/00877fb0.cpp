// from server: 100% by auto
// roc 2012-06 00877fb0  unit: DummyJob  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00877fb0
//
// 00877fb0  53                   push ebx
// 00877fb1  56                   push esi
// 00877fb2  57                   push edi
// 00877fb3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00877fb7  807f0e00             cmp byte ptr [edi + 0xe], 0
// 00877fbb  8bd9                 mov ebx, ecx
// 00877fbd  8bf7                 mov esi, edi
// 00877fbf  751e                 jne 0x877fdf
// 00877fc1  8b4608               mov eax, dword ptr [esi + 8]
// 00877fc4  50                   push eax
// 00877fc5  8bcb                 mov ecx, ebx
// 00877fc7  e8e4ffffff           call 0x877fb0
// 00877fcc  8b36                 mov esi, dword ptr [esi]
// 00877fce  57                   push edi
// 00877fcf  e840a11000           call 0x982114
// 00877fd4  83c404               add esp, 4
// 00877fd7  807e0e00             cmp byte ptr [esi + 0xe], 0
// 00877fdb  8bfe                 mov edi, esi
// 00877fdd  74e2                 je 0x877fc1
// 00877fdf  5f                   pop edi
// 00877fe0  5e                   pop esi
// 00877fe1  5b                   pop ebx
// 00877fe2  c20400               ret 4
// standard library set<char> (function ?_Erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
