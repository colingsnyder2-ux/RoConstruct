// from server: 100% by auto
// roc 2009-12 0055b070  unit: RBX::Network::ServerReplicator  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055b070
//
// 0055b070  6a28                 push 0x28
// 0055b072  e8e9872900           call 0x7f3860
// 0055b077  83c404               add esp, 4
// 0055b07a  85c0                 test eax, eax
// 0055b07c  7406                 je 0x55b084
// 0055b07e  c70000000000         mov dword ptr [eax], 0
// 0055b084  8d4804               lea ecx, [eax + 4]
// 0055b087  85c9                 test ecx, ecx
// 0055b089  7406                 je 0x55b091
// 0055b08b  c70100000000         mov dword ptr [ecx], 0
// 0055b091  8d4808               lea ecx, [eax + 8]
// 0055b094  85c9                 test ecx, ecx
// 0055b096  7406                 je 0x55b09e
// 0055b098  c70100000000         mov dword ptr [ecx], 0
// 0055b09e  c6402401             mov byte ptr [eax + 0x24], 1
// 0055b0a2  c6402500             mov byte ptr [eax + 0x25], 0
// 0055b0a6  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
