// from server: 100% by auto
// roc 2007-08 004451f0  unit: VCRenderSettings::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004451f0
//
// 004451f0  53                   push ebx
// 004451f1  56                   push esi
// 004451f2  57                   push edi
// 004451f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004451f7  807f1500             cmp byte ptr [edi + 0x15], 0
// 004451fb  8bd9                 mov ebx, ecx
// 004451fd  8bf7                 mov esi, edi
// 004451ff  751e                 jne 0x44521f
// 00445201  8b4608               mov eax, dword ptr [esi + 8]
// 00445204  50                   push eax
// 00445205  8bcb                 mov ecx, ebx
// 00445207  e8e4ffffff           call 0x4451f0
// 0044520c  8b36                 mov esi, dword ptr [esi]
// 0044520e  57                   push edi
// 0044520f  e84eaa1e00           call 0x62fc62
// 00445214  83c404               add esp, 4
// 00445217  807e1500             cmp byte ptr [esi + 0x15], 0
// 0044521b  8bfe                 mov edi, esi
// 0044521d  74e2                 je 0x445201
// 0044521f  5f                   pop edi
// 00445220  5e                   pop esi
// 00445221  5b                   pop ebx
// 00445222  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
