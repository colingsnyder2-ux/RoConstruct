// from server: 100% by auto
// roc 2008-06 006483c0  unit: RBX::Block  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006483c0
//
// 006483c0  6a20                 push 0x20
// 006483c2  e859850500           call 0x6a0920
// 006483c7  83c404               add esp, 4
// 006483ca  85c0                 test eax, eax
// 006483cc  7406                 je 0x6483d4
// 006483ce  c70000000000         mov dword ptr [eax], 0
// 006483d4  8d4804               lea ecx, [eax + 4]
// 006483d7  85c9                 test ecx, ecx
// 006483d9  7406                 je 0x6483e1
// 006483db  c70100000000         mov dword ptr [ecx], 0
// 006483e1  8d4808               lea ecx, [eax + 8]
// 006483e4  85c9                 test ecx, ecx
// 006483e6  7406                 je 0x6483ee
// 006483e8  c70100000000         mov dword ptr [ecx], 0
// 006483ee  c6401c01             mov byte ptr [eax + 0x1c], 1
// 006483f2  c6401d00             mov byte ptr [eax + 0x1d], 0
// 006483f6  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
