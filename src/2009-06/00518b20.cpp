// from server: 100% by auto
// roc 2009-06 00518b20  unit: RBX::PartChunk  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00518b20
//
// 00518b20  6a24                 push 0x24
// 00518b22  e811ff1f00           call 0x718a38
// 00518b27  83c404               add esp, 4
// 00518b2a  85c0                 test eax, eax
// 00518b2c  7406                 je 0x518b34
// 00518b2e  c70000000000         mov dword ptr [eax], 0
// 00518b34  8d4804               lea ecx, [eax + 4]
// 00518b37  85c9                 test ecx, ecx
// 00518b39  7406                 je 0x518b41
// 00518b3b  c70100000000         mov dword ptr [ecx], 0
// 00518b41  8d4808               lea ecx, [eax + 8]
// 00518b44  85c9                 test ecx, ecx
// 00518b46  7406                 je 0x518b4e
// 00518b48  c70100000000         mov dword ptr [ecx], 0
// 00518b4e  c6402001             mov byte ptr [eax + 0x20], 1
// 00518b52  c6402100             mov byte ptr [eax + 0x21], 0
// 00518b56  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
