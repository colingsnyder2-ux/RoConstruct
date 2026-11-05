// from server: 100% by auto
// roc 2010-06 00468690  unit: CRobloxWnd::PartDropTarget  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00468690
//
// 00468690  53                   push ebx
// 00468691  56                   push esi
// 00468692  57                   push edi
// 00468693  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00468697  807f1500             cmp byte ptr [edi + 0x15], 0
// 0046869b  8bd9                 mov ebx, ecx
// 0046869d  8bf7                 mov esi, edi
// 0046869f  751e                 jne 0x4686bf
// 004686a1  8b4608               mov eax, dword ptr [esi + 8]
// 004686a4  50                   push eax
// 004686a5  8bcb                 mov ecx, ebx
// 004686a7  e8e4ffffff           call 0x468690
// 004686ac  8b36                 mov esi, dword ptr [esi]
// 004686ae  57                   push edi
// 004686af  e8e6f23300           call 0x7a799a
// 004686b4  83c404               add esp, 4
// 004686b7  807e1500             cmp byte ptr [esi + 0x15], 0
// 004686bb  8bfe                 mov edi, esi
// 004686bd  74e2                 je 0x4686a1
// 004686bf  5f                   pop edi
// 004686c0  5e                   pop esi
// 004686c1  5b                   pop ebx
// 004686c2  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
