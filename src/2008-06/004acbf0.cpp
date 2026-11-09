// from server: 100% by auto
// roc 2008-06 004acbf0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004acbf0
//
// 004acbf0  6a40                 push 0x40
// 004acbf2  e8293d1f00           call 0x6a0920
// 004acbf7  83c404               add esp, 4
// 004acbfa  85c0                 test eax, eax
// 004acbfc  7406                 je 0x4acc04
// 004acbfe  c70000000000         mov dword ptr [eax], 0
// 004acc04  8d4804               lea ecx, [eax + 4]
// 004acc07  85c9                 test ecx, ecx
// 004acc09  7406                 je 0x4acc11
// 004acc0b  c70100000000         mov dword ptr [ecx], 0
// 004acc11  8d4808               lea ecx, [eax + 8]
// 004acc14  85c9                 test ecx, ecx
// 004acc16  7406                 je 0x4acc1e
// 004acc18  c70100000000         mov dword ptr [ecx], 0
// 004acc1e  c6403c01             mov byte ptr [eax + 0x3c], 1
// 004acc22  c6403d00             mov byte ptr [eax + 0x3d], 0
// 004acc26  c3                   ret 
// standard library set<pod48> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
