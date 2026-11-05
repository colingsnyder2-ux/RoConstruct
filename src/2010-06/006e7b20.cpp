// from server: 100% by auto
// roc 2010-06 006e7b20  unit: RBX::P8PVInstance::?$SetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e7b20
//
// 006e7b20  6a34                 push 0x34
// 006e7b22  e879fe0b00           call 0x7a79a0
// 006e7b27  83c404               add esp, 4
// 006e7b2a  85c0                 test eax, eax
// 006e7b2c  7406                 je 0x6e7b34
// 006e7b2e  c70000000000         mov dword ptr [eax], 0
// 006e7b34  8d4804               lea ecx, [eax + 4]
// 006e7b37  85c9                 test ecx, ecx
// 006e7b39  7406                 je 0x6e7b41
// 006e7b3b  c70100000000         mov dword ptr [ecx], 0
// 006e7b41  8d4808               lea ecx, [eax + 8]
// 006e7b44  85c9                 test ecx, ecx
// 006e7b46  7406                 je 0x6e7b4e
// 006e7b48  c70100000000         mov dword ptr [ecx], 0
// 006e7b4e  c6403001             mov byte ptr [eax + 0x30], 1
// 006e7b52  c6403100             mov byte ptr [eax + 0x31], 0
// 006e7b56  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
