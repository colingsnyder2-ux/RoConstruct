// from server: 100% by auto
// roc 2009-12 006ad260  unit: RBX::Accoutrement  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad260
//
// 006ad260  6a30                 push 0x30
// 006ad262  e8f9651400           call 0x7f3860
// 006ad267  83c404               add esp, 4
// 006ad26a  85c0                 test eax, eax
// 006ad26c  7406                 je 0x6ad274
// 006ad26e  c70000000000         mov dword ptr [eax], 0
// 006ad274  8d4804               lea ecx, [eax + 4]
// 006ad277  85c9                 test ecx, ecx
// 006ad279  7406                 je 0x6ad281
// 006ad27b  c70100000000         mov dword ptr [ecx], 0
// 006ad281  8d4808               lea ecx, [eax + 8]
// 006ad284  85c9                 test ecx, ecx
// 006ad286  7406                 je 0x6ad28e
// 006ad288  c70100000000         mov dword ptr [ecx], 0
// 006ad28e  c6402c01             mov byte ptr [eax + 0x2c], 1
// 006ad292  c6402d00             mov byte ptr [eax + 0x2d], 0
// 006ad296  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
