// from server: 100% by auto
// roc 2009-06 005fc030  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fc030
//
// 005fc030  6a1c                 push 0x1c
// 005fc032  e801ca1100           call 0x718a38
// 005fc037  83c404               add esp, 4
// 005fc03a  85c0                 test eax, eax
// 005fc03c  7406                 je 0x5fc044
// 005fc03e  c70000000000         mov dword ptr [eax], 0
// 005fc044  8d4804               lea ecx, [eax + 4]
// 005fc047  85c9                 test ecx, ecx
// 005fc049  7406                 je 0x5fc051
// 005fc04b  c70100000000         mov dword ptr [ecx], 0
// 005fc051  8d4808               lea ecx, [eax + 8]
// 005fc054  85c9                 test ecx, ecx
// 005fc056  7406                 je 0x5fc05e
// 005fc058  c70100000000         mov dword ptr [ecx], 0
// 005fc05e  c6401801             mov byte ptr [eax + 0x18], 1
// 005fc062  c6401900             mov byte ptr [eax + 0x19], 0
// 005fc066  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
